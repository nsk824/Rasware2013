#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <stdio.h>
		
		
/**
 * Temporary code for testing the linesensor
 */
void LSTest(tLineSensor *ls) {
	float LSData[8]; // used to store linesensor data
	char Proceed; // used to pause linesensor output during test
	int i;
	
	/**** LineSensor test code, make sure you're connected with PUTTY! ****/
	LineSensorReadArray(ls, LSData);
	for(i = 0; i < 8; i++) {
			printf("%4f", LSData[i]);
	}
	printf("\n");
	// wait until key pressed to print out next read
	Proceed = getchar();
	/**** end test code ****/
}
