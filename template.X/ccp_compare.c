//
// Compare 割り込み
//
// 1827は CCP(Capture/Compare/PWM)モジュールを4つ(CCP1、CCP2、CCP3、CCP4) 積んでいますが
// Compare モードの場合は Timer1 しか接続出来ません
// なお CCP1 と CCP2 は設定で Compare 出力ピンの位置を変更できます
//
#include "setting.h"

#ifdef USE_CCP1_COMPARE

// CCP1 初期化
void init_ccp1_compare(void)
{
    // 全ての割り込み処理を一旦停止します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
    
    // 0 をセットするとRB3(9 pin) を CCP1 の Compare 出力とします
    // 1 をセットするとRB0(6 pin) を CCP1 の Compare 出力とします
    // 詳しくはデータシート 118p を参照してください
    APFCON0bits.CCP1SEL = ? ;

    // 動作モードを設定します
    // 0b1000 : 出力ピンを Low  で初期化、時間が来たら High にセット
    // 0b1001 : 出力ピンを High で初期化、時間が来たら Low  にセット
    // 0b1010 : 割り込みだけ実行
    // 0b1011 : 特殊イベント実行(詳しくは 209p)
    // 詳しくはデータシート 204p を参照してください
    CCP1CONbits.CCP1M = ? ;

    // CCPRx の値をリセットします
    CCPR1 = 65535;
    
    // Timer1 の動作クロックをセットします
    // 0b00 : FOSC/4
    // 0b01 : FOSC
    // 詳しくはデータシート 185p を参照してください
    T1CONbits.TMR1CS = ? ;
    
    // Timer1 の prescale をセットします
    // 0b11 : x8
    // 0b10 : x4
    // 0b01 : x2
    // 0b00 : x1
    // 詳しくはデータシート 185p を参照してください
    T1CONbits.T1CKPS = ? ;
    
    // Timer1 を ON にします
    // 詳しくはデータシート 185p を参照してください
    T1CONbits.TMR1ON = ? ;

    // Timer1 のカウンターの値をリセットします
    TMR1 = ? ; 
    
    // Compare割り込みが起きた時に立つフラグをリセットします
    // なお自動ではリセットされないので手動でリセットする必要があります
    PIR1bits.CCP1IF = ? ;

    // 周辺割り込みを許可します
    // 歴史的な背景(？)から、INT外部割り込みや8ビットタイマー割り込みなどの
    // 基本的な割り込み処理以外の割り込みのことを周辺割り込みと呼び、
    // PIE1、PIE2 レジスタで許可/不許可を設定します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.PEIE = ? ;

    // Compare割り込みを許可します
    // 詳しくはデータシート 90p を参照してください
    PIE1bits.CCP1IE = ? ;
 
    // 全ての割り込み処理を許可します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
}

#endif