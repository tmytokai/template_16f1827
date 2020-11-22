#ifndef _SETTING_H
#define _SETTING_H

// __delay_ms 関数を使う場合は define する必要があります
// init.c 内の OSCCON の設定と合わせてください(今回は 4 Mhz)
#define _XTAL_FREQ 4000000

// デジタル入力を使う場合はコメントアウトを解除してください
//#define USE_INPUT

//  シリアル通信を使う場合はコメントアウトを解除してください
//#define USE_UART

// A/D変換を使う場合はコメントアウトを解除してください
//#define USE_ADC

// PWM を使う場合はコメントアウトを解除してください
//#define USE_CCP1_PWM
//#define USE_CCP2_PWM
//#define USE_CCP3_PWM
//#define USE_CCP4_PWM

// RB0/INT外部割り込みを使う場合はコメントアウトを解除してください
//#define USE_RB0INT

// タイマー1割り込みを使う場合はコメントアウトを解除してください
//#define USE_TIMER1

// Compare 割り込みを使う場合はコメントアウトを解除してください
//#define USE_CCP1_COMPARE

#include <xc.h>

void init(void);

#ifdef USE_INPUT
void init_input(void);
#endif

#ifdef USE_UART
#include <stdio.h>
void init_uart(void);
#endif

#ifdef USE_ADC
void init_adc(void);
int adc(int chn);
#endif

#ifdef USE_CCP1_PWM
void init_ccp1_pwm(void);
#endif

#ifdef USE_CCP2_PWM
void init_ccp2_pwm(void);
#endif

#ifdef USE_CCP3_PWM
void init_ccp3_pwm(void);
#endif

#ifdef USE_CCP4_PWM
void init_ccp4_pwm(void);
#endif

#ifdef USE_RB0INT
void init_rb0int(void);
#endif

#ifdef USE_TIMER1
void init_timer1(void);
#endif

#ifdef USE_CCP1_COMPARE
void init_ccp1_compare(void);
#endif

#endif
