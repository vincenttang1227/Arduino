int out1=2;
int out2=3;
int out3=4;
int out4=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(out1,INPUT);
  pinMode(out2,INPUT);
  pinMode(out3,INPUT);
  pinMode(out4,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print("NO1:");
   Serial.print(digitalRead(out1));
   Serial.print(" NO2:");
   Serial.print(digitalRead(out2));
   Serial.print(" NO3:");
   Serial.print(digitalRead(out3));
   Serial.print(" NO4:");
   Serial.println(digitalRead(out4));
   delay(1000);
}
