#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <stdio.h>

tADC *adc[4];

extern float leftSpeed; //used to adjust motor speed while turning
extern float rightSpeed;
extern int Mailbox; //used to determine in the main program whether to turn left or turn right

#define LEFT 1
#define RIGHT 0

void initIRSensor(void) {
	adc[0] = InitializeADC(PIN_D0);
    //adc[1] = InitializeADC(PIN_D1);
    //adc[2] = InitializeADC(PIN_D2);
    //adc[3] = InitializeADC(PIN_D3);
}

float avg_ADCRead(int iterate, tADC *adc) {
    // Use this to lower ADC fluctuations
		//
    int i;
    float sum = 0;
    
    for(i = 0; i < iterate; i++) {
        sum += ADCRead(adc);
    }
    sum /= iterate;
		
    return sum;
}


// Program assumes that IR sensors (and the wall) are on the left of vehicle
// Also assumes the vehicle is always at least 10 cm away from wall at all times
void follow_wall(void) {
    float old_ADCValue = 0;
	
    float ADCValue = avg_ADCRead(256, adc[0]);   // Higher the value, the closer it is to 10cm
	
		//initIRSensor();
    
		if(ADCValue > old_ADCValue) {
        // Turn a little to the right (fixed amount)
			Mailbox = 2;
			rightSpeed = 0.2;
//			  SetMotor(motors[LEFT], 0.25);
	//			SetMotor(motors[RIGHT], 0.20);			
    } else if(ADCValue < old_ADCValue) {
        // Turn a little to the left (fixed amount)
			Mailbox = 1;
			leftSpeed = 0.1;
//			  SetMotor(motors[LEFT], 0.10);
	//			SetMotor(motors[RIGHT], 0.35);
    }
		
    old_ADCValue = ADCValue;
}

