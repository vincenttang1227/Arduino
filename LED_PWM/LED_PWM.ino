int led1=3;
int num=15;
void setup() {
  pinMode(led1,OUTPUT);

}

void loop() {
  for(int i=0;i<=255;i+=num)
  {
    analogWrite(led1,i);
    delay(50);
    }
  for(int i=255;i>=0;i-=num)
  {
    analogWrite(led1,i);
    delay(50);
    }
    delay(500);
}
