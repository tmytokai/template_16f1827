//
// シリアル通信
//
#include "setting.h"

#ifdef USE_UART

// UART 初期化
void init_uart(void)
{
    // 送受信制御レジスタ初期化
    TXSTA = 0x00;
    RCSTA = 0x00;

    // ピン設定
    APFCON0bits.RXDTSEL = 1; // RB2(8 pin) を RX とする
    APFCON1bits.TXCKSEL = 1; // RB5(11 pin) を TX とする
    TRISB = TRISB | 0b00000100; // RX(8 pin) を入力モードにする
    RCSTAbits.SPEN=1; // TX と RX を有効にする
    
    // ボーレート設定
    // SYNC=0, BRG16=1, BRGH=1 の場合 rate = FOSC/(4*([SPBRGH:SPBRGL]+1))
    TXSTAbits.SYNC = 0; // 非同期モード
    BAUDCONbits.BRG16 = 1; // 16bit ボーレートジェネレータ使用
    TXSTAbits.BRGH = 1; // 高速モード
    SPBRGH = 0;
    SPBRGL = 8; // 通信速度 = (4*10^6)/(4*(8+1)) = 111111.1 ≒ 115200

    // 送信設定    
    TXSTAbits.TX9 = 0;  // 8bit送信
    TXSTAbits.TXEN = 1; // 送信許可
    PIE1bits.TXIE = 0; // 送信割り込み無し

    // 受信設定
    RCSTAbits.RX9 = 0;  // 8bit受信
    RCSTAbits.CREN = 1; // 受信許可
    PIE1bits.RCIE = 0; // 受信割り込み無し
}

// USART で 1 byte 送信
void putch(char data)
{
    while(!PIR1bits.TXIF) continue; // 送信可になるまで待つ
    
    TXREG = data; // 1文字送信
}

// USART で 1 byte 受信
// 文字を受信していない時やエラーの時は EOF を返す
#if __XC8_VERSION < 2000
char getch(void)
#else
int getch(void)
#endif
{
    if(!PIR1bits.RCIF) return EOF; // 受信バッファが空

    // エラーが起きたらリセット
    if( RCSTAbits.FERR==1 || RCSTAbits.OERR==1){
        RCSTAbits.CREN=0;
        NOP();
        NOP();
        RCSTAbits.CREN=1;
        return EOF;
    }
    
    return RCREG;
}

#endif