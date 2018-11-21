#include <SoftwareSerial.h>
SoftwareSerial bt(10,11);
int trigPin=7;
int echoPin=8;

void setup() {
  bt.begin(38400);
  Serial.begin(38400);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  while(!Serial)
  { ; }
  Serial.println("BlueTooth Start @^_^@");
}
float dist()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  return pulseIn(echoPin,HIGH)/58.8;
}
void loop() {
//  Serial.println(dist());
  int value=int(dist()*100);
  Serial.println(value);
  byte x[2];
  x[0]=value/256;
  x[1]=value%256;
  for (int i=0;i<2;i++)
  {
    bt.write(x[i]);
  }
  delay(500);
}
