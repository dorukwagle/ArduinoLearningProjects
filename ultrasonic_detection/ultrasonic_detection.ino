#include "SR04.h"

#define GREEN 5
#define RED 6
#define TRIG_PIN 3
#define ECHO_PIN 9
#define BUZZER 2

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

long distance = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  short led_state = LOW;
  Serial.println(sr04.Distance());
  while((distance = sr04.Distance()) <= 20) {
    led_state = !led_state;
    digitalWrite(GREEN, led_state);
    digitalWrite(RED, !led_state);
    digitalWrite(BUZZER, HIGH);
    delay(100);
  }

  digitalWrite(BUZZER, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);

  short brightness = 0;
  for (; brightness <= 255; ++brightness) {
    analogWrite(GREEN, brightness);
    delay(2);
  }
  for (; brightness >= 0; --brightness) {
    analogWrite(GREEN, brightness);
    delay(2);
  }
}