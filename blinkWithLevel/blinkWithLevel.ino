byte led = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led,0);
  delay(1000);
  analogWrite(led,25);
  delay(1000);
  analogWrite(led,75);
  delay(1000);
  analogWrite(led,125);
  delay(1000);
}
