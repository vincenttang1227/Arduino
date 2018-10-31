int numMod[] = {4, 5, 6, 7};
int led[] = {8, 9, 10, 11};
int buzzer = 12;
int i;

void setup() {
  for (i = 0; i < 4; i++) {
    pinMode(numMod[i], INPUT);
    pinMode(led[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (i = 0; i < 4; i++) {
    if (digitalRead(numMod[i]) == 1) {
      digitalWrite(led[i], 1);
      tone(buzzer, 200 * (i + 1), 5);
    }
    else {
      digitalWrite(led[i], 0);
    }
  }
}
