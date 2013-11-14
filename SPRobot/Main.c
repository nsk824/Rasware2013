#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include "SPRobot.h"

#define LEFT 1
#define RIGHT 0

/*
float leftSpeed;
float rightSpeed;
int Mailbox;
*/
/**
 * Initialize the motors and sensors, pretty self-explanitory
 *
 * ... unless you're dumb :3
 **/
void InitializeBot(void) {
	// initialize line sensor
	tI2C *bus = InitializeI2C(PIN_B3, PIN_B2);
	ls = InitializeLineSensor(bus, 0);
	// initialize motors
	motors[LEFT] = InitializeMotor(PIN_C5, PIN_C4, true, false);
	motors[RIGHT] = InitializeMotor(PIN_B7, PIN_B6, true, false);
	// initialize IR sensors
	//initIRSensor();
}


int main(void){  
	// fire up this bad boy  
	InitializeMCU();
	
	// run light show
	InitializeLightshow();
	RunLightshow();
	
	InitializeBot();
		
	// start the motors, as of right now cancels the light show :(
	SetMotor(motors[LEFT], 0.25);
	SetMotor(motors[RIGHT], 0.35);

    // Need Threads to run together
	//SetMotor(motors[LEFT], 0.25);
	//SetMotor(motors[RIGHT], 0.35);
	
//	Mailbox = 0;
		
	// This is where the magic happens
	while(1) {
		LSTest(ls);	
/*
  	follow_wall();
		if (Mailbox == 1){
			SetMotor(motors[LEFT], leftSpeed);
		}
	  else if (Mailbox == 2){
			SetMotor(motors[RIGHT], rightSpeed);
		}
*/
	}
}
