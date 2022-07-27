#include "Servo.h"

/* 舵機類別(class)宣告 */
Servo servo1;


/* 服舵機腳位 */
#define sevo1_pin A1

void setup()
{
   servo1.attach(sevo1_pin); //初始化舵機1腳位為D5
}

void loop()
{
   servo1.write(90);
   delay(1000);
   servo1.write(60);
   delay(1000);
   servo1.write(30);
   delay(1000);
   servo1.write(60);
   delay(1000);

}
