#include <SoftwareSerial.h>
#include <Servo.h>
Servo S1;
SoftwareSerial bt(7, 8);

int servoPin = 2;
int RmotorGo = 3;
int RmotorBk = 5;
int LmotorGo = 6;
int LmotorBk = 11;
int rSpeed = 100;
int lSpeed = 120;
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
  bt.begin(38400);
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
  delay(250);
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

void check()
{
  cStop();
  delay(100);
  cBack();
  delay(100);

  S1.write(0);
  float distR = dist();
  delay(250);
  S1.write(180);
  float distL = dist();
  delay(250);
  S1.write(90);

  Serial.print("右邊距離：");
  Serial.print(distR);
  Serial.print("  左邊距離：");
  Serial.println(distL);
  
  if (distR < 25 && distL < 25)
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
  if (nowDist > 25)
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
