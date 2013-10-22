
#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int color = 1;
tMotor *motors[2];
tLineSensor *ls;

/**
 * Taste the fuckin' rainbow.
 *
 * @param tPWM **pins : an array of 3 PWMs representing each color pin
 **/
void LEDRainbow(tPWM **pins) {
	  // Red
	  if(color == 1) {
			SetPWM(pins[0], 1, 0);
			SetPWM(pins[1], 0, 0);
			SetPWM(pins[2], 0, 0);
			color = 2; // Color will be orange on next call to this function
	  }
		// Orange
    else if(color == 2){
			SetPWM(pins[0], 1, 0);
			SetPWM(pins[1], 0.6666, 0);
			SetPWM(pins[2], 0, 0);
			color = 3; // Color will be yellow on next call to this function
    }			
		// Yellow
    else if(color == 3){
			SetPWM(pins[0], 1, 0);
			SetPWM(pins[1], 1, 0);
			SetPWM(pins[2], 0, 0);
			color = 4; // And so on...
		}
		// Green
    else if(color == 4){
			SetPWM(pins[0], 0, 0);
			SetPWM(pins[1], 1, 0);
			SetPWM(pins[2], 0, 0);
			color = 5; // And so forth...
	  }
		// Blue
    else if(color == 5){
			SetPWM(pins[0], 0, 0);
			SetPWM(pins[1], 0, 0);
			SetPWM(pins[2], 1, 0);
			color = 6; // Roy G. Biv is a colorful man
		}
		// Indigo
    else if(color == 6){
			SetPWM(pins[0], 0.6666, 0);
			SetPWM(pins[1], 0, 0);
			SetPWM(pins[2], 1, 0);
			color = 7; // And he proudly stands at the rainbow's end
		}
		// Violet
    else if(color == 7){
			SetPWM(pins[0], 1, 0);
			SetPWM(pins[1], 0, 0);
			SetPWM(pins[2], 1, 0);
			color = 8; // Roy G. Biv is a colorful man
		}
		// White
		else {
			// set fourth color
			SetPWM(pins[0], 1, 0);
			SetPWM(pins[1], 1, 0);
			SetPWM(pins[2], 1, 0);
			color = 1; // And his name spells out the whole color spectrum
		}	
}


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
    motors[0] = InitializeMotor(PIN_C5, PIN_C4, true, false);
    motors[1] = InitializeMotor(PIN_B7, PIN_B6, true, false);
}


int main(void) {  
		float LSData[8]; // used to store linesensor data
		char Proceed; // used to pause linesensor output during test
		int i; // used for looping the linesensor test code
		tPWM *Red;	
		tPWM *Green;
		tPWM *Blue;
		tPWM *pins[3]; 
	
    // fire up this bad boy  
    InitializeMCU();
		InitializeBot();
	
		// Initialize RGB pins for the lightshow, put them in an array
	  Red = InitializePWM(PIN_F1, 50000);
	  SetPWM(Red, 1, 0);
		Blue = InitializePWM(PIN_F2, 50000);
    SetPWM(Blue, 1, 0);
		Green = InitializePWM(PIN_F3, 50000);
    SetPWM(Green, 1, 0);
	
	  pins[0] = Red;
	  pins[1] = Green;
	  pins[2] = Blue;
    
		// Disco time, change float value at the end to change speed of lightshow
		// Must use multithreading/pthreads to continue show while the robot runs
		CallEvery(LEDRainbow, pins, 0.05f);
		
		// start the motors, as of right now cancels the light show :(
		SetMotor(motors[LEFT], 0.25);
    SetMotor(motors[RIGHT], 0.35);
		
		// This is where the magic happens
		while(1) {
			
				/**** LineSensor test code, make sure you're connected with PUTTY! ****/
				LineSensorReadArray(ls, LSData);
				for(i = 0; i < 8; i++) {
						printf("%f", LSData[i]);
				}
				printf("\n");
				// wait until key pressed to print out next read
				Proceed = Getc();
				/**** end test code ****/
				
		}
}
