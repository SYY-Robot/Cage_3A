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

#define ultrasonic_pin1 3
#define ultrasonic_pin2 10

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // 當前角度
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // 之前角度
int distance;
bool flag = 0;

float ultrasonic_distance_9_10();


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

   pinMode(ultrasonic_pin1, OUTPUT);
   pinMode(ultrasonic_pin2, INPUT);
}

void loop() {
   distance = ultrasonic_distance_9_10();
   delay(20);
   if (distance >= 10) {
      if (flag == 0) {
         servo3.write(0);
         delay(100);
         servo4.write(0);
         flag = 1;
      }
      else{
         servo3.write(180);
         delay(100);
         servo4.write(180);
         flag = 0;
      }
      delay(1000);
   }

}

float ultrasonic_distance_9_10() {
   digitalWrite(3, LOW);
   digitalWrite(10, LOW);
   delayMicroseconds(5);
   digitalWrite(3, HIGH);
   delayMicroseconds(10);
   digitalWrite(3, LOW);
   unsigned long sonic_duration = pulseIn(10, HIGH);
   float distance_cm = (sonic_duration / 2.0) / 29.1;
   return distance_cm;
}