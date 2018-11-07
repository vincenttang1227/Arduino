void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 18; i++)
  {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i < 10; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
  }
  for (int i = 9; i >= 2; i--)
  {
    digitalWrite(i, LOW);
    delay(500);
  }
  for (int i = 2; i < 10; i++)
  {
    digitalWrite(i, HIGH);

  }
  delay(500);
  for(int i=10;i<18;i++)
  {
    digitalWrite(i,HIGH);
    delay(500);
    }
      for(int i=10;i<18;i++)
  {
    digitalWrite(i,LOW);
    }
}
