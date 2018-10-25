int ledR=7;

void setup() {
  pinMode(ledR,OUTPUT);
}

void loop() {
  digitalWrite(ledR,HIGH);
  delay(1000);
  digitalWrite(ledR,LOW);
  delay(1000);
}
