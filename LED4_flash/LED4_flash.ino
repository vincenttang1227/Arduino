//從pin2開始，共宣告6個腳位
int pin = 2;
int num = 6;

void setup() {
  // put your setup code here, to run once:
  for (int i = pin; i < pin + num; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //從右至左全亮
  for (int i = pin; i < pin + num; i++)
  {
    digitalWrite(i, HIGH);
    delay(50);
  }
  delay(500);

  for (int i = 0; i < 3; i++)
  {
    for (int i = pin + num - 1; i >= pin; i--)
      digitalWrite(i, LOW);
    delay(500);
    for (int i = pin; i < pin + num; i++)
      digitalWrite(i, HIGH);
    delay(500);
  }
  //從左至右全暗
  for (int i = pin + num - 1; i >= pin; i--)
  {
    digitalWrite(i, LOW);
    delay(50);
  }
  delay(500);
  for (int i = 0; i < 3; i++)
  {
    for (int i = pin; i < pin + num; i++)
      digitalWrite(i, HIGH);
    delay(500);
    for (int i = pin + num - 1; i >= pin; i--)
      digitalWrite(i, LOW);
    delay(500);

  }
}
