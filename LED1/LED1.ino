int ledR = 7;

void setup() {
  pinMode(ledR, OUTPUT);
}

void loop() 
{
    digitalWrite(ledR, HIGH);
    delay(150);
    digitalWrite(ledR, LOW);
    delay(100);
}
