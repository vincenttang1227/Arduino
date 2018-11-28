#include <SoftwareSerial.h>
#include <dht.h>
dht myDht;
int dhtPin = 2;
SoftwareSerial bt(10, 11);

void setup() {
  pinMode (dhtPin, INPUT);
  bt.begin(38400);
  Serial.begin(38400);
  while (!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start @^_^@");
}

void loop() {
  myDht.read11(dhtPin);
  int Temp = myDht.temperature;
  int Humi = myDht.humidity;

  Serial.print(Temp);
  Serial.print(" ");
  Serial.println(Humi);
  if (bt.read() == 'a')
  {
    byte X[3];
    X[0] = 97;
    X[1] = Temp;
    X[2] = Humi;
    for (i = 0; i < 3; i++)
    {
      bt.write(X[i];
    }
  }
  delay(250);
}
