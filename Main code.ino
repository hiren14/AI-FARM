/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  WARNING :
  For this example you'll need Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App project setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

#include <BlynkSimpleSerialBLE.h>

const int soil=3;
const int relay=4;
const int mq2=5;
const int relay2=6;
const int rain=7;
const int relay3=8;
const int mq135=9;
const int relay4=2;
#define BLYNK_PRINT Serial


//#include <SPI.h>
//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>
//#include <DHT.h>
#define TRIGGERPIN D1

#define ECHOPIN D2

#include <SimpleTimer.h>

#include <OneWire.h>

#include <DallasTemperature.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "wyDV16hdrn0Atw9sDF-ivgfwBh39QYZr";

//#define W5100_CS  10
//#define SDCARD_CS 4

//#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

//DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board "D4 pin on the ndoemcu Module"

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature DS18B20(&oneWire);

float temp;

float Fahrenheit=0;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup()
{
  pinMode(soil, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(mq2, INPUT);
  pinMode(relay2, OUTPUT);
  pinMode(rain, INPUT);
  pinMode(relay3, OUTPUT);
  pinMode(mq135, INPUT);
  //pinMode(servo, OUTPUT);
  
  
pinMode(TRIGGERPIN, OUTPUT);

pinMode(ECHOPIN, INPUT);
  
   SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
  
 // Debug console
  Serial.begin(9600);

  //pinMode(SDCARD_CS, OUTPUT);
  //digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  Blynk.begin(auth);
  // You can also specify server:
  //Blynk.begin(auth, "blynk-cloud.com", 80);
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);

  //dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}





void getSendData()

{

  DS18B20.requestTemperatures(); 

  temp = DS18B20.getTempCByIndex(0); // Celcius

  

  Serial.println(temp);

  

  Blynk.virtualWrite(V3, temp); //virtual pin V3

  


}





void loop()
{
if{
  (soil==High);
   digitalWrite(relay, HIGH);
   Blynk.email("hiren14lalani@gmail.com", "Ardunio UNO Alert", "SOIL MOISTURE IS HIGH "); Blynk.notify("Ardunio UNO Alert - SOIL MOISTURE IS HIGH !!!");
  }
  else
  {
    digitalWrite(relay, LOW);
  }


 
if{
  (rain==High);
   digitalWrite(relay3, HIGH);Blynk.email("hiren14lalani@gmail.com", "Ardunio UNO Alert", "out side rain "); Blynk.notify("Ardunio UNO Alert -out side rain!!");
  }
  else
  {
    digitalWrite(relay3, LOW);
  }


  
if{
  (mq135==High);
   digitalWrite(relay2, HIGH);Blynk.email("hiren14lalani@gmail.com", "Ardunio UNO Alert", "AIR QULATITY "); Blynk.notify("Ardunio UNO Alert -AIR QULATITY !");
  }
  else
  {
    digitalWrite(relay2, LOW);
  }



/*  
if{
  (mq4==High);
   digitalWrite(relay3, HIGH);
  }
  else
  {
    digitalWrite(relay3, LOW);
  }
*/


lcd.clear(); //Use it to clear the LCD Widget

lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") // Please use timed events when LCD printintg in void loop to avoid sending too many commands // It will cause a FLOOD Error, and connection will be dropped }

void loop() {

lcd.clear();

lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") long duration, distance;

digitalWrite(TRIGGERPIN, LOW);

delayMicroseconds(3);

digitalWrite(TRIGGERPIN, HIGH);

delayMicroseconds(12);

digitalWrite(TRIGGERPIN, LOW);

duration = pulseIn(ECHOPIN, HIGH);

distance = (duration/2) / 29.1;

Serial.print(distance);

Serial.println("Cm");

lcd.print(7, 1, distance);



























  
  
}
  
  Blynk.run();
  timer.run();
}
