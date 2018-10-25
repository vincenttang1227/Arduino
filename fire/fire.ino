int sensorPin=A0;
int buzzerPin=7;
int ledR=8;

void setup() 
{
  pinMode(ledR,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int value=analogRead(sensorPin);
  Serial.println(value);
  delay(300);
  if (value<900)
  {
    digitalWrite(ledR,1);
    digitalWrite(buzzerPin,1);
    delay(250);
    digitalWrite(ledR,0);
    digitalWrite(buzzerPin,0);
    delay(50);
  }
}
