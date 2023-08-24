#include <Arduino.h>
#include "SR04.h"
#include "Servo.h"

#define TRIG_PIN 3
#define ECHO_PIN 5
#define SERVO_PIN 9


SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
Servo servo;

long distance = 0;
void setup()
{
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  servo.write(90);
}

void loop()
{
  distance = sr04.Distance();
  if (!distance)
    return;
  Serial.println(distance);
  if (distance > 20)
    servo.write(100);
  else if (distance > 18)
    servo.write(80);
  else if (distance > 15)
    servo.write(60);
  else if (distance > 12)
    servo.write(40);
  else if (distance > 8)
    servo.write(10);
  else if (distance > 2)
    servo.write(0);
  delay(200);
}