
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


### Block Daigram


### Requirements

#### Hardware Requirements:
* Temperature sensor(DS18B20)
* Pulse sensor
* NODEMCU (ESP8266)
* Breadboard
* Power Supply (Battery or Power Bank)

#### Software Requirements:
* Arduino compiler
* ThingSpeak(Cloud service)


### Images


### Project Setup

#### Step 1
Take a Breadboard and attach  NodeMCU ESP8266. Then do the required connections shown in the pictures.

((((Addd images))))
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


### Output

((((add images))))

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











