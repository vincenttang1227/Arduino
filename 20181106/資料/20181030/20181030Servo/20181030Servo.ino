#include <Servo.h>
Servo S1;
int servoPin = 2;

void setup() {
  // put your setup code here, to run once:
  S1.attach(servoPin);
  S1.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 180; i++)
  {
    S1.write(i);
    delay(100);
  }
  for (int i = 180; i >= 0; i--)
  {
    S1.write(i);
    delay(100);
  }
}
