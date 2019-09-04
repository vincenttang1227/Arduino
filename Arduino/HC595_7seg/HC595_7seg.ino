int data = 9;
int push = 10;
int upload = 11;
int num;

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
    digitalWrite(data, X[num][i]);
    digitalWrite(push, HIGH);
  }
  digitalWrite(upload, HIGH);
}

void loop()
{
  if (Serial.available() > 0)
  {
    num = Serial.parseInt();
    num = constrain(num, 0, 9);
  }
  pled();
  delay(1000);
}
