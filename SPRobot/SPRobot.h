#include <RASLib/inc/pwm.h>
#include <RASLib/inc/motor.h>

tMotor *motors[2];
tLineSensor *ls;

void InitializeBot(void);

void LEDRainbow(tPWM **RGB);

void InitializeLightshow(void);

void RunLightshow(void);

void LSTest(tLineSensor *ls);

void initIRSensor(void);

void follow_wall(void);
