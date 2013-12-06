#include "sensor.h"

void initializeADC10(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
}

unsigned int checkLeftSensor(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;
	ADC10AE0 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int checkRightSensor(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;

	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int checkFrontSensor(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;
	ADC10AE0 |= BIT5;
	ADC10CTL0 |= ENC + ADC10SC;

	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);
}
