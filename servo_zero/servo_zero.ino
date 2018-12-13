#include <Servo.h>
Servo S1;
int servoPin = 2;

void setup() {
  S1.attach(servoPin);
  S1.write(90);
}

void loop(){
//   for (int i=0;i<=180;i++)
//  {
//    S1.write(i);
//    delay(10);
//  }
//    for (int i=180;i>=0;i--)
//  {
//    S1.write(i);
//    delay(10);
//  }
}
