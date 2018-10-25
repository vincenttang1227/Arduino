//////Button
int buttonR = 2;
int buttonG = 8;
int ledR = 3;
int ledG = 9;
int StateR = 0;
int StateG = 0;
unsigned long lastTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonR, INPUT);
  pinMode(buttonG, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if (millis() - lastTime > 500){
    if (digitalRead(buttonR) == 1)
      if (StateG == 0)
        if (StateR == 0)
          StateR = 1;
        else
          StateR = 0;

    if (digitalRead(buttonG) == 1)
      if (StateR == 0)
        if (StateG == 0)
          StateG = 1;
        else
          StateG = 0;
          
    digitalWrite(ledR,StateR);
    digitalWrite(ledG,StateG);
    lastTime = millis();
  }
}
