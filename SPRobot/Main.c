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
	float LSData[8]; // used to store linesensor data
	char Proceed; // used to pause linesensor output during test
	int i; // used for looping the linesensor test code
	
	// fire up this bad boy  
	InitializeMCU();
	
	InitializeLightshow();
	RunLightshow();
		
	// start the motors, as of right now cancels the light show :(
	//SetMotor(motors[LEFT], 0.25);
	//SetMotor(motors[RIGHT], 0.35);
		
	// This is where the magic happens
	while(1) {
			
		/**** LineSensor test code, make sure you're connected with PUTTY! ****
		LineSensorReadArray(ls, LSData);
		for(i = 0; i < 8; i++) {
				printf("%f", LSData[i]);
		}
		printf("\n");
		// wait until key pressed to print out next read
		//Proceed = Getc();
		**** end test code ****/
			
	}
}
