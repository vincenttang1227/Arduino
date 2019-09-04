int data = 9;
int push = 10;
int upload = 11;
int value[8];

void setup()  {
  pinMode(data, OUTPUT);
  pinMode(push, OUTPUT);
  pinMode(upload, OUTPUT);
}

void pled()
{
  digitalWrite(upload, LOW);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(push, LOW);
    digitalWrite(data, value[i]);
    digitalWrite(push, HIGH);
  }
  digitalWrite(upload, HIGH);
}
void loop()
{
  for (int i = 0; i < 8; i++)
  {
    value[i] = 1;
    pled();
    delay(150);
    value[i] = 0;
  }
}
