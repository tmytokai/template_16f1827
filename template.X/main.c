#include "config.h"
#include "setting.h"

void main(void){

    init();

    while(1){
        RA0 = 1;
        __delay_ms(1000);
        RA0 = 0;
        __delay_ms(1000);
    }

   return;
}
