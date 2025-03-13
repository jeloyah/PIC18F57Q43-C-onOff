#include <xc.h>
#include "timer0.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
	/* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:16384 */
	T0CON1 = 0x7E;   
}

void TIMER0_Delay(void)
{
	
	/* Load TMR0 with initial value FC17(hex) = 64535(dec) */
    /* TIMER0_time = (1/TMR0_clock_source) x (end_value - initial_value) x prescaler */
    /*             = (1/64MHz ) x (65535-64535) x 16384 = 256 ms */
	TMR0H = 0xFC;
	TMR0L = 0x17;

    /* Timer0 enabled */
	T0CON0 |= 0x80; 
                 
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80)
          ;
        
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
             
    /* Timer0 disabled */
	T0CON0 &= 0x7F;
}

void TIMER0_Delay_ms(unsigned int time_milis)
{
	
    /* HFINTOSC; counter not synchronized; prescaler 1:64 */
	T0CON1 = 0x76;   
    
    /* Load TMR0 with initial value FC17(hex) = 64535(dec) */
    /* TIMER0_time = (1/TMR0_clock_source) x (end_value - initial_value) x prescaler */
    /*             = (1/64MHz ) x (65535-64535) x 64 = 1 ms */
	TMR0H = 0xFC;
	TMR0L = 0x17;

    /* Timer0 enabled */
	T0CON0 |= 0x80; 
    
    while(time_milis != 0)    
    {                
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80)
          ;
        
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
    time_milis--;
    }
             
    /* Timer0 disabled */
	T0CON0 &= 0x7F;
}