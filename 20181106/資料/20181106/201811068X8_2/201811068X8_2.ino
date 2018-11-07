void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 18; i++)
  {
    pinMode(i, OUTPUT);
  }

}
int x[8][8]={
  {1,0,0,0,0,0,0,1}.
  {0,1,0,0,0,0,1,0}.
  {0,0,1,0,0,1,0,0}.
  {0,0,0,1,1,0,0,0}.
  {0,0,0,1,1,0,0,0}.
  {0,0,1,0,0,1,0,0}.
  {0,0,0,0,0,0,1,0}.
  {0,0,0,0,0,0,0,1}.
};
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i < 10; i++)
  {
    digitalWrite(i, LOW);
  }
  for(int i=10;i<18;i++)
  {
    digitalWrite(i,HIGH);
    }
  digitalWrite(12,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  
}
