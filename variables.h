#include <Servo.h>
byte baseServoCommand,Joint1Command,Joint2Command,ClawCommand,ClawJointCommand;
int BaseArm= 0;
int ForeArm= 0;
int baseLocation[3]={0,0,0},targetLocation[3]={0,0,0};

Servo baseS,joint1s,joint2s,claw;

