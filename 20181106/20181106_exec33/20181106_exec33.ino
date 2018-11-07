void setup() {
  for(int i=2;i<18;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(int i=2;i<10;i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
  }
  for(int i=9;i>=2;i--)
  {
    digitalWrite(i,LOW);
    delay(100);
  }
  delay(100);
  for(int i=2;i<10;i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
  }
  delay(100);
 for(int i=10;i<18;i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
  }
for(int i=18;i>=10;i--)
  {
    digitalWrite(i,LOW);
    delay(100);
  }
 
}
