#include <Servo.h>

uint8_t baseServoCommand=0,Joint1Command=0,Joint2Command=0,ClawCommand=0;

Servo baseS,joint1s,joint2s,claw;


void setup() {
  
}

void loop() {
  
  ////////////////////////
  ///// Input Sensors/////
  ////////////////////////
    
  
  /////////////////////////
  ///// Base Servo ////////
  /////////////////////////

  switch(baseServoCommand){
    case 0: //Stay still

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Release power

    default;
      break;
  }

  /////////////////////////
  ////// Joint 1 /////////
  /////////////////////////
  switch(Joint1Command){
    case 0: //Stay still

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Release power

    default;
      break;
  }


  /////////////////////////
  ////// Joint 2 /////////
  /////////////////////////
  switch(Joint2Command){
    case 0: //Stay still

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Release power

    default;
      break;
  }

  ////////////////////////
  ////// Claw ///////////
  ////////////////////////
  switch(ClawCommand){
    case 0: //Stay still

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Release power

    default;
      break;
  }
  
}
