#include <Servo.h>
Servo S1,S2;
int servoPin = 2;
int servoPin2=7;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  S1.attach(servoPin);
  S2.attach(servoPin2);
  S1.write(0);
  Serial.begin(9600);
}

void turnServo(Servo s, int angle)
{

  int nowAngle = s.read();
  if (angle > nowAngle)
  {
    for (int i = nowAngle; i <= angle; i++)
    {
      s.write(i);
      delay(100);
    }
  }
  else
  {
    for (int i = nowAngle; i >= angle; i--)
    {
      s.write(i);
      delay(100);
    }
  }
}
void loop() {
  value = analogRead(A0);
  int servoAngle = map(value, 20, 1050, 0, 180);
  //Serial.println(value);
  // S1.write(servoAngle);
  //Serial.println(Serial.available());
  if (Serial.available() > 0)
  {
    // char ch=Serial.read();
    int num = Serial.parseInt();
    int num2=Serial.parseInt();
    //Serial.println(ch);
    // Serial.println(num);
    //S1.write(num);
    turnServo(S1, num);
    turnServo(S2,num2);
    //  Serial.println(S1.read());
  }
}
