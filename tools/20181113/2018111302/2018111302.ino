#include <SoftwareSerial.h>
SoftwareSerial bt(10, 11);
int ledR = 3; //PWM
int ledY = 5; //PWM
int ledG = 6; //PWM
int rNum = 0;
int yNum = 0;
int gNum = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  bt.begin(38400);
  Serial.begin(38400);
  while (!Serial)
  {
    ;
  }
  Serial.println("Bluetooth Start~~");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bt.available() > 0)
  {
    char ch = bt.read();
    int num = bt.parseInt();
    Serial.print(ch);
    Serial.println(num);
    if (ch == 'R')
    {
      rNum = num;
    }
    if (ch == 'Y')
    {
      yNum = num;
    }
    if (ch == 'G')
    {
      gNum = num;
    }

  }
  analogWrite(ledR,rNum);
  analogWrite(ledY,yNum);
  analogWrite(ledG,gNum);
}
