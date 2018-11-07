int out1 = 2;
int out2 = 3;
int out3 = 4;
int out4 = 5;
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(out1, INPUT);
  pinMode(out2, INPUT);
  pinMode(out3, INPUT);
  pinMode(out4, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("NO1:");
  Serial.print(digitalRead(out1));
  Serial.print(" NO2:");
  Serial.print(digitalRead(out2));
  Serial.print(" NO3:");
  Serial.print(digitalRead(out3));
  Serial.print(" NO4:");
  Serial.println(digitalRead(out4));
  if (digitalRead(out1) == 1)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }

  if (digitalRead(out2) == 1)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }
    if (digitalRead(out3) == 1)
  {
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW);
  }
    if (digitalRead(out4) == 1)
  {
    digitalWrite(led4, HIGH);
  }
  else
  {
    digitalWrite(led4, LOW);
  }

  delay(1000);
}
