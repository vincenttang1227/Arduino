#include <SCoop.h>
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
int carState = 0;
float dist;

void setup() {
  mySCoop.start();
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
}

void turnServo(Servo S, int angle) {
  int nowAngle = S.read();
  if (nowAngle > angle) {
    for (int i = nowAngle; i >= angle; i--) {
      S.write(i);
      delay(10);
    }
  }
  else {
    for (int i = nowAngle; i <= angle; i++) {
      S.write(i);
      delay(10);
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
  analogWrite(LmotorGo, pwm);
  delay(cTime);
}

void cBack(int cTime, int pwm) {
  digitalWrite(RmotorGo, LOW);
  digitalWrite(RmotorBk, HIGH);
  digitalWrite(LmotorGo, LOW);
  digitalWrite(LmotorBk, HIGH);
  analogWrite(RmotorBk, pwm);
  analogWrite(LmotorBk, pwm);
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

void freestyle(int cTime, int pwm) {
  for (int i = 0; i < 5; i++) {
    cGo(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
  for (int i = 0; i < 5; i++) {
    cBack(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
  for (int i = 0; i < 5; i++) {
    turnFL(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
  for (int i = 0; i < 5; i++) {
    turnFR(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
  for (int i = 0; i < 5; i++) {
    spinL(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
  for (int i = 0; i < 5; i++) {
    spinR(cTime, pwm);
    delay(cTime);
  }
  cStop(cTime, 0);
}

defineTaskLoop(taskMain)
{
  int cSpeed = 32;
  dist = distance();
  dist = constrain(dist, 0, 80);
  Serial.println(dist);

  if (dist > 25)
    cGo(50, cSpeed * 4);
  else {
    cStop(0, 0);
    turnServo(S1, 0);
    delay(250);
    float rDist = distance();
    rDist = constrain(rDist, 0, 80);
    turnServo(S1, 180);
    delay(250);
    float lDist = distance();
    lDist = constrain(lDist, 0, 80);

    turnServo(S1, 90);
    Serial.print("rDist:");
    Serial.print(rDist);
    Serial.print("  lDist:");
    Serial.println(lDist);

    if (rDist > lDist)
      turnFR(50, cSpeed * 4);
    else
      turnFL(50, cSpeed * 4);
  }
  delay(500);
}

void loop() {
  yield();
}
