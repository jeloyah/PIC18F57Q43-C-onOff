
#include <xc.h>
#include "clock.h"

void CLOCK_Initialize(void)
{
	/* HFINTOSC enabled */
    OSCEN = 0x40;
    
    /* HFINTOSC = 1 MHz */
	OSCFRQ = 0x00;
    
    /* Clock source = HFINTOSC, Clock Divider = 1 */
    OSCCON1 = 0x60;
}
