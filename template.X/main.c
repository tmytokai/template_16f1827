#include "config.h"
#include "setting.h"

void main(void){

    init();

    while(1){
    }

   return;
}

// 割り込み処理が起こるとこの関数が呼び出されます
// ちなみに isr は Interrupt Service Routine の略です
#if __XC8_VERSION < 2000
void interrupt isr(void)
#else
void __interrupt () isr(void) 
#endif
{
    INTCONbits.GIE = 0; // 割り込み処理中に再度割り込みがかからないようにします

    // 割り込み関数は全ての割り込み処理で共通なので
    // 立っているフラグを見てどの割り込みが生じたか判断します
    
    INTCONbits.GIE = 1; // 割り込み処理が終わったので再び割り込みを許可します
}

