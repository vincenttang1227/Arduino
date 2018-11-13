#define sensorPin 7

int ledR = 8;
int buzzer=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(sensorPin);
  Serial.println(value);
  if (value == 0)
  {
    digitalWrite(ledR, HIGH);
    tone(buzzer,512);
  }
  else
  {
    digitalWrite(ledR, LOW);
    noTone(buzzer);
  }
}
