
#include <xc.h>
#include "clock.h"

void CLOCK_Initialize(void)
{
	/* HFINTOSC enabled */
    OSCEN = 0x40;
    
    /* HFINTOSC = 1 MHz */
	OSCFRQ = 0x08;
    
    /* Clock source = HFINTOSC, Clock Divider = 64 */
    OSCCON1 = 0x66;
}
