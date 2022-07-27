#include "Servo.h"

/* 每個舵機類別(class)宣告 */
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

/* 各伺服舵機腳位、最大角度、最小角度與初始角度設定 */
#define sevo1_pin 5
#define servo1_angle_min 0
#define servo1_angle_max 180
#define servo1_angle_init 30

#define sevo2_pin 6
#define servo2_angle_min 0
#define servo2_angle_max 180
#define servo2_angle_init 180

#define sevo3_pin 9
#define servo3_angle_min 0
#define servo3_angle_max 180
#define servo3_angle_init 180

#define sevo4_pin 11
#define servo4_angle_min 0
#define servo4_angle_max 180
#define servo4_angle_init 90

/* 每個舵機目前角度變數宣告，預設為初始化的角度*/
unsigned short servo1_angle = servo1_angle_init;
unsigned short servo2_angle = servo2_angle_init;
unsigned short servo3_angle = servo3_angle_init;
unsigned short servo4_angle = servo4_angle_init;

#define echoPin 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 10 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

char c;  // 接收藍芽字串用變數
bool flag = 0;

float ultrasonic_distance_10_3();

void setup()
{
   Serial.begin(9600);  // UART0串口初始化

   servo1.attach(sevo1_pin); //初始化舵機1腳位為D5
   servo2.attach(sevo2_pin); //初始化舵機2腳位為D6
   servo3.attach(sevo3_pin); //初始化舵機3腳位為D9
   servo4.attach(sevo4_pin); //初始化舵機4腳位為D11

   servo1.write(servo1_angle);     //初始化舵機1角度
   servo2.write(servo2_angle);    //初始化舵機2角度
   servo3.write(servo3_angle);      //初始化舵機3角度
   servo4.write(servo4_angle);      //初始化舵機4角度

   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop()
{
   if (ultrasonic_distance_10_3() <= 10) {
      flag = !flag;
      if (flag) {
         servo2.write(180);
         delay(100);
         servo3.write(180);
         delay(1000);
      }
      else {
         servo2.write(0);
         delay(100);
         servo3.write(0);
         delay(1000);
      }
   }
}

float ultrasonic_distance_10_3() {
   digitalWrite(10, LOW);
   digitalWrite(3, LOW);
   delayMicroseconds(5);
   digitalWrite(10, HIGH);
   delayMicroseconds(10);
   digitalWrite(10, LOW);
   unsigned long sonic_duration = pulseIn(3, HIGH);
   float distance_cm = (sonic_duration / 2.0) / 29.1;
   return distance_cm;
}
