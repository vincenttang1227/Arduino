#include <Servo.h>
Servo S1;
int servoPin=2;

void setup() {
  // put your setup code here, to run once:
  S1.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int value=analogRead(A0);
   Serial.println(value);
   int servoAngle=map(value,100,300,0,180);
   S1.write(servoAngle);
   delay(1000);
}
