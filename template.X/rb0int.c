//
// RB0/INT外部割り込み
//
#include "setting.h"

#ifdef USE_RB0INT

void init_rb0int(void) {

    // 全ての割り込み処理を一旦停止します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
    
    // RB0/INT を入力モードにします
    // 詳しくは input.c の説明を読んで下さい
    TRISB = TRISB | ? ;

    // RB0/INT にプルアップ抵抗を接続しない場合は内部プルアップ機能を有効にします
    // 詳しくは input.c の説明を読んで下さい
    WPUB = WPUB | ? ;
    OPTION_REGbits.nWPUEN = 0;

    // RB0/INT外部割り込みを行うタイミングを指定します
    // 0 をセットすると立ち下がり(H→L)で割り込みをします
    // 1 をセットすると立ち上がり(L→H)で割り込みをします
    // 詳しくはデータシート 175p を参照してください
    OPTION_REGbits.INTEDG = ? ;
    
    // RB0/INT外部割り込みが起きた時に立つフラグを 0 で初期化します
    // なお自動ではリセットされないので手動でリセットする必要があります
    INTCONbits.INTF = ? ;
    
    // RB0/INT外部割り込みを許可します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.INTE = ? ; 
    
    // 全ての割り込み処理を許可します
    // 詳しくはデータシート 89p を参照してください
    INTCONbits.GIE = ? ; 
}

#endif