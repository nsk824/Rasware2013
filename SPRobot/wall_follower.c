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

void initIRSensor(void) {
	adc[0] = InitializeADC(PIN_D0);
    //adc[1] = InitializeADC(PIN_D1);
    //adc[2] = InitializeADC(PIN_D2);
    //adc[3] = InitializeADC(PIN_D3);
}

float avg_ADCRead(int iterate, tADC *adc) {
    // Use this to lower ADC fluctuations
    int i;
    float avg=iterate;
    
    for(i = 0; i < avg; i--) {
        avg += ADCRead(adc);
    }
    
    return avg;
}


// Program assumes that IR sensors (and the wall) are on the left of vehicle
// Also assumes the vehicle is always at least 10 cm away from wall at all times
void follow_wall(void) {
    float old_ADCValue = 0;
    
    initIRSensor();
    
    while(1) {
        float ADCValue = ADCRead(adc[0]);   // Higher the value, the closer it is to 10cm
        
        if(ADCValue > old_ADCValue) {
            // Turn a little to the right (fixed amount)
        } else if(ADCValue < old_ADCValue) {
            // Turn a little to the left (fixed amount)
        }
        
        
        old_ADCValue = ADCValue;
    }
}

