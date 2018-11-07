int data = 9;
int push = 10;
int upload = 11;
int a[8];

void setup() {
  // put your setup code here, to run once:
  pinMode(data, OUTPUT);
  pinMode(push, OUTPUT);
  pinMode(upload, OUTPUT);
}

void pLed()
{
  digitalWrite(upload, LOW);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(push,LOW);
    digitalWrite(data,a[i]);
    digitalWrite(push,HIGH);
  }
  digitalWrite(push,LOW);
  digitalWrite(upload,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<8;i++)
  {
    a[i]=1;
    pLed();
    delay(100);
    }
   for(int i=0;i<8;i++)
   {
    a[i]=0;
    pLed();
    delay(100);
    }
   for(int i=7;i>=0;i--)
   {
    a[i]=1;
    pLed();
    delay(100);
    }
}
