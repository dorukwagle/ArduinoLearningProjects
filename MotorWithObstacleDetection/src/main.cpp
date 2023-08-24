#include <Arduino.h>
#include "SR04.h"

#define TRIG_PIN 3
#define ECHO_PIN 9

#define ENABLE 5
#define DIRA 6
#define DIRB 7

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

long distance = 0;
void setup()
{
  // Serial.begin(9600);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  analogWrite(ENABLE, 120);
}

void loop()
{
  distance = sr04.Distance();

  if (distance > 20) {
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW); 
  }
  else {
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
  }
}