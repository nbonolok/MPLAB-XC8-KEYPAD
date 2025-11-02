/*
 * File:   lab03.c
 * Author: nbonolok
 *
 * Created on October 28, 2025, 5:35 PM
 */
#pragma warning disable 520
//CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT, WDTE = OFF, PWRTE = ON, MCLRE = OFF, CP = OFF
#pragma config CPD = OFF, BOREN = OFF, IESO = OFF,  FCMEN = OFF, LVP = OFF 
//CONFIG2
#pragma config BOR4V = BOR21V,  WRT = OFF

#define  RS  0          //PORTD<RD0>
#define  E   1          //PORTD<RD1>
#define  D4  4          //PORTD<RD4>
#define  D5  5          //PORTD<RD5>
#define  D6  6          //PORTD<RD6>
#define  D7  7          //PORTD<RD7>

#define  RED     0x04   //Only RED    Led is ON
#define  YELLOW  0x02   //Only YELLOW Led is ON 
#define  GREEN   0x01   //Only GREEN  Led is ON
double _XTAL_FREQ = 8000000;      //8Mhz oscillator speed    
#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include "keypad.h"                  //Include keypad library
#include "lcd.h" 
    

void initDisplay(){                       //initialize Display function
    TRISD = 0x00;                         //Set PORTD as OUTPUT  
    PORTD = 0x00;                         //Clear PORTD
    LCD(&PORTD, RS, E, D4, D5, D6, D7);   //Assign LCD pins through Constructor 
    LCD_Begin(16, 2);                     //Configure LCD to 16x2 
    LCD_Goto(1, 1);                       //Set cursor to Col= 1, Row = 1
    __delay_ms(100);                      //Wait for 100 ms 
    
     LCD_PutS("Keypad Driver"); 
     LCD_Goto(1,2);
} 
void initPIC(){
    OSCCON         =  0x77; 
    INTCONbits.GIE =  0x00;
    ANSELH         =  0x00;
     __delay_ms(50);
}
void main(void) {
    initPIC();
    initDisplay();
    KEYPAD(&PORTB,&TRISB);
    
    while (1) {
        char key = getKeyPressed();
        
        if (key) {
             char buffer[10];
             sprintf(buffer, "%c",key);
             LCD_PutS(buffer);
             key = 0;
             __delay_ms(250);
        }
    }
    return;
}
