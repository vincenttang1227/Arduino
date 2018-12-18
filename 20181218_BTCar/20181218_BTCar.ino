#include <SoftwareSerial.h>
#include <Servo.h>
Servo S1;
SoftwareSerial bt(7, 8);

int trigP = 2;
int echoP = 4;
int RmotorGo = 3;
int RmotorBk = 5;
int LmotorGo = 6;
int LmotorBk = 11;
int servoP = 9;
int cState = 0;
float dist;
int cDirect = 0;
int lTracer = A4;
int rTracer = A5;

void setup() {
  pinMode(RmotorGo, OUTPUT);
  pinMode(RmotorBk, OUTPUT);
  pinMode(LmotorGo, OUTPUT);
  pinMode(LmotorBk, OUTPUT);
  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);
  Serial.begin(38400);
  S1.attach(servoP);
  S1.write(90);
  turnServo(S1, 0);
  turnServo(S1, 180);
  turnServo(S1, 90);
  dist = distance();
  bt.begin(38400);
  while (!Serial)
  {
    ;
  }
  Serial.println("BT Start");
  analogWrite(A0, 1024);
  analogWrite(A1, 0);
}

void turnServo(Servo S, int angle) {
  int nowAngle = S.read();
  if (nowAngle > angle) {
    for (int i = nowAngle; i >= angle; i--) {
      S.write(i);
      delay(5);
    }
  }
  else {
    for (int i = nowAngle; i <= angle; i++) {
      S.write(i);
      delay(5);
    }
  }
}

float distance() {
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
  return pulseIn(echoP, HIGH) / 58.8;
}

void cGo(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorGo, pwm);
  analogWrite(LmotorGo, pwm * 1.14);
  delay(cTime);
}

void cBack(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(RmotorBk, pwm);
  analogWrite(LmotorBk, pwm * 1.14);
  delay(cTime);
}

void cStop(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, LOW);
  delay(cTime);
}

void turnR(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(LmotorGo, pwm);
  delay(cTime);
}

void turnL(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorGo, pwm);
  delay(cTime);
}

void turnFR(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorGo, pwm / 2);
  analogWrite(LmotorGo, pwm);
  delay(cTime);
}

void turnFL(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorGo, pwm);
  analogWrite(LmotorGo, pwm / 2);
  delay(cTime);
}

void spinR(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorBk, pwm);
  analogWrite(LmotorGo, pwm);
  delay(cTime);
}

void spinL(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(RmotorGo, pwm);
  analogWrite(LmotorBk, pwm);
  delay(cTime);
}

void freeStyle() {
  for (int i = 0; i < 5; i++) {
    cGo(250, 255);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    cBack(250, 255);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    turnFL(250, 255);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    turnFR(250, 255);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    spinL(250, 255);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    spinR(250, 255);
    delay(250);
  }
  cStop(0, 0);
}

void cAvoid() {
  dist = distance();
  dist = constrain(dist, 0, 80);

  if (dist > 25) {
    analogWrite(A1, 0);
    cGo(50, 120);
  }
  else {
    analogWrite(A1, 512);
    cStop(0, 0);
    turnServo(S1, 0);
    delay(250);
    float rDist = distance();
    turnServo(S1, 180);
    delay(250);
    float lDist = distance();
    turnServo(S1, 90);

    if (rDist < 25 && lDist < 25) {
      cBack(500, 150);
    }
    else if (rDist > lDist) {
      cBack(500, 150);
      cStop(200, 0);
      turnR(250, 150);
    }
    else if (rDist < lDist) {
      cBack(500, 150);
      cStop(200, 0);
      turnL(250, 150);
    }
  }
}

void carBT() {
  if (cDirect == 1)
    spinL(50, 120);
  else if (cDirect == 2)
    cGo(50, 120);
  else if (cDirect == 3)
    spinR (50, 120);
  else if (cDirect == 4)
    turnL(50, 120);
  else if (cDirect == 5)
    cStop(0, 0);
  else if (cDirect == 6)
    turnR(50, 120);
  else if (cDirect == 8)
    cBack(50, 120);
}

void tracer() {
  int lT = analogRead(lTracer);
  int rT = analogRead(rTracer);
  int cSpeed = 200;
  unsigned long time1, time2;

  if (lT < 500 && rT < 500)
    cGo(50, cSpeed);
  else if (lT > 500 && rT < 500)
    turnL(50, cSpeed);
  else if (lT < 500 && rT > 500)
    turnR(50, cSpeed);
  else if (lT < 500 && rT < 500)
    cBack(50, cSpeed);
  cStop(0, 0);
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    if (value != 0)
      cState = value;
  }

  if (bt.available() > 0) {
    char ch = bt.read();
    int num = bt.parseInt();

    if (ch == 'B') {
      cState = num;
      cDirect = 0;
      cStop(0, 0);
    }
    if (cState == 3) {
      if (ch == 'C')
        cDirect = num;
    }
    Serial.print(ch);
    Serial.println(num);
  }

  switch (cState) {
    case 1:
      freeStyle();
      break;
    case 2:
      cAvoid();
      break;
    case 3:
      carBT();
      break;
    case 4:
      tracer();
      break;
    default:
      break;
  }
}
