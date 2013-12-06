#ifndef _sensor_h
#define _sensor_h
#include <msp430.h>

void initializeADC10();

unsigned int checkLeftSensor();

unsigned int checkRightSensor();

unsigned int checkFrontSensor();

#endif
