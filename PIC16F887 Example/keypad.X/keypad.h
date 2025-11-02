/*******************************************************************************
 * MPLAB XC8 compiler KEYPAD driver for 4x4 and 4x3 Keypads.                   *
 * This is a free software with NO WARRANTY.                                   *
 * Email:nbonolok@gmail.com                                                    *
 *                                                                             *
 * Keypad Driver header file keypad.h                                          *
 ******************************************************************************/

#ifndef __KEYPAD_h
#define __KEYPAD_h
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

extern  double  _XTAL_FREQ;
#define ROWS  4
#define COLS  4
const char keymap[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
//User call functions 
void KEYPAD(volatile unsigned char *_p,volatile unsigned char *_t);
char getKeyPressed(void); 

//Internal functions
uint8_t isColumnActive(uint8_t col); 
char makeKeymap(uint8_t row, uint8_t col); 

#endif

// end of header code