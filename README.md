# MPLAB-XC8-KEYPAD   
Microchip XC8 compiler library for 4x4 or (4x3) smaller keypad connected to any 8-bit port of the common PIC microcontroller.

## Description   
The keypad library implements the makeKeymap  helper function that converts a 2D array of characters (or key values) into the format required. The keypad library was tested on  matrix keypads (4x3 and  4x4 ). The columns and rows of the keypad can be connected to any 8-bit microcontroller PORT just by defining **PORT\<X\>** and **TRIS\<X\>** as a pointer through the library function constructor.  

## Interface   
The main files for the library are **keypad.h** and **keypad.c** , both using MPLAB XC8  compiler. The following header file statement must
be included when using the keypad library:
```C
#include <keypad.h>
```
The following variables in the **keypad.h** header file must be changed to match keypad used 4x4 or 4x3 layouts.
1. **_XTAL_FREQ** : Used for selection of the oscillator frequency
2. **ROWS** : Number of rows in the selected keypad
3. **COLS** : Number of columns in the selected keypad
4. **keymap**: Used for mapping keypad ascii values as in the keypad layout  
```C
extern  double  _XTAL_FREQ;
#define ROWS  4
#define COLS  4
const char keymap[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
```
## User Functions
| Function   | KEYPAD(\&port,\&tris) |
| :---- | :---- |
| Description | A constructor like function that is used for initialization of the PIC PORT <br>and TRIS when interfacing to a keypad |
| Parameters | \&PORT\<X\>  and \&TRIS\<X\> |
| Return | \- |

| Function  | getKeyPressed(void) |
| :---- | :---- |
| Description | Scans the keypad and returns a mapped character based on  key pressed  |
| Parameters | \- |
| Return | char  |

### Example:  
 A 4x4 keypad  is connected to the PIC16F887 microcontroller’s PORTB. 
```C

  #include <keypad.h>
   //PIC initialization code here 
    void  main(void){      
    KEYPAD(&PORTB, &TRISB);      
      while(1){             
          char  key = getKeyPressed();            
          if(key){              
          //Do something here with key value
             }      
          }
      }
 
```
