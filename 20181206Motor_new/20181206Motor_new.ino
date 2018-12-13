#include <Servo.h>
Servo S1;

int servoPin = 2;
int RmotorGo = 3;
int RmotorBk = 5;
int LmotorGo = 6;
int LmotorBk = 11;
int rSpeed = 80;
int lSpeed = 100;
int trig = 9;
int echo = 10;

void setup() {
  pinMode(RmotorGo, OUTPUT);
  pinMode(RmotorBk, OUTPUT);
  pinMode(LmotorGo, OUTPUT);
  pinMode(LmotorBk, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  S1.attach(servoPin);
  Serial.begin(38400);
  while (!Serial)
  {
    ;
  }
  S1.write(90);
  for (int i = 90; i >= 0; i--)
  {
    S1.write(i);
    delay(10);
  }
  for (int i = 0; i <= 180; i++)
  {
    S1.write(i);
    delay(10);
  }
  for (int i = 180; i >= 90; i--)
  {
    S1.write(i);
    delay(10);
  }
}

void cGo()
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed);
  analogWrite(LmotorBk, 0);
  delay(100);
}

void cBack()
{
  digitalWrite(RmotorBk, HIGH);
  analogWrite(RmotorBk, rSpeed);
  analogWrite(RmotorGo, 0);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(LmotorBk, lSpeed);
  analogWrite(LmotorGo, 0);
  delay(100);
}

void cStop()
{
  analogWrite(RmotorGo, 0);
  analogWrite(RmotorBk, 0);
  analogWrite(LmotorGo, 0);
  analogWrite(LmotorBk, 0);
  delay(100);
}

void turnL()
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, LOW);
  analogWrite(LmotorGo, 0);
  analogWrite(LmotorBk, 0);
  delay(100);
}

void turnR()
{
  digitalWrite(RmotorGo, LOW);
  analogWrite(RmotorGo, 0);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed);
  analogWrite(LmotorBk, 0);
  delay(100);
}

void spinL()
{
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  analogWrite(RmotorGo, rSpeed);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorBk, HIGH);
  digitalWrite(LmotorGo, LOW);
  analogWrite(LmotorBk, lSpeed);
  analogWrite(LmotorGo, 0);
  delay(100);
}

void spinR()
{
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(LmotorGo, lSpeed);
  analogWrite(LmotorBk, 0);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(RmotorGo, LOW);
  analogWrite(RmotorBk, rSpeed);
  analogWrite(RmotorGo, 0);
  delay(100);
}

float dist()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  return pulseIn(echo, HIGH) / 58.2;
}

void servoTurn(int angle)
{
  int nowAngle = S1.read();
  if (nowAngle > angle)
  {
    for (int i = nowAngle; i >= angle; i--)
    {
      S1.write(i);
      delay(10);
    }
  }
  else
  {
    for (int i = nowAngle; i <= angle; i++)
    {
      S1.write(i);
      delay(10);
    }
  }
}

void check() {
  cStop();
  float distR;
  float distL;
  servoTurn(0);
  distR = dist();
  delay(200);
  servoTurn(180);
  distL = dist();
  delay(200);
  servoTurn(90);

  Serial.print("右邊距離：");
  Serial.print(distR);
  Serial.print("  左邊距離：");
  Serial.println(distL);
 if (distR < 20 && distL < 20)
  {
    cBack();
    delay(200);
    check();
  }
  else if (distR > distL)
  {
    spinR();
    delay(200);
  }
  else
  {
    spinL();
    delay(200);
  }
  cStop();
  delay(200);
}

void loop() {
  float nowDist = dist();
  Serial.print("現在距離：");
  Serial.println(nowDist);
  if (nowDist > 20)
    cGo();
  else
    check();
  //  cStop();
  //  delay(100);
  //  for (int i = 0; i < 5; i++)
  //  {
  //    cBack();
  //    delay(100);
  //  }
  //  cStop();
  //  delay(100);
  //  for (int i = 0; i < 5; i++)
  //  {
  //    turnL();
  //    delay(200);
  //  }
  //  cStop();
  //  for (int i = 0; i < 5; i++)
  //  {
  //    turnR();
  //    delay(200);
  //  }
  //  cStop();
  //  delay(200);
  //  for (int i = 0; i < 5; i++)
  //  {
  //    spinL();
  //    delay(200);
  //  }
  //  delay(1000);
  //   for (int i = 0; i < 5; i++)
  //  {
  //    spinR();
  //    delay(200);
  //  }
  //  delay(2000);
}
