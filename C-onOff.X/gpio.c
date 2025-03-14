
#include <xc.h>
#include "gpio.h"

/* PortA initialization */
void PortA_Initialize(void)
{
    /* Clear register */
    LATA = 0x00;
    
    /* Pins as digital I/O */
    ANSELA = 0x00;
    
    /* Disable pull-up for RA7:RA0 */
    WPUA = 0x00;
        
    /* RA7:RA0 as output */
    TRISA = 0x00;
}

/* PortB initialization */
void PortB_Initialize(void)
{
    /* Clear register */
    LATB = 0x00;
    
    /* Pins as digital I/O */
    ANSELB = 0x00;
    
    /* Enable Rpull-up on RB4 */
    WPUB = 0x10;
        
    /* RB4 as input, RB7:RB5 & RB3:RB0 as outputs */
    TRISB = 0x10;
}

/* PortC initialization */
void PortC_Initialize(void)
{
    /* Clear register */
    LATC = 0x00;
    
    /* Pins as digital I/O */
    ANSELC = 0x00;
    
    /* Disable Rpull-ups */
    WPUC = 0x00;
        
    /* RC7:RC0 as outputs */
    TRISC = 0x00;
}
    
/* PortD initialization */
void PortD_Initialize(void)
{
    /* Clear register */
    LATD = 0x00;
    
    /* Pins as digital I/O */
    ANSELD = 0x00;
    
    /* Disable Rpull-ups */
    WPUD = 0x00;
        
    /* RD7:RD0 as outputs */
    TRISD = 0x00;
}

/* PortE initialization */
void PortE_Initialize(void)
{
    /* Clear register */
    LATE = 0x00;
    
    /* Pins as digital I/O */
    ANSELE = 0x00;
    
    /* Disable Rpull-ups */
    WPUE = 0x00;
        
    /* RE3:RE0 as outputs */
    TRISE = 0x00;
}    

/* PortF initialization */
void PortF_Initialize(void)
{
    /* Clear register */
    LATF = 0x08;
    
    /* Pins as digital I/O */
    ANSELF = 0x00;
    
    /* Disable Rpull-ups */
    WPUF = 0x00;
        
    /* RF7:RF0 as outputs */
    TRISF = 0x00;
}