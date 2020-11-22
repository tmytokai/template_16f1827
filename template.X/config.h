#ifndef _CONFIG_H
#define _CONFIG_H

// Configuration Word 1, 詳しくはデータシート 50p 参照
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config CLKOUTEN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF

// Configuration Word 2, 詳しくはデータシート 52p 参照
#pragma config WRT = OFF
#pragma config PLLEN = OFF
#pragma config STVREN = OFF
#pragma config BORV = LO
#pragma config LVP = OFF

#endif