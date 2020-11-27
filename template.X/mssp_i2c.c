//
// I2Cマスターモード
//
// 1827は MSSP(Master Synchronous Serial Port)モジュールを2つ(MSSP1、MSSP2)積んでいますので
// SPI または I2C を2系統同時に扱えます
//
#include "setting.h"

#ifdef USE_MSSP1_I2C

// MSSP1 初期化
void init_mssp1_i2c(void)
{
    // MSSP1 の I2C マスターモードでは SCL1 (10 ピン)と SDA1 (7 ピン)を使います
    
    TRISB = TRISB | 0b00010010; // I2CマスターモードではSCL1とSDA1(=RB1,4)を入力モードにします

    SSP1STAT = 0b10000000; // 100kHzモード(SMP=1)
    SSP1CON1 = 0b00101000; // SDA1/SCL1有効(SSP1EN=1)、I2Cマスターモード(SSP1M=0b1000)
    SSP1CON2 = 0x00;
    SSP1CON3 = 0x00;
    SSP1MSK = 0x00;
    SSP1ADD = 19; // FOSC/(4*clock)-1 = 8000k/400k-1 = 19
}

// MSSP1 で start condition 送信
void mssp1_i2c_start(void) 
{
    SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    SSP1CON2bits.SEN = 1; // Start Condition 送信開始
    while(SSP1CON2bits.SEN==1) continue; // 処理が終わるとハードが SEN = 0、SSP1IF = 1 にします
}

// MSSP1 で stop condition 送信
void mssp1_i2c_stop(void)
{
    SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    SSP1CON2bits.PEN = 1; // Stop Condition 送信開始
    while (SSP1CON2bits.PEN==1) continue; // 処理が終わるとハードが PEN = 0、SSP1IF = 1 にします
}

// MSSP1 で 1 byte 送信
void mssp1_i2c_putch( char data )
{ 
    SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    SSP1BUF = data; // バッファにデータをセットするとハードが送信開始します
    while (SSP1IF == 0) continue; // 処理が終わるとハードが SSP1IF = 1 にします

    // デバッグ用
    //printf("send %c\r\n",data);
    //if(SSP1CON2bits.ACKSTAT == 0) printf("ack\r\n");
    //else printf("nack\r\n");
}

// MSSP1 で 1 byte 受信
// nack = 1 : NACK 送信
// nack = 0 : ACK  送信
int mssp1_i2c_getch( unsigned char nack )
{
    int data = 0;

    SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    SSP1CON2bits.RCEN = 1; // 受信開始
    while (SSP1IF == 0) continue; // 処理が終わるとハードが RCEN = 0、SSP1IF = 1 にします
    data = SSP1BUF;

    // ACK/NACK 送信
    SSP1IF = 0; // 割り込みフラグは自動ではリセットされないので手動でリセットします
    SSP1CON2bits.ACKDT = nack; // 1をセットするとNACKを送る
    SSP1CON2bits.ACKEN = 1; // 送信開始
    while (SSP1IF == 0) continue; // 処理が終わるとハードが ACKEN = 0、SSP1IF = 1 にします

    return data;
}

#endif
