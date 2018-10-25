int ledR=7;
int buzzer1=8;
int sensorPin=A0;
int hValue=150;
int lValue=150;

void setup() {
  pinMode(ledR,OUTPUT);
  pinMode(buzzer1,OUTPUT);
  digitalWrite(ledR,1);
  while(millis()<5000)
  {
    if(analogRead(sensorPin)>hValue)
      hValue=analogRead(sensorPin);
    if(analogRead(sensorPin)<lValue)
      lValue=analogRead(sensorPin);
  }
  digitalWrite(ledR,0);
  Serial.begin(9600);
  Serial.print("HIGH: ");
  Serial.print(hValue);
  Serial.print("    LOW: ");
  Serial.println(lValue);
}

void loop() 
{
  int sensorValue=analogRead(sensorPin);
  int buzzerValue=map(sensorValue,lValue,hValue,40,6000);
  if (sensorValue>hValue || sensorValue <lValue)
    noTone(buzzer1);
  else
  {
    tone(buzzer1,buzzerValue,50);
    delay(60);
    noTone(buzzer1);
  }
}
