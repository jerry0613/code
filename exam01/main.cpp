#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
PwmOut PWM1(D6);


int main() {
    int i;

    //uLCD
    uLCD.printf("\n107061141\n");
    uLCD.rectangle(10, 20, 60, 70, 0xFFFFFF);

    //PWM
    PWM1.period(0.001);
    PWM1 = 0;

    while(1) {
        for (i = 0; i < 10; i++) {
            PWM1 = PWM1 + 0.1;
            wait(0.1);
        }
        for (i = 0; i < 10; i++) {
            PWM1 = PWM1 - 0.1;
            wait(0.1);
        }
    }

    
}