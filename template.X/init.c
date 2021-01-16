//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// このファイルの内容は書き換えないでください
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "setting.h"

// 全体初期化
void init(void)
{
    OSCCON = _OSCCON;
    PORTA = 0x0;
    PORTB = 0x0;
    TRISA = 0x0;
    TRISB = 0x0;
    ANSELA = 0x0;
    ANSELB = 0x0;

#ifdef USE_INPUT
    init_input();
#endif

#ifdef USE_UART
    init_uart();
#endif

#ifdef USE_ADC
    init_adc();
#endif

#ifdef USE_CCP1_PWM
    init_ccp1_pwm();
#endif

#ifdef USE_CCP2_PWM
    init_ccp2_pwm();
#endif

#ifdef USE_CCP3_PWM
    init_ccp3_pwm();
#endif

#ifdef USE_CCP4_PWM
    init_ccp4_pwm();
#endif

#ifdef USE_RB0INT
    init_rb0int();
#endif

#ifdef USE_TIMER0
    init_timer0();
#endif

#ifdef USE_TIMER1
    init_timer1();
#endif

#ifdef USE_TIMER2
    init_timer2();
#endif

#ifdef USE_CCP1_COMPARE
    init_ccp1_compare();
#endif

#ifdef USE_CCP1_CAPTURE
    init_ccp1_capture();
#endif

#ifdef USE_MSSP1_SPI
    init_mssp1_spi();
#endif

#ifdef USE_MSSP1_I2C
    init_mssp1_i2c();
#endif

#ifdef USE_DAC
    init_dac();
#endif

#ifdef USE_COMPARATOR1
    init_comparator1();
#endif
}
