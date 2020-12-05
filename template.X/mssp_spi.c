//
// SPI マスターモード
//
// 1827は MSSP(Master Synchronous Serial Port)モジュールを2つ(MSSP1、MSSP2)積んでいますので
// SPI または I2C を2系統同時に扱えます ※ ピン配置の関係で同時に使えない組み合わせもあります
//
#include "setting.h"

#ifdef USE_MSSP1_SPI

// MSSP1 を SPI マスターモードで初期化
//
// デフォルトでは SPIモード0 で初期化します
// ビットオーダーはデフォルトで MSBFIRST (らしい)です
// クロックは 1 MHz です
//
void init_mssp1_spi(void)
{
    // MSSP1 の SPI マスターモードでは SCK1 (10 ピン)と SDI1 (7 ピン)を使います
    // SDO1 は 8 ピンと 15 ピンのどちらかを指定できます
    APFCON0bits.SDO1SEL = 1; // 15 ピンを SDO1 とします
    TRISB = TRISB | 0b00000010; // マスターモードでは SDI1 (RB1,7ピン)を入力モードにします

    SSP1CON1 = 0x00;
    SSP1STAT = 0x00;
    SSP1CON2 = 0x00;
    SSP1CON3 = 0x00;

    char CKP = 0, CKE = 1; // mode0
    SSP1CON1bits.SSPM = 0b1010; // SPIマスターモード
    SSP1CON1bits.CKP = CKP;
    SSP1STATbits.CKE = CKE;
    SSP1STATbits.SMP = 0; // タイミングが合わなかったら1にする
    SSP1CON1bits.SSPEN = 1; // MSSPモジュール ON
    SSP1ADD = 1; // クロック = 1MHz ( FOSC/(4*clock)-1 = 8 MHz/4M-1 = 1 )
}

// MSSP1 で SPIモードを変更
//
// (参考) SPIモード、CPOL/CPHA、CKP/CKE 対応表
//
// SPIモード0 :
// アイドル時ロー極性    : CPOL = 0 または CKP = 0
// 立上がり時サンプリング: CPHA = 0 または CKE = 1
//
// SPIモード1 :
// アイドル時ロー極性    : CPOL = 0 または CKP = 0
// 立下がり時サンプリング: CPHA = 1 または CKE = 0
//
// SPIモード2 :
// アイドル時ハイ極性    : CPOL = 1 または CKP = 1
// 立下がり時サンプリング: CPHA = 0 または CKE = 1
//
// SPIモード3 :
// アイドル時ハイ極性    : CPOL = 1 または CKP = 1
// 立上がり時サンプリング: CPHA = 1 または CKE = 0
//
void mssp1_spi_setmode(char mode)
{
    char CKP = 0, CKE = 1; // mode0
    if(mode==1){ CKP = 0; CKE = 0; }
    if(mode==2){ CKP = 1; CKE = 1; }
    if(mode==3){ CKP = 1; CKE = 0; }

    SSP1CON1bits.CKP = CKP;
    SSP1STATbits.CKE = CKE;
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
