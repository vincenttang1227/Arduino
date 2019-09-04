int num = 0;
int X[10][8] =
{
  {0, 0, 0, 0, 0, 0, 1, 0},    //0
  {1, 0, 0, 1, 1, 1, 1, 0},    //1
  {0, 0, 1, 0, 0, 1, 0, 0},    //2
  {0, 0, 0, 0, 1, 1, 0, 0},    //3
  {1, 0, 0, 1, 1, 0, 0, 0},    //4
  {0, 1, 0, 0, 1, 0, 0, 0},    //5
  {0, 1, 0, 0, 0, 0, 0, 0},    //6
  {0, 0, 0, 1, 1, 1, 1, 0},    //7
  {0, 0, 0, 0, 0, 0, 0, 0},    //8
  {0, 0, 0, 0, 1, 0, 0, 0}     //9
};

void setup()
{
  Serial.begin(9600);
  for (int i = 2; i < 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    num = Serial.parseInt();
    num = constrain(num, 0, 9);
  }
  for (int i = 2; i < 10; i++)
  {
    digitalWrite(i, X[num][i - 2]);
  }
  delay(1000);
}
