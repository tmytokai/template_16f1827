//
// SPI マスターモード
//
// 1827は MSSP(Master Synchronous Serial Port)モジュールを2つ(MSSP1、MSSP2)積んでいますので
// SPI または I2C を2系統同時に扱えます ※ ピン配置の関係で同時に使えない組み合わせもあります
//
#include "setting.h"

#ifdef USE_MSSP1_SPI

// MSSP1 を SPI マスターモードで初期化
void init_mssp1_spi(void)
{
    // MSSP1 の SPI マスターモードでは SCK1 (10 ピン)と SDI1 (7 ピン)を使います
    // SDO1 は 8 ピンと 15 ピンのどちらかを指定できます

    APFCON0bits.SDO1SEL = 1; // 15 ピンを SDO1 とします
    TRISB = TRISB | 0b00000010; // マスターモードでは SDI1 (RB1,7ピン)を入力モードにします(他は出力)

    // MODE0 → SMP=0, CKE=1, CKP=0、ビットオーダーはデフォルトで MSBFIRST (らしい)
    SSP1STAT = 0b01000000; // SMP=0, CKE=1
    SSP1CON1 = 0b00101010; // MSSP1 ON(SSP1EN=1)、CKP=0, SPIマスターモード(SSP1M=0b1010)
    SSP1CON2 = 0x00;
    SSP1CON3 = 0x00;
    SSP1ADD = 1; // クロック = 1MHz ( FOSC/(4*clock)-1 = 8 MHz/4M-1 = 1 )
}

// MSSP1 で 1 byte 送信
void mssp1_spi_putch( char data )
{
    SSP1BUF = data;
}

// MSSP1 で 1 byte 受信
int mssp1_spi_getch(void)
{
    while(!SSP1STATbits.BF) continue; // 受信待ち (BF = Buffer Full Status bit)
    PIR1bits.SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    return SSP1BUF; // SSP1BUF からデータを読み込むと SSP1STATbits.BF がリセットされます
}

#endif
