#include <msp430.h> 
#define delay _delay_cycles(70000)

// |- BIT? ta paga e pone low
// ^= BIT? ta pone high

int counter = 0;


void setup()
{
    P1DIR ^= BIT0 + BIT6;
    P1DIR &= ~BIT3;
    P1OUT ^= BIT0 + BIT6;
}

void fast(){
    P1OUT |= BIT0;
    P1OUT ^= BIT6;
    delay;
    P1OUT |= BIT6;
    P1OUT ^= BIT0;
    delay;
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    //setup pins
	setup();

	//blink led
	while(1)
	{
	    if(P1IN &BIT3){
	    P1OUT |= (BIT0 + BIT6);

	    }
	    else{
	    fast();
	    }

	}
}
