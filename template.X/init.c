#include "setting.h"

// 全体初期化
void init(void)
{
    // オシレータ(発振回路)の設定で、FOSC(Frequency of Oscillator)を 4 Mhz にセットしています
    // 今回は FOSC = 4 MHz (SPLLEN=0, IRCF=0b1101) としています
    // なお __delay_ms 関数を使う場合は setting.h 内の _XTAL_FREQ も同じ速さにする必要があります
    // 詳しくはデータシート 67p を参照してください
    OSCCON = 0b01101000; 

    // ポート A,B を初期化します
    PORTA = 0x00; 
    PORTB = 0x00;

    // ポート A,B の入出力設定です
    // 0 にすると出力モード、1 にすると入力モードになります
    // 詳しくはデータシート 120p(ポートA)と126p(ポートB) を参照してください
    TRISA = 0b00000000;
    TRISB = 0b00000000;

    // ポート A,b のアナログ設定です
    // 0 にするとデジタル入出力モード、1 にするとアナログ入力モードになります
    // アナログ入力モードにする場合は対応する TRISx も入力モードにして下さい
    // 詳しくはデータシート 122p(ポートA)と128p(ポートB) を参照してください
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;

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
    
#ifdef USE_TIMER1
    init_timer1();
#endif
    
#ifdef USE_CCP1_COMPARE
    init_ccp1_compare();
#endif

}
