#include <msp430.h> 
#include "nav.h"
#include "sensor.h"
#include "robotMovement.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	return 0;
}
