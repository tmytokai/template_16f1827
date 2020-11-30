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
    // DAC ON(DACEN=1)、DACOUT(1ピン)使用(DACOE=1)
    // 詳しくはデータシート 154p を参照してください
    DACCON0 = 0b10100000 ;
}

#endif
