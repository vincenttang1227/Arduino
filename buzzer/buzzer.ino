int playPin = 8;
// 依樂譜的順序，填入代表的音符，空白代表休止符
char notes[] = "ccggaagffeeddc ";

// 決定每個音階的拍子，用 unsigned long 所以拍子只能是正整數
unsigned long beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4}; 

// 利用 sizeof()，算出總共要多少音符
int length = sizeof(notes); 

// 決定一拍的長度，這邊一拍 200 毫秒越大會播放越慢
int wait = 400;

void setup() {
  pinMode(playPin, OUTPUT);
}

void loop() {
  // 利用 for 來播放我們設定的歌曲，一個音一個音撥放

  for (int i = 0; i < length; i++) {
 // 如果是空白的話，不撥放音樂
    if (notes[i] == ' ') {
      delay(beats[i] * wait); // rest
    } else {

  // 呼叫 palySound() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
      playSound(playPin,notes[i], beats[i] * wait);
    } 

    // 每個音符之間的間隔，這邊設定的長短會有連音或斷音的效果
    delay(wait/10); 
  }

}

void playSound(int OutputPin, char note, unsigned long duration) {
   // 音符字元與對應的頻率由兩個矩陣表示
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 };

  // 播放音符對應的頻率
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin,tones[i], duration);
  //下方的 delay() 及 noTone ()，因為Buzzer在播放音樂是有時間長度所以如果不停止等待會重覆播放
      delay(duration);
      noTone(OutputPin);
    }
  }
}
