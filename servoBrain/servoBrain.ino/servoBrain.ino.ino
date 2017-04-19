#include <Servo.h>
#define CLAWPIN 8
#define S1PIN 9
#define S2PIN 10 
#define S3PIN 3

#define clawClosed 

#define S3stopSpeed 80
#define S2stopSpeed 80
#define S1stopSpeed 83

#define s3rightMax 94
#define s3leftMax 90
#define s2rightMax 50
#define s2leftMax 110
#define s1rightMax 100
#define s1leftMax 70

int s1speeds[9] = {59,67,75,79,83,87,95,103,115};
int s2speeds[9] = {56,64,70,74,80,86,94,100,112};

Servo s1,s2,s3,claw;
void setup()
{
  Serial.begin(9600);
}
char command;
int clawangle=90,s3speed=S3stopSpeed,s2speed=4,s1speed=4;
void loop(){
  if (Serial.available()>0){
      command=Serial.read();
  }
  switch (command){
    case 'f':
      s1.detach();
      s2.detach();
      s3.detach();
      claw.detach();
      command='p';
      break;    
    
      //////CLAW SERVO///////////
     case '1':
        if (!claw.attached()) claw.attach(CLAWPIN);
        clawangle=60;
        claw.write(clawangle);
        Serial.println("claw opened");
        command='p';
        break;
     
     case '2':
        if (!claw.attached()) claw.attach(CLAWPIN);
        clawangle-=4;
        claw.write(clawangle);
        Serial.println(clawangle);
       command='p';
      break;
    
     case '3':
        if (!claw.attached()) claw.attach(CLAWPIN);
        clawangle+=4;
        claw.write(clawangle);
        Serial.println(clawangle);
       command='p';
      break;
     
     case '4':
       if (!claw.attached()) claw.attach(CLAWPIN);
       clawangle=132;
       claw.write(clawangle);
       Serial.println("claw close");
       command='p';
       break;
     
     /// Servo 3 ////
     case 'q':
       if (!s3.attached()) s3.attach(S3PIN);
       s3speed+=4;
       Serial.println(s3speed);
       s3.write(s3speed);
       command='p';
      break;
     case 'w':
       s3.detach();
       Serial.println("Servo 3 stopped");
       s3speed=S3stopSpeed;
       command='p';
      break;
     case 'e':
       if (!s3.attached()) s3.attach(S3PIN);
       s3speed-=4;
       Serial.println(+s3speed);
       s3.write(s3speed);
       command='p';
       break; 
     /// Servo 2 ////
     case 'a':
       if (!s2.attached()) s2.attach(S2PIN);
       if (s2speed>0){
         s2speed-=1;
         s2.write(s2speeds[s2speed]);
         Serial.println(s2speed);  
     }
       command='p';
       break;
     case 's':
       s2speed=4;
       s2.write(s2speeds[s2speed]);
       command='p';
       Serial.println("S2 stopped");
       break;
     case 'd':
       if (!s2.attached()) s2.attach(S2PIN);
       if (s2speed<8){
         s2speed+=1;
         Serial.println(s2speed);
         s2.write(s2speeds[s2speed]);  
       }
       command='p';
       break;  
     /// Servo 1 ///
     case 'z':
       if (!s1.attached()) s1.attach(S1PIN);
       if (s1speed>0) {
          s1speed-=1;
          Serial.println(s1speeds[s1speed]);
          s1.write(s1speeds[s1speed]+5);
          s1.write(s1speeds[s1speed]);
       }
       command='p';
       break;
     case 'x':
       s1speed=4;
       s1.write(S1stopSpeed);
       command='p';
       Serial.println("S1 stopped");
       break;
     case 'c':
       if (!s1.attached()) s1.attach(S1PIN);
       if (s1speed<8){
         s1speed+=1;
         Serial.println(s1speeds[s1speed]);
         s1.write(s1speeds[s1speed]); 
       }  
       command='p';
       break;
     default:
      break; 
  }  
 
  
}
  
  

