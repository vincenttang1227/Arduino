#include <Servo.h>
Servo S1;
int servoPin = 7;

#include <SoftwareSerial.h>
SoftwareSerial bt(10, 11);

void setup() {
  bt.begin(38400);
  Serial.begin(38400);
  S1.attach(servoPin);
  while (!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start @^_^@");
  S1.write(90);
}

void loop() {
  if(bt.available()>0)
  {
    char ch=bt.read();
    int angle=bt.parseInt();
    Serial.print(ch);
    Serial.println(angle);
    S1.write(angle);
  }
  
}
