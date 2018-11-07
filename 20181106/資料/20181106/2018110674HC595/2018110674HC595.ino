int data = 9;
int push = 10;
int upload = 11;
int a = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(data, OUTPUT);
  pinMode(push, OUTPUT);
  pinMode(upload, OUTPUT);
}

void ledOn()
{
    digitalWrite(upload,LOW);
    for(int i=0;i<8;i++)
    {
      digitalWrite(push,LOW);
      digitalWrite(data,HIGH);
      digitalWrite(push,HIGH);
      }
     digitalWrite(push,LOW);
     digitalWrite(upload,HIGH);      
}

void ledOff()
{
    digitalWrite(upload,LOW);
    for(int i=0;i<8;i++)
    {
      digitalWrite(push,LOW);
      digitalWrite(data,LOW);
      digitalWrite(push,HIGH);
      }
     digitalWrite(push,LOW);
     digitalWrite(upload,HIGH);      
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(upload, LOW);
  digitalWrite(push, LOW);
  if (a == 0)
  {
    digitalWrite(data, HIGH);
  }
  else
  {
    digitalWrite(data, LOW);
  }
  a++;
  
  if (a == 8)
  {
    a = 0;
    ledOff();
    delay(1000);
    ledOn();
    delay(1000);
  }
  digitalWrite(push, HIGH);
  digitalWrite(push, LOW);
  digitalWrite(upload, HIGH);
  delay(100);
 

  
}
