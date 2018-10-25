int ledR = 2;
int ledY = 4;
int ledG = 6;

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop()
{
  digitalWrite(ledR, HIGH);
  delay(5000);
  digitalWrite(ledR, LOW);
  /*
    digitalWrite(ledY,HIGH);
    delay(2000);
    digitalWrite(ledY,LOW);
  */
  digitalWrite(ledG, HIGH);
  delay(5000);
  digitalWrite(ledG, LOW);
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledY, HIGH);
    delay(250);
    digitalWrite(ledY, LOW);
    delay(250);
  }
}
