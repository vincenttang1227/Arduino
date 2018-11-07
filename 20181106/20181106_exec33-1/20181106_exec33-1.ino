int ROW[8]={10,11,12,13,A0,A1,A2,A3};
int CEL[8]={2,3,4,5,6,7,8,9};
int XO[8][8]={
{0,1,1,1,1,1,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,1,0},
};
void setup() {
  for(int i=2;i<=18;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(XO[i][j]==1)
      {
        digitalWrite(ROW[i],LOW);
        digitalWrite(CEL[j],HIGH);
        delay(1);
        digitalWrite(CEL[j],LOW);
        digitalWrite(ROW[i],HIGH);
      }
    }
  }
}
