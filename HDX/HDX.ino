int hdxPin=2;
int buzzerPin=7;
int ledR=8;

void setup() 
{
  pinMode(hdxPin,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int value=digitalRead(hdxPin);
  Serial.println(value);
  delay(250);
  if (value==1)
  {
    digitalWrite(ledR,1);
    digitalWrite(buzzerPin,1);
    delay(500);
    digitalWrite(ledR,0);
    digitalWrite(buzzerPin,0);
    delay(50);
  }
}
