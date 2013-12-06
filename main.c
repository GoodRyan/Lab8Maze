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
    unsigned int leftSensorTooClose = 0x27c, leftSensorTooFar = 0x1c0, frontSensorWallPresent = 0x2F0;

    while(1){
    	leftSensorReading = checkLeftSensor();
    	frontSensorReading = checkFrontSensor();
    	if(frontSensorReading > frontSensorWallPresent){
    		turnRobotRight();
    		_delay_cycles(350000);
    	}
    	else if (leftSensorReading > leftSensorTooClose){
    		turnRobotRight();
    	}
    	else if(leftSensorReading < leftSensorTooFar){
    		turnRobotLeft();
    	}
    	else{
    		_delay_cycles(50000);
    		moveRobotForward();
    	}

    }
}
