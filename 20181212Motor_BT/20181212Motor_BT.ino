#include <SoftwareSerial.h>
#include <Servo.h>
Servo S1;
SoftwareSerial bt(7, 8);

int servoPin = 2;
int RmotorGo = 3;
int RmotorBk = 5;
int LmotorGo = 6;
int LmotorBk = 11;
int rSpeed = 80;
int lSpeed = 84;
int trig = 9;
int echo = 10;
int ledState = 0;
int carState = 0;

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
  Serial.println("BT Starting~~");

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
  analogWrite(A1, 0);
  cStop();
  delay(200);
}

void freeGo()
{
  cGo();
  delay(2000);
  for (int i = 0; i < 5; i++)
  {
    cBack();
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    turnL();
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    turnR();
    delay(200);
  }
  cStop();
  delay(200);
  for (int i = 0; i < 5; i++)
  {
    spinL();
    delay(200);
  }
  delay(500);
  for (int i = 0; i < 5; i++)
  {
    spinR();
    delay(200);
  }
  delay(500);
}

void loop()
{
  float nowDist = dist();
  constrain(nowDist, 0, 100);
  //  Serial.print("現在距離：");
  //  Serial.println(nowDist);
  
  //設定前進與停車變數
  if (ledState == 1)
  {
    if (carState == 0)
      cStop();
    else if (carState == 1)
      cGo();
    else if (carState == 2)
      turnL();
    else if (carState == 3)
      turnR();
    else if (carState == 4)
      cBack();
    else if (carState == 5)
    {
      if (nowDist > 20)
        cGo();
      else
        check();
    }
    else if (carState == 6)
      freeGo();
  }
  else
  {
    cStop();
    carState = 0;
  }

  if (bt.available() > 0)
  {
    char ch = bt.read();
    int num = bt.parseInt();

    Serial.print(ch);
    Serial.println(num);

    //藍芽控制綠燈開關
    if (ch == 'C' && num == 0)
    {
      if (ledState == 0)
      {
        ledState = 1;
        analogWrite(A0, 1024);
      }
    }
    if (ch == 'C' && num == 2)
    {
      if (ledState == 1)
      {
        ledState = 0;
        analogWrite(A0, 0);
      }
    }

    //設定藍芽控制前進與停止
    if (ch == 'C' && num == 1)
      carState = 1;//前進
    if (ch == 'C' && num == 4)
      carState = 0;//停止
    if (ch == 'C' && num == 3)
      carState = 2;//左轉
    if (ch == 'C' && num == 5)
      carState = 3;//右轉
    if (ch == 'C' && num == 7)
      carState = 4;//後退
    if (ch == 'C' && num == 6)
      carState = 5;//自走避障
    if (ch == 'C' && num == 8)
      carState = 6;//花式自走
  }
  //  if (ledState == 1)
  //    analogWrite(A0, 1024);
  //  else
  //    analogWrite(A0, 0);
}
