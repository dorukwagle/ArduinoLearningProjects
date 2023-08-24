int value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A4);
  Serial.println(value);
  delay(3000);
}
