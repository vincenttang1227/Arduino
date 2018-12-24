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
float dist;
int cState = 0;
int ledState = 0;
int cDirect = 0;
int cSpeed = 200;
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
  analogWrite(LmotorGo, pwm * 1.3);
  delay(cTime);
}

void cBack(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(RmotorBk, pwm);
  analogWrite(LmotorBk, pwm * 1.2);
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
  analogWrite(RmotorGo, pwm / 3.5);
  analogWrite(LmotorGo, pwm);
  delay(cTime);
}

void turnFL(int cTime, int pwm) {
  digitalWrite(RmotorGo, HIGH);
  digitalWrite(RmotorBk, LOW);
  digitalWrite(LmotorGo, HIGH);
  digitalWrite(LmotorBk, LOW);
  analogWrite(RmotorGo, pwm);
  analogWrite(LmotorGo, pwm / 3.5);
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

void freeStyle(int cs) {
  for (int i = 0; i < 5; i++) {
    cGo(250, cs);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    cBack(250, cs);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    turnFL(250, cs);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    turnFR(250, cs);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    spinL(250, cs);
    delay(250);
  }
  cStop(0, 0);
  for (int i = 0; i < 5; i++) {
    spinR(250, cs);
    delay(250);
  }
  cStop(0, 0);
  cState = 0;
}

void cAvoid() {
  dist = distance();
  dist = constrain(dist, 0, 80);

  if (dist > 25) {
    cGo(50, 120);
  }
  else {
    analogWrite(A2, 512);
    analogWrite(A3, 512);
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
      turnR(500, 150);
    }
    else if (rDist < lDist) {
      cBack(500, 150);
      cStop(200, 0);
      turnL(500, 150);
    }
  }
}

void carBT(int i) {
  analogWrite(A2, 512);
  if (cDirect == 2)
    cGo(50, i);
  else if (cDirect == 4) {
    analogWrite(A0, 512);
    analogWrite(A1, 0);
    turnL(50, i);
  }
  else if (cDirect == 5)
    cStop(0, 0);
  else if (cDirect == 6) {
    analogWrite(A0, 0);
    analogWrite(A1, 512);
    turnR(50, i);
  }
  else if (cDirect == 7) {
    analogWrite(A0, 512);
    analogWrite(A1, 0);
    spinL(50, i);
  }
  else if (cDirect == 8)
    cBack(50, i);
  else if (cDirect == 9) {
    analogWrite(A0, 0);
    analogWrite(A1, 512);
    spinR (50, i);
  }
}

void tracer(int i) {
  int lT = analogRead(lTracer);
  int rT = analogRead(rTracer);
  unsigned long time1, time2;

  if (lT < 500 && rT < 500) {
    analogWrite(A0, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 512);
    cGo(50, i);
  }
  else if (lT > 500 && rT < 500) {
    analogWrite(A0, 0);
    analogWrite(A1, 512);
    analogWrite(A2, 512);
    turnFL(50, i*1.2);
  }
  else if (lT < 500 && rT > 500) {
    analogWrite(A0, 512);
    analogWrite(A1, 0);
    analogWrite(A2, 512);
    turnFR (50, i*0.8);
  }
  else if (lT > 500 && rT > 500) {
    analogWrite(A0, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    cStop(0, 0);
  }
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

    if (ch == 'C' && num == 1)
      ledState = 1;
    if (ch == 'C' && num == 3)
      ledState = 0;

    if (ledState == 1)
      analogWrite(A2, 512);
    else
      analogWrite(A2, 0);

    if (ledState == 1) {
      if (ch == 'B') {
        cState = num;
        cDirect = 0;
        cStop(0, 0);
        analogWrite(A0, 0);
        analogWrite(A1, 0);
        analogWrite(A2, 512);
      }

      if (cState == 3) {
        if (ch == 'C')
          cDirect = num;
      }

      if (cState == 1 || cState == 3) {
        if (ch == 'S')
          cSpeed = num;
      }
    }
    Serial.print(ch);
    Serial.println(num);

  }
  switch (cState) {
    case 1:
      freeStyle(cSpeed);
      break;
    case 2:
      cAvoid();
      break;
    case 3:
      carBT(cSpeed);
      break;
    case 4:
      tracer(cSpeed);
      break;
    default:
      break;
  }
}
