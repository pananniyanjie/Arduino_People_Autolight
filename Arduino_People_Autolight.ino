#include "Arduino.h"
/*
本代码由黑联科技开源
禁止用于非法用途
*/
int scra = 0;
int waittime = 0;

void setup(){
  int scra = 0;
  int waittime = 25;//这里改时间
  pinMode(9,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}
void loop(){
      if(digitalRead(3) == 1){
       delay(300);
       if(digitalRead(3) == 1 ){
        for(;scra<=254;scra++){
          delay(waittime);
          Serial.println(scra);
          analogWrite(9,scra);
            if( scra >= 253 ){
               Serial.println("+饱和停止");
               scra = 255;
               analogWrite(9,scra);
            }
          }
        }
      }
      if(digitalRead(3) == 0){
       delay(300);
       if(digitalRead(3) == 0){
        for(;scra>0;scra--){
        delay(waittime);
        Serial.println(scra);
        analogWrite(9,scra);
         if( scra <= 2 ){
          Serial.println("-饱和停止");
          scra = 0;
          analogWrite(9,scra);
         }
       }  
     }
   }
 
}
