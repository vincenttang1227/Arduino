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
  if (bt.available()>0)
  {
    String str=bt.readString();
    bt.print(str);
//    bt.print(str.toInt()); 只讀數字
    Serial.println(str);
  }
}
