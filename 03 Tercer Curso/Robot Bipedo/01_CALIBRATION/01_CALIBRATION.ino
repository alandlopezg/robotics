#include "VarSpeedServo.h"  //include VarSpeedServo library

VarSpeedServo RU;  //Right Upper
VarSpeedServo RL;  //Right Lower
VarSpeedServo LU;  //Left Upper
VarSpeedServo LL;  //Left Lower

const int vel = 30;
const int array_cal[4] = {81,80,90,92};   // Define the angular adjustment of servo (RU, RL, LU, LL )


void Servo_Init()
{
    RU.attach(3);   // Connect the signal wire of the upper-right servo to pin 3
    RL.attach(5);   // Connect the signal wire of the lower-right servo to pin 5 
    LU.attach(6);   // Connect the signal wire of the upper-left  servo to pin 6 
    LL.attach(9);   // Connect the signal wire of the lower-left  servo to pin 9 
}

void setup()  
{
    Servo_Init();  
}

void loop() 
{ 
    RU.slowmove (array_cal[0] , vel);  // Define the angle and speed of the upper-right servo.
    RL.slowmove (array_cal[1] , vel);
    LU.slowmove (array_cal[2] , vel);
    LL.slowmove (array_cal[3] , vel);
    delay(2000);
}
