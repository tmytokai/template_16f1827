//
// 割り込み処理が起こると共通でこの関数が呼び出されます
// ちなみに isr は Interrupt Service Routine の略です
//
#include "setting.h"

// main.c で定義されている外部変数は extern しないと
// このソース内で使えませんので注意して下さい
// (例) extern int count;

#if __XC8_VERSION < 2000
void interrupt isr(void)
#else
void __interrupt () isr(void) 
#endif
{
    // この割り込み関数は全ての割り込み処理で共通なので
    // 立っている割り込みフラグを見てどの割り込みが生じたか判断します
}
