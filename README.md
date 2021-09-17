
# SWASTHYA: IOT Based Health Monitoring System

#### Abstract
* Health and fitness have become more important.
* Healthcare sensors are playing a vital role in hospitality.
* Patient monitoring system, a major improvement in hospitality because of its advanced technology.
* Our proposed system provides a better health monitoring service.
* An IOT based system to measure temperature and pulse rate.
* The system is interfaced with cloud through which caretakers can have an update about the patient’s condition.

#### Introduction

* COVID-19, an infectious disease caused by a newly discovered coronavirus has affected people’s lives adversely.
* Most of the people infected with COVID-19 virus will show mild to moderate symptoms.
* Body temperature rise, irregular pulse rate and shortness of breath caused due to low oxygen saturation level are some of the symptoms.
* Elderly people being more prone to this infectious disease they need to be regularly monitored to prevent further complications.

#### Objectives

* To design a portable health monitoring system.
* To provide medical assistance according to the data received.
* To prevent further infection of coronavirus.

#### Problem Statement

* Elderly people and the young ones being more prone to COVID19 need special attention and effective Monitoring System.

#### Methodology

* The system consists of temperature sensor and pulse sensor that measures the patient's body temperature and pulse rate.
* The data received from these sensors is stored in cloud server (ThingSpeak) through NODEMCU Wifi module.
* The NODEMCU WiFi module is provided with the power supply.
* Display of the stored data is accessed by the caretakers and doctors to monitor patients.


## Block Daigram
![block](https://user-images.githubusercontent.com/83587918/133770819-1ce14119-3bc4-465f-865d-ee79718afc81.png)

## Requirements

#### Hardware Requirements:
* Temperature sensor(DS18B20)
* Pulse sensor
* NODEMCU (ESP8266)
* Resistor (4.7k )
* Breadboard
* Power Supply (Battery or Power Bank)

#### Software Requirements:
* Arduino compiler
* ThingSpeak(Cloud service)


## Images
![temp](https://user-images.githubusercontent.com/83587918/133770817-4c2a0611-fb2c-434d-aec2-3187e9b387d2.jpg)
![node mcu](https://user-images.githubusercontent.com/83587918/133770822-0344042f-36d0-40c2-836d-1a38a1d26a11.jpg)
![pulse](https://user-images.githubusercontent.com/83587918/133770824-ae1cf52b-0613-4230-adf6-94345f3f50b8.png)
![resistor](https://user-images.githubusercontent.com/83587918/133828682-6838858f-c2b2-497f-85b7-6b8d742d562a.jpeg)

## Project Setup

#### Step 1
Take a Breadboard and attach  NodeMCU ESP8266. Then do the required connections shown in the pictures.

 #### -->Pulse Sensor Connection
 
![connection](https://user-images.githubusercontent.com/83587918/133828890-06089f59-5886-40b7-8f07-e2251bed8bb8.jpg)

* Negative (–) -----------> Gnd pin
* Positive (+) -----------> 3v3 pin
* s pin of Sensor -----------> A0

 #### -->Temperature Sensor Connection
 
 ![temp](https://user-images.githubusercontent.com/83587918/133828924-2dd02235-072f-4ddf-9f37-d9ce7b2dd1a2.png)

* Connect the GND pin or the black wire of the sensor to the GND.

* Connect the Vcc pin or the Red wire of the sensor to the 3.3V supply.

* Connect the signal pin or the yellow wire to the 3.3V through a 4.7kohm resistor and also connect this signal pin to the GPIO12 which is D5 pin of the module.

#### Step 2
Install and setup Arduino IDE in your PC. Download and install all required libraries. Check and set the port in Arduino IDE and connect the NodeMCU ESP8266 using USB cable. 
Copy the code given, in your Arduino IDE and make required changes in the code.
Such As:
* Wifi Name
* Wifi Password
* Channel ID
* Thingspeak API Key

    #### Note
    Create an account in Thingspeak Cloud service then create one channel, give a name for that particular channel. When you open that channel you will get option called "API KEYS" here you will get the API key of your channel which you will need to copy in the code!


## Output
![output1](https://user-images.githubusercontent.com/83587918/133771688-630ea6d1-a332-428f-9b2d-16ca2b7bdc2d.png)

#### --> Care taker or Doctor can also download all the data in the form of excel sheet for further requirements!!


![Picture4](https://user-images.githubusercontent.com/83587918/133771697-487c9f75-799c-4be6-9048-89cba78298ad.png)

### Who are our End Customers?

* Aged people and the young ones who need special attention.
* Covid-19 victims who are supposed to be monitored for at least 14 days.
* Doctors and the hospitals who wish to provide better service to their patient's.
* Government ,to benefit its citizens.

### Conclusion

* Our proposed system aims at simplifying health monitoring.
* This system of ours has been proven effective enough in aiding medical assistance.
* This approach of ours contributes towards smart India.

## References

* Marathe, Sachi, et al. "A Wireless Patient Monitoring System using Integrated ECG module, Pulse Oximeter, Blood Pressure and Temperature Sensor." 2019 International Conference on Vision Towards Emerging Trends in Communication and Networking (ViTECoN). IEEE, 2019.
* Basu, Samik, et al. "Smart Health Monitoring System for Temperature, Blood Oxygen Saturation, and Heart Rate Sensing with Embedded Processing and Transmission Using IoT Platform." Computational Intelligence in Pattern Recognition. Springer, Singapore, 2020. 81-91.
* Mishra, Vaibhav, Durgesh Kumar Mishra, and Ass Pro Ankit Trivedi. "Health Monitoring System using IoT using Arduino Uno Microcontroller." Health 6.08 (2019).











