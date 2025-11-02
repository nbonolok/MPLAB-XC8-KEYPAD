/* 
 * File:   keypad.c
 * Author: nbonolok
 *
 * Created on October 28, 2025, 4:33 PM
 */
#include "keypad.h"
#include <xc.h>
#include <stdio.h>
volatile unsigned char *_pport;
volatile unsigned char *_ptris;
void KEYPAD(volatile unsigned char *_p,volatile unsigned char *_t){
        _pport = _p;                   //Dynamic PORT pointer  
        _ptris = _t;                   //Dynamic TRIS pointer
       *_ptris = 0xf0;                 //LOWER nibble outputs, Upper nibble = inputs  
       *_pport = 0xff;                 //PORT PINS = HIGH
}

uint8_t isColumnActive(uint8_t col) {
    uint8_t pin = 4 + col;
    uint8_t flag = (( *_pport & (1 << pin)) == 0);  // Active LOW
    return  flag;
    
}

char makeKeymap(uint8_t row, uint8_t col) {
    if (row < ROWS && col < COLS)
        return keymap[row][col];
    else
        return 0;
}

char getKeyPressed(void) {
    for (uint8_t row = 0; row < ROWS; row++) {
        *_pport = (*_pport | 0x0f);
        *_pport = (*_pport & (~(1<< row)));
        
        __delay_ms(2);                              //de-bouncing delay 

        for (uint8_t col = 0; col < COLS; col++) {
            if (isColumnActive(col)) {
                __delay_ms(20);                    //de-bounce
                while (isColumnActive(col));       //wait for release
                return makeKeymap(row, col);
            }
        }
        *_pport = (*_pport | (char)(1 << row));
    }
    return 0; // No Key  pressed
}

