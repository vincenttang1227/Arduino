int sensorPin=A0;
int ledR=11;

void setup() 
{
  pinMode(ledR,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int value=analogRead(sensorPin);
  int ledR_value=analogRead(ledR);
  ledR_value=map(value,200,400,0,255);
  ledR_value=constrain(ledR_value,0,255);
  Serial.println(value);
  Serial.println(ledR_value);
//  delay(50);
  analogWrite(ledR,ledR_value);
}
