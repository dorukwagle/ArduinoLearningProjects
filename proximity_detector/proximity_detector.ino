#define PIR 3
#define LED 9
#define BUZZER 11

bool is_waiting() {
 return  (millis() / 1000) < 60;
}

void delay_for_setup() {

   short led_state = LOW;
  while(is_waiting()) // 1 minute
  {
    led_state = !led_state;
    digitalWrite(LED, led_state);
    if(is_waiting) delay(400);
  }
  if(led_state == HIGH) digitalWrite(LED, LOW);
  short buzzer_state = LOW;
  short buzzer_count = 3;
  while(buzzer_count-- >= 0) {
    buzzer_state = !buzzer_state;
   digitalWrite(BUZZER, buzzer_state);
   delay(300);
  }
  digitalWrite(BUZZER, LOW);
}

void setup() {
    pinMode(PIR, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
 if(is_waiting()) delay_for_setup();

  short detected = digitalRead(PIR);
  digitalWrite(LED, detected);
  digitalWrite(BUZZER, detected);
}