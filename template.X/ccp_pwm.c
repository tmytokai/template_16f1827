//
// PWM
//
// 1827は CCP(Capture/Compare/PWM)モジュールを4つ(CCP1、CCP2、CCP3、CCP4) 積んでいます
// またタイマーモジュールを3つ(Timer2、Timer4、Timer6) 積んでるので同時に 3 つ PWM 出力可能です
// なお CCP1 と CCP2 は設定で PWM 出力ピンの位置を変更できます
//
#include "setting.h"

#ifdef USE_CCP1_PWM

// CCP1 を PWM モードで初期化
void init_ccp1_pwm(void)
{
    // 0 をセットするとRB3(9 pin) を CCP1 の PWM 出力とします
    // 1 をセットするとRB0(6 pin) を CCP1 の PWM 出力とします
    // 詳しくはデータシート 118p を参照してください
    APFCON0bits.CCP1SEL = ? ;

    // 動作モードを設定します
    // 0b1100 をセットすると PWM 出力モードになります
    // 詳しくはデータシート 204p を参照してください
    CCP1CONbits.CCP1M = ? ;

    // タイマーを接続します
    // 0b00 = Timer2、0b01 = Timer4、0b10 = Timer6
    // 詳しくはデータシート 206p を参照してください
    CCPTMRSbits.C1TSEL = ? ;

    // Timer2,4,6 の動作クロックは FOSC/4 で固定です
    
    // タイマーの prescale を設定します
    // 0b00 = x1、0b01 = x4、0b10 = x16、0b11 = x64
    // PWM 周期やパルス幅の計算で使います
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.T?CKPS = ? ;

    // 1 をセットするとタイマーが ON になり PWM 出力が始まります
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.TMR?ON = ? ;
}

#endif

#ifdef USE_CCP2_PWM

// CCP2 初期化
void init_ccp2_pwm(void)
{
    // 0 をセットするとRB6(12 pin) を CCP2 の PWM 出力とします
    // 1 をセットするとRA7(16 pin) を CCP2 の PWM 出力とします
    // 詳しくはデータシート 118p を参照してください
    APFCON0bits.CCP2SEL = ? ;

    // 動作モードを設定します
    // 0b1100 をセットすると PWM 出力モードになります
    // 詳しくはデータシート 204p を参照してください
    CCP2CONbits.CCP2M = ? ;

    // タイマーを接続します
    // 0b00 = Timer2、0b01 = Timer4、0b10 = Timer6
    // 詳しくはデータシート 206p を参照してください
    CCPTMRSbits.C2TSEL = ? ;

    // Timer2,4,6 の動作クロックは FOSC/4 で固定です
    
    // タイマーの prescale を設定します
    // 0b00 = x1、0b01 = x4、0b10 = x16、0b11 = x64
    // PWM 周期やパルス幅の計算で使います
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.T?CKPS = ? ;

    // 1 をセットするとタイマーが ON になり PWM 出力が始まります
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.TMR?ON = ? ;
}

#endif

#ifdef USE_CCP3_PWM

// CCP3 初期化
void init_ccp3_pwm(void)
{
    // CCP3 の PWM 出力は RA3(2 pin) 固定です

    // 動作モードを設定します
    // 0b1100 をセットすると PWM 出力モードになります
    // 詳しくはデータシート 204p を参照してください
    CCP3CONbits.CCP3M = ? ;

    // タイマーを接続します
    // 0b00 = Timer2、0b01 = Timer4、0b10 = Timer6
    // 詳しくはデータシート 206p を参照してください
    CCPTMRSbits.C3TSEL = ? ;

    // Timer2,4,6 の動作クロックは FOSC/4 で固定です
    
    // タイマーの prescale を設定します
    // 0b00 = x1、0b01 = x4、0b10 = x16、0b11 = x64
    // PWM 周期やパルス幅の計算で使います
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.T?CKPS = ? ;

    // 1 をセットするとタイマーが ON になり PWM 出力が始まります
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.TMR?ON = ? ;
}

#endif

#ifdef USE_CCP4_PWM

// CCP4 初期化
void init_ccp4_pwm(void)
{
    // CCP4 の PWM 出力は RA4(3 pin) 固定です

    // 動作モードを設定します
    // 0b1100 をセットすると PWM 出力モードになります
    // 詳しくはデータシート 204p を参照してください
    CCP4CONbits.CCP4M = ? ;

    // タイマーを接続します
    // 0b00 = Timer2、0b01 = Timer4、0b10 = Timer6
    // 詳しくはデータシート 206p を参照してください
    CCPTMRSbits.C4TSEL = ? ;

    // Timer2,4,6 の動作クロックは FOSC/4 で固定です
    
    // タイマーの prescale を設定します
    // 0b00 = x1、0b01 = x4、0b10 = x16、0b11 = x64
    // PWM 周期やパルス幅の計算で使います
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.T?CKPS = ? ;

    // 1 をセットするとタイマーが ON になり PWM 出力が始まります
    // 詳しくはデータシート 191p を参照してください
    T?CONbits.TMR?ON = ? ;
}

#endif
