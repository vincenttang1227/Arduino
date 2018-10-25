// 錯誤
int buttonR = 2;
int ledR = 3;
int stateR = 0;
// unsigned ->沒有正負符號，定義lastTime為最後觸發時間
unsigned long lastTime=0;

void setup() {
  pinMode(buttonR, INPUT);
  pinMode(ledR, OUTPUT);
//  Serial.begin(9600);
}

void loop() {
  int buttonRvalue = digitalRead(buttonR);
  int ledRvalue = digitalRead(ledR);
  //  Serial.println(value);
  // delay(500);
  /* 按下Button，Led亮；放開Button，Led暗
       if (value==1)
        digitalWrite(led1,1);
      else
        digitalWrite(led1,0);
  */
// 開關寫法 
//millis() --> 系統啟動後執行的時間(會一直增加)
  if (buttonRvalue == 1 && millis()-lastTime>500)
      digitalWrite(ledR,!ledRvalue);
  lastTime=millis();
    
/* 開關變數寫法
  if (value == 1 && millis()-lastTime>1000)
  { 
    if (state == 0)
      state = 1;
    else
      state = 0;
    lastTime=millis();
  }
  digitalWrite(led1, state);
*/
}
