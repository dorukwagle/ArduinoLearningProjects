#include <Arduino.h>
#include "SR04.h"
#include "Stepper.h"

#define TRIG_PIN 3
#define ECHO_PIN 5

#define  RPM 120
const int STEPS = 200;

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
Stepper stepper(STEPS, 8, 9, 10, 11);

long distance = 0;
void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(RPM);
}

void loop()
{
  distance = sr04.Distance();
  if (!distance) return;
  Serial.println(distance);
  if (distance > 20){
    Serial.println("positive rotating");
    stepper.step(STEPS);
  }
  else {
    Serial.println("negative rotating");
    stepper.step(- STEPS);
  }
  delay(1000);
}