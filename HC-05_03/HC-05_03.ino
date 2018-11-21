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
    char ch=bt.read();
    Serial.println(ch);
    if (ch=='1')
    {
      bt.write("Hello World!!");
    }
    if (ch=='2')
    {
      bt.write("大家好~~");
    }
    if (ch=='3')
    {
      bt.write("Test Message");
    }
    if (ch=='4')
    {
      bt.write("BT On");
    }
  }

}
