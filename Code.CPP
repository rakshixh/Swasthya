#include <DallasTemperature.h>
#include <OneWire.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "ThingSpeak.h"

#define pulsePin A0
#define ONE_WIRE_BUS D2                          //D2 pin of nodemcu
#define WIFI_SSID "Akshatha"
#define WIFI_PASSWORD "akshatha.r"
unsigned long myChannelNumber = 1269905;
const char * myWriteAPIKey = "RGRE8F0ODASXLTAG";
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

Ticker flipper;

OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire);            // Pass the oneWire reference to Dallas Temperature.
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.
volatile int rate[10];                        // array to hold last ten IBI values
volatile unsigned long sampleCounter = 0;     // used to determine pulse timing
volatile unsigned long lastBeatTime = 0;      // used to find IBI
volatile unsigned long current;
volatile int P = 512;                         // used to find peak in pulse wave, seeded
volatile int T = 512;                         // used to find trough in pulse wave, seeded
volatile int thresh = 560;                    // used to find instant moment of heart beat, seeded 530du
volatile int amp = 0;                         // used to hold amplitude of pulse waveform, seeded
volatile boolean firstBeat = true;            // used to seed rate array so we startup with reasonable BPM
volatile boolean secondBeat = false;          // used to seed rate array so we startup with reasonable BPM
volatile unsigned long lastMillis = 0;        // used to determine pulse timing
volatile float tempSignal=0;
volatile int msTime = 0;
float t;


void setup()
{
  sensors.begin();
   Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print("Connecting to ");
   Serial.print("WIFI_SSID");
     while (WiFi.status() !=WL_CONNECTED)
            {
              Serial.print(".");
              delay(500);
            }
   Serial.println();
   Serial.print("Connected");
   Serial.println("IP Address:");
   Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
   pinMode(A0,INPUT);
   interruptSetup();                          // sets up to read Pulse Sensor signal every 2mS
   lastMillis=millis();
 }

void loop()
{
   sensors.requestTemperatures();  
   t = sensors.getTempCByIndex(0);                                                                                
 
 if(msTime>10000)
    {
        noInterrupts();
        interrupts();
        msTime=0;
    }

    if (QS == true) {    // A Heartbeat Was Found

        serialOutputWhenBeatHappens();         // A Beat Happened, Output that to serial.
        QS = false;                            // reset the Quantified Self flag for next time
    }
}

//  Decides How To OutPut BPM and Temp Data
void serialOutputWhenBeatHappens() {
    sendDataToSerial('B',BPM);// send heart rate with a 'B' prefix
    Serial.print("Temperature is: ");                     // Send the command to get temperatures  
    Serial.println(t);
    ThingSpeak.setField(1, BPM);
    ThingSpeak.setField(2, t);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
 
}

void sendDataToSerial(char symbol, int data ) {
    Serial.print(symbol);
    Serial.println(data);
}

void interruptSetup() {

    flipper.attach_ms(2, ISRTr);
}

void ISRTr() {
    noInterrupts();                            // disable interrupts while we do this

    Signal = analogRead(pulsePin);             // read the Pulse Sensor
    current=millis();
    int difference = current-lastMillis;
    lastMillis=current;
    sampleCounter += difference;               // keep track of the time in mS with this variable
    msTime+=difference;
    int N = sampleCounter - lastBeatTime;      // monitor the time since the last beat to avoid noise

    //  finding the peak and trough of the pulse wave
    if(Signal < thresh && N > (IBI/5)*3) {     // avoid dichrotic noise by waiting 3/5 of last IBI
        if (Signal < T) {                      // T is the trough
            T = Signal;                        // keep track of lowest point in pulse wave
        }
    }

    if(Signal > thresh && Signal > P) {        // thresh condition helps avoid noise
        P = Signal;                            // P is the peak
    }                                          // keep track of highest point in pulse wave

 
    if (N > 250) {                                   // avoid high frequency noise
        if ( (Signal > thresh) && (Pulse == false) && (N > (IBI/5)*3) ) {
            Pulse = true;                            // set the Pulse flag when we think there is a pulse
            //digitalWrite(blinkPin,LOW);              // turn on pin 13 LED
            IBI = sampleCounter - lastBeatTime;      // measure time between beats in mS
            lastBeatTime = sampleCounter;            // keep track of time for next pulse

            if(secondBeat) {                         // if this is the second beat, if secondBeat == TRUE
                secondBeat = false;                  // clear secondBeat flag
                for(int i=0; i<=9; i++) {            // seed the running total to get a realisitic BPM at startup
                    rate[i] = IBI;
                }
            }

            if(firstBeat) {                          // if it's the first time we found a beat, if firstBeat == TRUE
                firstBeat = false;                   // clear firstBeat flag
                secondBeat = true;                   // set the second beat flag
                interrupts();                        // enable interrupts again
                return;                              // IBI value is unreliable so discard it
            }


            // keep a running total of the last 10 IBI values
            word runningTotal = 0;                   // clear the runningTotal variable

            for(int i=0; i<=8; i++) {                // shift data in the rate array
                rate[i] = rate[i+1];                 // and drop the oldest IBI value
                runningTotal += rate[i];             // add up the 9 oldest IBI values
            }

            rate[9] = IBI;                           // add the latest IBI to the rate array
            runningTotal += rate[9];                 // add the latest IBI to runningTotal
            runningTotal /= 10;                      // average the last 10 IBI values
            BPM = 60000/runningTotal;                // how many beats can fit into a minute? that's BPM!
            QS = true;                               // set Quantified Self flag
            // QS FLAG IS NOT CLEARED INSIDE THIS ISR
        }
    }

    if (Signal < thresh && Pulse == true) {  // when the values are going down, the beat is over

        //digitalWrite(blinkPin,HIGH);           // turn off pin 13 LED
        Pulse = false;                         // reset the Pulse flag so we can do it again
        amp = P - T;                           // get amplitude of the pulse wave
        thresh = amp/2 + T;                    // set thresh at 50% of the amplitude
        P = thresh;                            // reset these for next time
        T = thresh;
    }

    if (N > 2500) {                            // if 2.5 seconds go by without a beat
        thresh = 530;                          // set thresh default
        P = 512;                               // set P default
        T = 512;                               // set T default
        lastBeatTime = sampleCounter;          // bring the lastBeatTime up to date
        firstBeat = true;                      // set these to avoid noise
        secondBeat = false;                    // when we get the heartbeat back
        BPM=0;
    }
    interrupts();                              // enable interrupts when youre done!
}