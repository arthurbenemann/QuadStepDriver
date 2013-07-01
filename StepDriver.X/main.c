#include "xc.h"

#pragma config PLLSEL   = PLL3X     // 3X PLL multiplier selected
#pragma config CFGPLLEN = OFF       // PLL turned on during execution
#pragma config CPUDIV   = NOCLKDIV  // 1:1 mode (for 48MHz CPU)
#pragma config LS48MHZ  = SYS48X8   // Clock div / 8 in Low Speed USB mode
#pragma config FOSC     = INTOSCIO  // HFINTOSC selected at powerup, no clock out
#pragma config PCLKEN   = OFF       // Primary oscillator driver
#pragma config FCMEN    = OFF       // Fail safe clock monitor
#pragma config IESO     = OFF       // Internal/external switchover (two speed startup)
#pragma config nPWRTEN  = OFF       // Power up timer
#pragma config BOREN    = SBORDIS   // BOR enabled
#pragma config nLPBOR   = ON        // Low Power BOR
#pragma config WDTEN    = OFF      // Watchdog Timer controlled by SWDTEN
#pragma config WDTPS    = 32768     // WDT postscalar
#pragma config PBADEN   = OFF       // Port B Digital/Analog Powerup Behavior
#pragma config SDOMX    = RC7       // SDO function location
#pragma config LVP      = OFF       // Low voltage programming
#pragma config MCLRE    = OFF        // MCLR function enabled
#pragma config STVREN   = ON        // Stack overflow reset
#pragma config ICPRT    = OFF       // Dedicated ICPORT program/debug pins disable
#pragma config DEBUG = OFF
#pragma config XINST    = OFF       // Extended instruction set


#define Step1 LATB0
#define Step2 LATB1
#define Step3 LATB2
#define Step4 LATB3

#define Dir1 LATD0
#define Dir2 LATD1
#define Dir3 LATD2
#define Dir4 LATD3

void delay(int j) {
    int i;
    for (i = 0; i < j; i++) {
    }
}

int main() {
    long int i = 0;

    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;

    TRISB &= 0xF0;
    TRISD &= 0xF0;

    while (1) {


        //delay(5);
        i++;


        Step4 = !Step4;
        Step3 = !Step3;
        Step2 = !Step2;
        Step1 = !Step1;

        if ((i % (200*16*2)) == 0) {
            Dir1 = !Dir1;
            Dir2 = !Dir2;
            Dir3 = !Dir3;
            Dir4 = !Dir4;
        }

    }
}

