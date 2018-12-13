#include <SoftwareSerial.h>
#include <Servo.h>
Servo S1;
SoftwareSerial bt(7, 8);

int servoPin = 2;
int RmotorGo = 3;
int RmotorBk = 5;
int LmotorGo = 6;
int LmotorBk = 11;
int rSpeed = 77;
int lSpeed = 80;
int trig = 9;
int echo = 10;
int ledState = 1;
int carState = 0;
int carGo = 1;
int speedVar = 1;
unsigned long time;

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
//  Serial.println("BT Starting~~");
// 開機Servo測試
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

void cGo(i)
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed * i);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed * i);
  analogWrite(LmotorBk, 0);
}

void cBack(i)
{
  digitalWrite(RmotorBk, HIGH);
  analogWrite(RmotorBk, rSpeed);
  analogWrite(RmotorGo, 0);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(LmotorBk, lSpeed);
  analogWrite(LmotorGo, 0);
}

void cStop()
{
  analogWrite(RmotorGo, 0);
  analogWrite(RmotorBk, 0);
  analogWrite(LmotorGo, 0);
  analogWrite(LmotorBk, 0);
}

void turnL(i)
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed * i);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, LOW);
  analogWrite(LmotorGo, 0);
  analogWrite(LmotorBk, 0);
}

void turnR(i)
{
  digitalWrite(RmotorGo, LOW);
  analogWrite(RmotorGo, 0);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed * i);
  analogWrite(LmotorBk, 0);
}

void turnLF(i, j)
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed * i);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed * j);
  analogWrite(LmotorBk, 0);
}

void turnRF(i, j)
{
  digitalWrite(RmotorGo, HIGH);
  analogWrite(RmotorGo, rSpeed * i);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorGo, HIGH);
  analogWrite(LmotorGo, lSpeed * j);
  analogWrite(LmotorBk, 0);
}
void spinL(i)
{
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  analogWrite(RmotorGo, rSpeed * i);
  analogWrite(RmotorBk, 0);
  digitalWrite(LmotorBk, HIGH);
  digitalWrite(LmotorGo, LOW);
  analogWrite(LmotorBk, lSpeed * i);
  analogWrite(LmotorGo, 0);
}

void spinR(i)
{
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(LmotorGo, lSpeed);
  analogWrite(LmotorBk, 0);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(RmotorGo, LOW);
  analogWrite(RmotorBk, rSpeed);
  analogWrite(RmotorGo, 0);
}

//測距
float dist()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  return pulseIn(echo, HIGH) / 58.2;
}

//Servo轉至指定角度
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

//避障檢查
void check() 
{
  analogWrite(A1, 1024);
  cStop();
  delay(50);
  float distR;
  float distL;
  servoTurn(0);
  distR = dist();
  delay(200);
  servoTurn(180);
  distL = dist();
  delay(200);
  servoTurn(90);

  //    Serial.print("右邊距離：");
  //    Serial.print(distR);
  //    Serial.print("  左邊距離：");
  //    Serial.println(distL);

  if (distR < 20 && distL < 20)
  {
    cBack(1);
    delay(200);
    check();
  }
  else if (distR > distL)
  {
    spinR(2);
    delay(200);
  }
  else
  {
    spinL(2);
    delay(200);
  }
  analogWrite(A1, 0);
  cStop();
  delay(200);
}

//自走模式
void freeGo()
{
  cGo(3);
  delay(2000);
  for (int i = 0; i < 5; i++)
  {
    cBack(2);
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    turnL(2);
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    turnR(2);
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    spinL(3);
    delay(200);
  }
  delay(500);
  for (int i = 0; i < 5; i++)
  {
    spinR(3);
    delay(200);
  }
  delay(500);
}

void loop()
{
  time = millis();
  int rPass = 0;
  int lpass = 0;
  int rSensor = analogRead(A4);
  int lSensor = analogRead(A5);

  if (ledState == 1)
  {
    if (carGo == 1)
    {
      if (rSensor < 500)
      {
        if (lSensor < 500)
          cGo(speedVar);
        else if (lSensor > 500)
        {
          turnRF(speedVar, speedVar * 2);
          if (rPass = 0)
            lPass = 1;
          else
            lPass = 2;
        }
      }
      else if (lSensor < 500)
      {
        if (rSensor < 500)
          cGo(speedVar);
        else if (rSensor > 500)
        {
          turnLF(speedVar, speedVar * 2);
          if (lPass = 0)
            rPass = 1;
          else
            rPass = 2;
        }
      }
      if (rPass > lPass)
        turnRF(speedVar, speedVar * 2);
      else
        turnLF(speedVar, speedVar * 2);
    }
  }

  Serial.print("rSensor:");
  Serial.print(rSensor);
  Serial.print("  lSensor:");
  Serial.println(lSensor);
  //  delay(500);
}
