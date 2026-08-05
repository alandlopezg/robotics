#include "VarSpeedServo.h"  //include VarSpeedServo library

VarSpeedServo RU;  //Right Upper
VarSpeedServo RL;  //Right Lower
VarSpeedServo LU;  //Left Upper
VarSpeedServo LL;  //Left Lower

const int vel = 30;
const int array_cal[4] = {81,80,90,92};   // Define the angular adjustment of servo (RU, RL, LU, LL )




const int num_dance = 8;
const int array_dance[num_dance][4] =
{ 
    {0,-40,0,40},    //In place to rise and fall
    {20,-40,-20,40},   
    {20,-20,-20,20},
    {20,0,-20,0},   
    {-20,-10,20,10},
    {-10,-30,10,30},
    {0,-40,0,40},
    {0,0,0,0},
};





void Servo_Init()
{
    RU.attach(3);   // Connect the signal wire of the upper-right servo to pin 3
    RL.attach(5);   // Connect the signal wire of the lower-right servo to pin 5 
    LU.attach(6);   // Connect the signal wire of the upper-left  servo to pin 6 
    LL.attach(9);   // Connect the signal wire of the lower-left  servo to pin 9 

    RU.slowmove (array_cal[0] , vel);  // Define the angle and speed of the upper-right servo.
    RL.slowmove (array_cal[1] , vel);
    LU.slowmove (array_cal[2] , vel);
    LL.slowmove (array_cal[3] , vel);
    delay(2000);
}

void setup()  
{
    Servo_Init();  
}

void loop() 
{ 
  In_place();
}







void In_place()
{ int vel_Dance=40;  
  for(int x = 0; x < 3; x++) {
        for(int z=0; z<6; z++) {                     
            RU.slowmove (array_cal[0] + array_dance[z][0] , vel_Dance);   
            RL.slowmove (array_cal[1] + array_dance[z][1] , vel_Dance);
            LU.slowmove (array_cal[2] + array_dance[z][2] , vel_Dance);
            LL.slowmove (array_cal[3] + array_dance[z][3] , vel_Dance);
            delay(300); 
        } 
    }

     for(int z=6; z<8; z++) {                     
            RU.slowmove (array_cal[0] + array_dance[z][0] , 30);   
            RL.slowmove (array_cal[1] + array_dance[z][1] , 30);
            LU.slowmove (array_cal[2] + array_dance[z][2] , 30);
            LL.slowmove (array_cal[3] + array_dance[z][3] , 30);
            delay(550); 
        } 
  }
