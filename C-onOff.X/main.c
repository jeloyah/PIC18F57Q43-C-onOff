
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "timer0.h"

void main(void) {
     
    unsigned char systemStatus=0;
    
    /* Config clock */
    CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize(); 
    
    /* Config TIMER0 */
    //TIMER0_Initialize();
    
    
    /* infinite loop */
    while(1)
    {   /* switch on RB4 pressed? */
        if (PORTB == 0x00)
            
        {   /* if status is OFF */
            if (systemStatus==0)
            {
                /* change status to ON*/
                systemStatus = 1;
                TIMER0_Delay_ms(10);
            }
            else
            {
                /* change status to OFF */
                systemStatus = 0;
                TIMER0_Delay_ms(10);
            }
        }
        
           
        if (systemStatus == 0)
            /* Turn off LED on RF3 */
            LATF = 0x08;
        else
            /* Turn on LED on RF3 */
            LATF = 0x00;
    } /* while*/
    
    return;
} /* main */