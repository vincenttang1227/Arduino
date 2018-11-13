#include <SoftwareSerial.h>
SoftwareSerial bt(10,11);
int ledR = 3;
int ledY = 5;
int ledG = 6;
int rNum = 0;
int yNum = 0;
int gNum = 0;


void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  bt.begin(38400);
  Serial.begin(38400);
  while (!Serial)
  {;}
  Serial.println("BlueTooth Start @^_^@");
}

void loop() {
  if (bt.available()>0)
  {
    char ch=bt.read();
    int num=bt.parseInt();
    Serial.println(num);
    if (ch=='R')
      rNum = num;
    if (ch=='Y')
      yNum = num;
    if (ch=='G')
      gNum = num;
  }
  analogWrite(ledR,rNum);
  analogWrite(ledY,yNum);
  analogWrite(ledG,gNum);
}
