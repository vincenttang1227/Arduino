int data=9;
int push=10;
int upload=11;
int a=0;
void setup() {
  pinMode(data,OUTPUT);
  pinMode(push,OUTPUT);
  pinMode(upload,OUTPUT);
}
void loop() {
  digitalWrite(upload,LOW);
  digitalWrite(push,LOW);
  if(a==0)
  { digitalWrite(data,HIGH);
   }else{digitalWrite(data,LOW);}
  a++;
  if(a==8){ a=0;}
  digitalWrite(push,HIGH);
  digitalWrite(push,LOW);
  digitalWrite(upload,HIGH);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  delay(500);
}
