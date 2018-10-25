int ledR = 7;

void setup()
{
  pinMode(ledR, OUTPUT);
}

void S()
{
  for (int i = 0; i < 3 ; i++)
  {
    digitalWrite(ledR, HIGH);
    delay(150);
    digitalWrite(ledR, LOW);
    delay(100);
  }
}

void O()
{
  for (int i = 0; i < 3 ; i++)
  {
    digitalWrite(ledR, HIGH);
    delay(400);
    digitalWrite(ledR, LOW);
    delay(100);
  }
}
void loop()
{
  S();
  delay(500);
  O();
  delay(500);
  S();
  delay(1000);
}
