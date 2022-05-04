/**
 * AC0 Generated Driver File
 * 
 * @file ac0.c
 * 
 * @ingroup  ac0
 * 
 * @brief This is the generated driver implementation file for the AC0 driver.
 *
 * @version AC0 Driver Version 1.0.0
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "../ac0.h"

int8_t AC0_Initialize(void) 
{

    //DACREF 100; 
    AC0.DACREF = 0x64;
    
    //CMP disabled; INTMODE Positive and negative inputs crosses; 
    AC0.INTCTRL = 0x0;
    
    //INITVAL LOW; INVERT disabled; MUXNEG DAC Reference; MUXPOS Positive Pin 0;   
    AC0.MUXCTRL = 0x4;
    
    //ENABLE enabled; HYSMODE No hysteresis; OUTEN enabled; POWER Power profile 0, Shortest response time, highest consumption; RUNSTDBY disabled; 
    AC0.CTRLA = 0x41;

    return 0;
}

ISR(AC0_AC_vect)
{
    /* Insert your AC interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    AC0.STATUS = AC_CMPIF_bm;
}

