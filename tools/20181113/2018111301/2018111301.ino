#include <SoftwareSerial.h>
SoftwareSerial mybt(10, 11) ; //10-RX,11-TX
int ledR = 8;
int ledY = 7;
int ledG = 6;
int rState = 0;
int yState = 0;
int gState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  mybt.begin(38400);
  Serial.begin(38400);
  while (!Serial)
  {
    ;
  }
  Serial.println("BlueTooth Start~~");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    mybt.write(Serial.read());
  }
  if (mybt.available() > 0)
  {
    char ch = mybt.read();
    if (ch == '0')
    {
      rState = 0;
    }
    if (ch == '1')
    {
      rState = 1;
    }
    if (ch == '2')
    {
      yState = 1;
    }
    if (ch == '3')
    {
      yState = 0;
    }
    if (ch == '4')
    {
      gState = 1;
    }
    if (ch == '5')
    {
      gState = 0;
    }
    Serial.println(ch);
   
  }

  digitalWrite(ledR, rState);
  digitalWrite(ledY, yState);
  digitalWrite(ledG, gState);

}
