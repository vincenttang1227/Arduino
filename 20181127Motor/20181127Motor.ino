int motorLeftGo = 2;
int motorLeftBk = 3;
int motorRightGo = 4;
int motorRightBk = 5;
void setup() {
  pinMode(motorLeftGo, OUTPUT);
  pinMode(motorLeftBk, OUTPUT);
  pinMode(motorRightGo, OUTPUT);
  pinMode(motorRightBk, OUTPUT);
}

void loop() {
  digitalWrite(motorLeftGo, HIGH);
  digitalWrite(motorLeftBk, LOW);
  digitalWrite(motorRightGo, HIGH);
  digitalWrite(motorRightBk, LOW);
}
