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
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ynY7DXLr7y7vSSh4Amvfys11V_Obp6kU";

// Your WiFi credentials.
// Set password to "" for open networks.
//code by hiren lalani 
char ssid[] = "Sangeeta";
char pass[] = "12345678";

Servo servo;

BLYNK_WRITE(V1) {

servo.write(param.asInt());
}
// These are used to set the direction of the bridge driver.
#define ENB D3      //ENB
#define MOTORB_1 D4 //IN3
#define MOTORB_2 D5 //IN4
#define MOTORA_1 D7 //IN1
#define MOTORA_2 D6 //IN2                              
#define ENA D8      //ENA

// SETUP
void setup()
{
  // Configure pins
  pinMode(ENA, OUTPUT);
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);

  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  servo.attach(5);  
  // Start serial communication
  Serial.begin(9600);

  // Connect Blynk
  Blynk.begin(auth, ssid, pass);
}


// FORWARD
BLYNK_WRITE(V4) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving forward");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
                                  
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                              digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else {
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}


// BACKWARD
BLYNK_WRITE(V5) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else {
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}

//ZERO
BLYNK_WRITE(V2)  {
  servo.write(0);
}

//180

BLYNK_WRITE(V3)   {
  servo.write(360);
  
}

// MAIN CODE
void loop()
{
  Blynk.run();
}
