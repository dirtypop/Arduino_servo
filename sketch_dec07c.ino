#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
Servo servo1;
const int PIN_SERVO = 5;
const int PIN_LED = 4;
const int PIN_SENSOR = A0;
int val;

void setup()
{
  //Serial Monitor
  Serial.begin(9600);
  
  //Servo
  servo1.attach(PIN_SERVO);
  
  //LED
  pinMode(PIN_LED, OUTPUT);
  
  //SENSOR
  pinMode(PIN_SENSOR, INPUT);
  
  //columns, rows of LCD
  lcd.begin(16,2);
  //Sample text
  lcd.print("Hajime");
  
  delay(1000);
}

void loop()
{
//  lcd.noDisplay();
//  analogWrite(PIN_LED, 0);
//  delay(1000);

//  lcd.display();
  Serial.print("Sensor:");
  val = analogRead(PIN_SENSOR);// 0 - 1023
  Serial.print(val);
  Serial.println("¥n");
  val = map(val, 0, 1023, 0, 180);// 0 - 180
  servo1.write(val);
//  analogWrite(PIN_LED, i); // 0 - 1023
  delay(15);
}

