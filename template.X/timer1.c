//
// タイマー1割り込み
//
// 16 bit カウンター TMR1 の値が 65535 から 0 に戻る時に
// 割り込みフラグ PIR1bits.TMR1IF がセットされて割り込みが生じます
//
#include "setting.h"

#ifdef USE_TIMER1

void init_timer1(void)
{
    // 全ての割り込み処理を一旦停止します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
    
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
    
    // Timer1 割り込みが起きた時に立つフラグをリセットします
    // なお自動ではリセットされないので手動でリセットする必要があります
    PIR1bits.TMR1IF = ? ;
    
    // 周辺割り込みを許可します
    // 歴史的な背景(？)から、INT外部割り込みや8ビットタイマー割り込みなどの
    // 基本的な割り込み処理以外の割り込みのことを周辺割り込みと呼び、
    // PIE1、PIE2 レジスタで許可/不許可を設定します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.PEIE = ? ;
    
    // Timer1 割り込みを許可します
    // 詳しくはデータシート 90p を参照してください
    PIE1bits.TMR1IE = ? ;
      
    // 全ての割り込み処理を許可します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
}

#endif
