int led1=3;
int sensorPin = A0;
void setup() {
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorvalue=analogRead(sensorPin);
  int ledvalue=map(sensorvalue,0,1023,0,255);
  ledvalue=constrain(ledvalue,0,255);
  analogWrite(led1,ledvalue);
  
  Serial.print("Sensorvalue: ");
  Serial.print(sensorvalue);
  Serial.print("  Ledvalue: ");
  Serial.println(ledvalue);
  //delay(500);
}
