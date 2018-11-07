#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Debug.h>
#include <MFRC522Extended.h>
#include <MFRC522Hack.h>
#include <require_cpp11.h>
MFRC522 mfrc522;
void setup() {
  Serial.print("Card UID:");
  String str="";
  for(byte i=0;i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i]<0x10? "0":"");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    str.concat(String(mfrc522.uid.uidByte[i]<0x10? "0":""));
    str.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
