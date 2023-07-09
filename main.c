#include <msp430.h> 

//Initialize pin and values
void init(){
    P1DIR |= BIT0 + BIT6;   //SETUP LED1,2 AS OUTPUT
    P1DIR &= ~BIT3;         //enable button
    P1REN |= BIT3;
    P1OUT |= BIT3;
    P1OUT &= ~(BIT0 +BIT6); //SET LED1,2 LOW
}

//LED go brr or not
void NoBrr(){
    P1OUT |= BIT0;
    P1OUT &= ~(BIT6);
    _delay_cycles(500000);
    P1OUT |= BIT6;
    P1OUT &= ~(BIT0);
    _delay_cycles(500000);

}
void GoBrr(){
        P1OUT |= BIT0;
        P1OUT &= ~(BIT6);
        _delay_cycles(100000);
        P1OUT |= BIT6;
        P1OUT &= ~(BIT0);
        _delay_cycles(100000);
}

//main shit
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//setup pins
	init();

	//LED go BRRR
	while(1)
	{
	    if (P1IN & BIT3){
	        NoBrr();
	    }

	    else{
	        GoBrr();
	    }
	}
}

