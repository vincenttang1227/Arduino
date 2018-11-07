int trig = 8;
int echo = 9;
int ledG = 10;
int ledY = 11;
int ledR = 12;
int buzzer1=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer1,OUTPUT);
  Serial.begin(9600);
}
float dis()
{
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long tt = pulseIn(echo, HIGH);
  return tt / 58.2;

}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledG,LOW);
  digitalWrite(ledY,LOW);
  digitalWrite(ledR,LOW);
  float dd = dis();
  if (dd > 10)
  {
    digitalWrite(ledG, HIGH);
  }
  else if (dd > 5 && dd < 10)
  {
    digitalWrite(ledY, HIGH);
    digitalWrite(buzzer1,HIGH);
    delay(500);
    digitalWrite(buzzer1,LOW);
    delay(500);
  }
  else if (dd < 5)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(buzzer1,HIGH);
    delay(100);
    digitalWrite(buzzer1,LOW);
    delay(500);
    digitalWrite(buzzer1,HIGH);
    delay(100);
    digitalWrite(buzzer1,LOW);
    delay(500);
     digitalWrite(buzzer1,HIGH);
    delay(100);
    digitalWrite(buzzer1,LOW);
    delay(500);
  }

  Serial.print("距離:");
  Serial.print(dd);
  Serial.println("CM");
  delay(1000);
}
