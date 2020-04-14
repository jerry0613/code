#include "mbed.h"

Serial pc( USBTX, USBRX );
AnalogIn Ain(A0);
AnalogOut Aout(DAC0_OUT);
DigitalIn  Switch(SW3);
DigitalOut redLED(LED1);
DigitalOut greenLED(LED2);
BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);

char table[20] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
                  0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF};

int main(){
    int freq = 0;
    int i, hun, ten, un, sample = 500;
    float ADCdata[sample];

    for (i = 0; i < sample; i++) {
            ADCdata[i] = Ain;
            wait(1./sample);
    }

    for (i = 0, freq = 0; i < sample; i++) {
            if (ADCdata[i] < 0.303 && ADCdata[i + 1] >= 0.303)
                freq++;
        }

    while(1){
        for (i = 0; i < 100; i++) {
            Aout = 0.5*sin(2*3.1415926/100 * i) + 0.5;
            wait(0.01/freq);
        }

        if(Switch == 0){
            greenLED = 0;
            redLED = 1;

            hun = freq / 100;
            display = table[hun];
            wait(0.5);

            ten = ((int)freq % 100) / 10;
            display = table[ten];
            wait(0.5);

            un = (int)freq % 10;
            display = table[un + 10];

            for (i = 0; i < 512; i++){
                pc.printf("%1.3f\r\n", ADCdata[i]);
            }
        } else {
            greenLED = 1;
            redLED = 0;
            display = 0;
        }

        
    }
}