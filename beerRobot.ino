#include "variables.h"
#include <math.h>
#include <SpeedTrig.h>

void initVariables(){
  baseServoCommand=0;
  Joint1Command=0;
  Joint2Command=0;
  ClawCommand=0;
}

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
    case 0: //Release power

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Stay still

    default:
      break;
  }

  /////////////////////////
  ////// Joint 1 /////////
  /////////////////////////
  switch(Joint1Command){
    case 0: //Release power

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Stay still

    default:
      break;
  }


  /////////////////////////
  ////// Joint 2 /////////
  /////////////////////////
  switch(Joint2Command){
    case 0: //Release power

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Stay still

    default:
      break;
  }

  ///////////////////////
  /////Claw Joint////////
  ///////////////////////
  switch(ClawJointCommand){
    case 0: //Release power

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Stay still
    
    default:
      break;
  }
  
  
  ////////////////////////
  ////// Claw ///////////
  ////////////////////////
  switch(ClawCommand){
    case 0: //Release power

      break;
    case 1:// Rotate Forward

      break;
    case 2: // Rotate Backwards

      break;
    case 3: //Stay still

    default:
      break;
  }
  
}

int toDegrees(double rad){
  return floor(rad*180/3.14159265);
}

double calculateB(int L){
  return acos((pow(BaseArm,2)+pow(ForeArm,2)-pow(L,2))/(2*BaseArm*ForeArm));
}
double calculateA(int L){
  return acos((pow(BaseArm,2)+pow(L,2)-pow(ForeArm,2))/(2*BaseArm*L));
}

double calculateL(int desiredTarget[3]){
  double Lx,Ly;
  Lx=hypot(baseLocation[0],desiredTarget[0]);
  Ly=hypot(baseLocation[1],desiredTarget[1]);
  Lx=sqrt(pow(Lx,2)+pow(Ly,2));
  Ly=baseLocation[2]-desiredTarget[2];
  return sqrt(pow(Lx,2)+pow(Ly,2));
}
double calculateAlfa(int L,int Lz){
  return asin(Lz/L);
}

