#include <SoftwareSerial.h>
SoftwareSerial myBt(10, 11); //10--Arduino的RX,11--Arduino的TX

int ledR = 5;
int ledY = 6;
int ledG = 7;
int rState = 0;
int yState = 0;
int gState = 0;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  myBt.begin(38400);
  Serial.begin(38400);
  //等待藍芽開機完成
  while (!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start @^_^@");
}

void loop() {
  if (Serial.available() > 0)
    myBt.write(Serial.read());
  if (myBt.available() > 0)
  {
    char ch = myBt.read();
    if (ch=='2')
      rState=1;
    if (ch=='3')
      rState=0;
      
    if (ch=='4')
      yState=1;
    if (ch=='5')
      yState=0;
      
    if (ch=='6')
      gState=1;
    if (ch=='7')
      gState=0;
    Serial.println(Serial.read());
  }
  digitalWrite(ledR, rState);
  digitalWrite(ledY, yState);
  digitalWrite(ledG, gState);
}
