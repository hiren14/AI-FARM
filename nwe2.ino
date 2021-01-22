#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <SimpleTimer.h>

#include <OneWire.h>

#include <DallasTemperature.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

char auth[] = "f24df138e4fe4d74967a74b95d475cf7";

 

/* WiFi credentials */

char ssid[] = "ZONG MBB-E8231-6E63";

char pass[] = "romeo1234";

 

SimpleTimer timer;

 

 

 

#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board "D4 pin on the ndoemcu Module"

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature DS18B20(&oneWire);

float temp;

float Fahrenheit=0;

void setup() 

{

  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  DS18B20.begin();

  timer.setInterval(1000L, getSendData);

}

 

void loop() 

{

  timer.run(); // Initiates SimpleTimer

  Blynk.run();

}

 

/*****************

* Send Sensor data to Blynk

******************/

void getSendData()

{

  DS18B20.requestTemperatures(); 

  temp = DS18B20.getTempCByIndex(0); // Celcius

   Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit

  Serial.println(temp);

  Serial.println(Fahrenheit);

  Blynk.virtualWrite(V3, temp); //virtual pin V3

  Blynk.virtualWrite(V4, Fahrenheit); //virtual pin V4


}