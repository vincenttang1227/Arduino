#include <SoftwareSerial.h>
SoftwareSerial bt(10, 11);

void setup() {
  bt.begin(38400);
  Serial.begin(38400);
  while (!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start @^_^@");
}

void loop() {
  if (bt.available() > 0)
  {
    //    Serial.println(bt.read());
    int value1 = analogRead(A0);
    int value2 = analogRead(A1);
    value1 = map(value1, 0, 950, 0, 394);
    value2 = map(value2, 0, 450, 0, 500);
    Serial.println(value2);
    if (bt.read() == 'a')
    {
      byte X[5];
      X[0] = 97;
      X[1] = value1 / 256;
      X[2] = value1 % 256;

      X[3] = value2 / 256;
      X[4] = value2 % 256;
      for (int i = 0; i < 5; i++)
      {
        bt.write(X[i]);
        Serial.println(X[i]);
      }
    }
  }
  //  delay(500);
}
