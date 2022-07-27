#include "Servo.h"

/* 每個舵機類別(class)宣告 */
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

/* 各伺服舵機腳位 */
#define sevo1_pin 5
#define sevo2_pin 6
#define sevo3_pin 9
#define sevo4_pin 11

void setup()
{
   servo1.attach(sevo1_pin); //初始化舵機1腳位為D5
   servo2.attach(sevo2_pin); //初始化舵機2腳位為D6
   servo3.attach(sevo3_pin); //初始化舵機3腳位為D9
   servo4.attach(sevo4_pin); //初始化舵機4腳位為D11
}

void loop()
{
   servo3.write(0);
   delay(100);
   servo4.write(0);
   delay(5000);
   servo3.write(180);
   delay(100);
   servo4.write(180);
   delay(5000);
}
