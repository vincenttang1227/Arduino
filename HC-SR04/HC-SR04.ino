int trig = 8;
int echo = 9;
int ledR = 10;
int ledY = 11;
int ledG = 12;
int buzz = 6;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(9600);
}

float dist()
{
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  long tt = pulseIn(echo, HIGH);
  return tt / 58.2;
}

void loop()
{
  float dd = dist();
  if (dd > 10)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, HIGH);
  }
  else if (dd > 5 && dd < 10)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    tone(buzz, 512, 500);
    delay(500);
    digitalWrite(ledY, LOW);
    delay(500);
  }
  else if (dd < 5)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    tone(buzz, 512, 100);
    delay(100);
    digitalWrite(ledR, LOW);
    delay(100);
  }
  Serial.print("距離：");
  Serial.print(dd);
  Serial.println("cm");
}
