#include <Servo.h>
Servo S1;
int servoPin = 2;
int numMod[] = {4, 5, 6, 7};
int led[] = {8, 9, 10, 11};
int buzzer = 12;

void setup() {
  S1.attach(servoPin);
  S1.write(0);
  
  for (int i = 0; i < 4; i++) {
    pinMode(numMod[i], INPUT);
    pinMode(led[i], OUTPUT);
  }
  Serial.begin(9600);
}

void turnServo(Servo s, int angle) {
  int nowAngle = s.read();
  Serial.println(angle);
  if (angle > nowAngle) {
    for (int i = nowAngle; i <= angle; i++) {
      s.write(i);
      delay(25);
    }
  }
  else {
    for (int i = nowAngle; i >= angle; i--) {
      s.write(i);
      delay(25);
    }
  }
}
void loop() {
  //數字模組控制+LED+Buzzer
  for (int i = 0; i < 4; i++) {
    if (digitalRead(numMod[i]) == 1) {
      digitalWrite(led[i], 1);
      tone(buzzer, 200 * (i + 1), 50);
      S1.write(60 * i);
    }
    else {
      digitalWrite(led[i], 0);
    }
  }

  /*  //(可變、光敏)電阻控制
      int value=analogRead(A0);
      int angle= map(value,100,300,0,180);
      angle=constrain(angle,0,180);
      Serial.print("Value: ");
      Serial.println(value);
      Serial.print("Angle: ");
      Serial.println(angle);
      S1.write(angle);
  */
  /*  //輸入控制
    if (Serial.available() > 0) {
      //    char ch = Serial.read();
      int num = Serial.parseInt();
      num = constrain(num, 0, 180);
      turnServo(S1, num);
      //    S1.write(num);
    }
  */
}
