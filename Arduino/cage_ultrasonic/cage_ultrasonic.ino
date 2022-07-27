#include <Servo.h>

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

#define ultrasonic_trig 10
#define ultrasonic_echo 3

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // 當前角度
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // 之前角度
int distance;
bool flag = 0;

float ultrasonic_distance();


void setup() {
   pinMode(ultrasonic_trig, OUTPUT);
   pinMode(ultrasonic_echo, INPUT);

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
   distance = ultrasonic_distance();
   delay(20);
   if (distance <= 10) {
      if (flag == 0) {
         servo3.write(30);
         delay(100);
         servo4.write(30);
         flag = 1;
      }
      else{
         servo3.write(120);
         delay(100);
         servo4.write(120);
         flag = 0;
      }
      delay(1000);
   }

}

float ultrasonic_distance() {
   long duration, distance_cm;
   digitalWrite(ultrasonic_trig, LOW);
   delayMicroseconds(2);
   digitalWrite(ultrasonic_trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(ultrasonic_trig, LOW);
   duration = pulseIn(ultrasonic_echo, HIGH);
   distance_cm = (duration / 2) / 29.1;
   return distance_cm;
}
