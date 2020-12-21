//
// D/A変換
//
// 出力電圧 = VDD*(DACCON0bits.DACR/32)
//
// なので、 x [V] 出力したいときは
//
// DACCON0bits.DACR = x/VDD*32
//
// より詳細な計算式についてはデータシート 151p を参照してください
//
#include "setting.h"

#ifdef USE_DAC

// DAC 初期化
void init_dac(void)
{
    // 1 をセットするとDACOUT(1ピン)から出力します
    // 0 をセットすると内部だけで使います
    // 詳しくはデータシート 154p を参照してください
    DACCON0bits.DACOE = ? ;

    // 1 をセットすると DAC を ON にします
    // 詳しくはデータシート 154p を参照してください
    DACCON0bits.DACEN = ? ;
}

#endif
