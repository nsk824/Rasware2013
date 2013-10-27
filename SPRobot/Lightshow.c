#include <RASLib/inc/time.h>
#include <RASLib/inc/pwm.h>

int color = 1;
tPWM *RGB[3];

/**
 * Taste the fuckin' rainbow.
 *
 * @param tPWM **RGB : an array of 3 PWMs representing each color pin
 **/
void LEDRainbow(tPWM **RGB) {
	switch(color) {
		case 1: // Red
			SetPWM(RGB[0], 1, 0);
			SetPWM(RGB[1], 0, 0);
			SetPWM(RGB[2], 0, 0);
			color = 2; // Color will be orange on next call to this function
			break;
		case 2: // Orange
			SetPWM(RGB[0], 1, 0);
			SetPWM(RGB[1], 0.6666, 0);
			SetPWM(RGB[2], 0, 0);
			color = 3; // Color will be yellow on next call to this function
			break;
		case 3: // Yellow
			SetPWM(RGB[0], 1, 0);
			SetPWM(RGB[1], 1, 0);
			SetPWM(RGB[2], 0, 0);
			color = 4; // And so on...
			break;
		case 4: // Green
			SetPWM(RGB[0], 0, 0);
			SetPWM(RGB[1], 1, 0);
			SetPWM(RGB[2], 0, 0);
			color = 5; // And so forth...
			break;
		case 5: // Blue
			SetPWM(RGB[0], 0, 0);
			SetPWM(RGB[1], 0, 0);
			SetPWM(RGB[2], 1, 0);
			color = 6; // Roy G. Biv is a colorful man
			break;
		case 6: // Indigo
			SetPWM(RGB[0], 0.6666, 0);
			SetPWM(RGB[1], 0, 0);
			SetPWM(RGB[2], 1, 0);
			color = 7; // And he proudly stands at the rainbow's end
			break;
		case 7: // Violet
			SetPWM(RGB[0], 1, 0);
			SetPWM(RGB[1], 0, 0);
			SetPWM(RGB[2], 1, 0);
			color = 8; // Roy G. Biv is a colorful man
			break;
		case 8: // White
			SetPWM(RGB[0], 1, 0);
			SetPWM(RGB[1], 1, 0);
			SetPWM(RGB[2], 1, 0);
			color = 1; // And his name spells out the whole color spectrum
			break;
	}
}


/**
 * Initialize RGB pins for the lightshow, put them in an array 
 */
void InitializeLightshow() {
	tPWM *Red;	
	tPWM *Green;
	tPWM *Blue;

	Red = InitializePWM(PIN_F1, 50000);
	SetPWM(Red, 1, 0);
	Blue = InitializePWM(PIN_F2, 50000);
	SetPWM(Blue, 1, 0);
	Green = InitializePWM(PIN_F3, 50000);
	SetPWM(Green, 1, 0);
	
	RGB[0] = Red;
	RGB[1] = Green;
	RGB[2] = Blue;
}


/**
 * Disco time
 * note: must use multithreading/pthreads to continue show while the robot runs
 */
void RunLightshow() {
	CallEvery(LEDRainbow, RGB, 0.05f);
}
