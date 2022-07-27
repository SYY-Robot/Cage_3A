#include <Arduino.h>
#include "Servo.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

#define sevo1_pin 5
#define servo1_angle_min 0
#define servo1_angle_max 180
#define servo1_angle_init 90

#define sevo2_pin 6
#define servo2_angle_min 0
#define servo2_angle_max 180
#define servo2_angle_init 90

#define sevo3_pin 9
#define servo3_angle_min 0
#define servo3_angle_max 180
#define servo3_angle_init 90

#define sevo4_pin 11
#define servo4_angle_min 0
#define servo4_angle_max 180
#define servo4_angle_init 90

#define sevo5_pin A1
#define servo5_angle_min 0
#define servo5_angle_max 180
#define servo5_angle_init 90

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // 當前角度
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // 之前角度
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // 用於儲存位置/角度
String data = "";

void setup() {

   Serial.begin(9600);
   servo1.attach(sevo1_pin);
   servo2.attach(sevo2_pin);
   servo3.attach(sevo3_pin);
   servo4.attach(sevo4_pin);
   servo5.attach(sevo5_pin);

   delay(20);

   servo1PPos = servo1_angle_init;
   servo1.write(servo1PPos);
   servo2PPos = servo2_angle_init;
   servo2.write(servo2PPos);
   servo3PPos = servo3_angle_init;
   servo3.write(servo3PPos);
   servo4PPos = servo4_angle_init;
   servo4.write(servo4PPos);
   servo5PPos = servo5_angle_init;
   servo5.write(servo5PPos);
}

void loop() {
   if(Serial.available() > 0){
      data = Serial.readString();

      if(data.startsWith("Q")){
         String dataS = data.substring(1, data.length());
         servo1Pos = dataS.toInt();

         if(servo1PPos > servo1Pos) {
            for(int j = servo1PPos; j >= servo1Pos; j--) {
               servo1.write(j);
               delay(10);
            }
         }

         else if(servo1PPos < servo1Pos) {
            for (int j = servo1PPos; j<= servo1Pos; j++) {
               servo1.write(j);
               delay(10);
            }
         }
         servo1PPos = servo1Pos;
      }

      if(data.startsWith("A")){
         String dataS = data.substring(1, data.length());
         servo2Pos = dataS.toInt();

         if(servo2PPos > servo2Pos) {
            for(int j = servo2PPos; j >= servo2Pos; j--) {
               servo2.write(j);
               delay(10);
            }
         }

         else if(servo2PPos < servo2Pos) {
            for (int j = servo2PPos; j<= servo2Pos; j++) {
               servo2.write(j);
               delay(10);
            }
         }
         servo2PPos = servo2Pos;
      }

      if(data.startsWith("Z")){
         String dataS = data.substring(1, data.length());
         servo3Pos = dataS.toInt();

         if(servo3PPos > servo3Pos) {
            for(int j = servo3PPos; j >= servo3Pos; j--) {
               servo3.write(j);
               delay(10);
            }
         }

         else if(servo3PPos < servo3Pos) {
            for (int j = servo3PPos; j<= servo3Pos; j++) {
               servo3.write(j);
               delay(10);
            }
         }
         servo3PPos = servo3Pos;
      }
      
      if(data.startsWith("W")){
         String dataS = data.substring(1, data.length());
         servo4Pos = dataS.toInt();

         if(servo4PPos > servo4Pos) {
            for(int j = servo4PPos; j >= servo4Pos; j--) {
               servo4.write(j);
               delay(10);
            }
         }

         else if(servo4PPos < servo4Pos) {
            for (int j = servo4PPos; j<= servo4Pos; j++) {
               servo4.write(j);
               delay(10);
            }
         }
         servo4PPos = servo4Pos;
      }

      if(data.startsWith("S")){
         String dataS = data.substring(1, data.length());
         servo5Pos = dataS.toInt();

         if(servo5PPos > servo5Pos) {
            for(int j = servo5PPos; j >= servo5Pos; j--) {
               servo5.write(j);
               delay(10);
            }
         }

         else if(servo5PPos < servo5Pos) {
            for (int j = servo5PPos; j<= servo5Pos; j++) {
               servo5.write(j);
               delay(10);
            }
         }
         servo5PPos = servo5Pos;
      }
   }
}
