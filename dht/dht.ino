#include <dht.h>
  dht dht1;
int sensorPin = 2;
int ledG = 8;
int ledR = 9;
void setup() {
  Serial.begin(9600);
  pinMode(ledG,OUTPUT);
  pinMode(ledR,OUTPUT);
}

void loop() {
  int ret = dht1.read11(sensorPin);
  int hum = dht1.humidity;
  int tem = dht1.temperature;
  if(hum >= 70 && hum<=80)
  {
    digitalWrite(ledG,1);
    digitalWrite(ledR,0);
  }
  else
  {
    digitalWrite(ledR,1);
    digitalWrite(ledG,0);
  }
  Serial.print("TEMP: ");
  Serial.print(tem);
  Serial.print("  HUMI: ");
  Serial.println(hum);

  delay(500);
}
