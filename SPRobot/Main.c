#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <stdio.h>
#include "SPRobot.h"

#define LEFT 1
#define RIGHT 0

/**
 * Initialize the motors and sensors, pretty self-explanitory
 *
 * ... unless you're dumb :3
 **/
void InitializeBot() {
	// initialize line sensor
	tI2C *bus = InitializeI2C(PIN_B3, PIN_B2);
	ls = InitializeLineSensor(bus, 0);
	// initialize motors
	motors[LEFT] = InitializeMotor(PIN_C5, PIN_C4, true, false);
	motors[RIGHT] = InitializeMotor(PIN_B7, PIN_B6, true, false);
}


int main(void) {  
	// fire up this bad boy  
	InitializeMCU();
	
	InitializeLightshow();
	RunLightshow();
	
	InitializeBot();
		
	// start the motors, as of right now cancels the light show :(
	//SetMotor(motors[LEFT], 0.25);
	//SetMotor(motors[RIGHT], 0.35);
		
	// This is where the magic happens
	while(1) {
			
		//LSTest(ls);
			
	}
}
