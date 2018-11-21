#include <SoftwareSerial.h>
SoftwareSerial bt(10,11);

void setup() {
  bt.begin(38400);
  Serial.begin(38400);
  while(!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start @^_^@");
}

void loop() {
  int value=analogRead(A0);
  Serial.println(value);
  byte b[2];
  b[0]=value/256;
  b[1]=value%256;
  for (int i=0;i<2;i++)
  {
    bt.write(b[i]);
//    Serial.println(b[i]);
  }
  delay(250);
  }
