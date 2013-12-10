#include <msp430.h> 
#include "nav.h"
#include "sensor.h"
#include "robotMovement.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initializePinOuts();

    configureTimer();

    initializeADC10();

    unsigned int leftSensorReading = checkLeftSensor(), frontSensorReading = checkFrontSensor();
    unsigned int leftSensorTooClose = 0x28c, leftSensorTooFar = 0x1d5, frontSensorWallPresent = 0x2a5;

    while(1){
    	leftSensorReading = checkLeftSensor();
    	frontSensorReading = checkFrontSensor();
    	if(frontSensorReading > frontSensorWallPresent){
    		turnRobotRight();
    	}
    	else if (leftSensorReading > leftSensorTooClose){
    		turnRobotRight();
    	}
    	else if(leftSensorReading < leftSensorTooFar){
    		turnRobotLeft();
    	}
    	else{
    		moveRobotForward();
    	}

    }
}
