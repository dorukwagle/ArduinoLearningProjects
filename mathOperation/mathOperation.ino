int count;
int ran[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<20;i++){
     ran[i] = random(20);
  }

  Serial.print("random: ");
  for(int i=0;i<20;i++){
    Serial.print(ran[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  count++;
if(count == 5)
  delay(9999999);  

}
