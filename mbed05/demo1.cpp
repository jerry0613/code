#include "mbed.h"

Timer t;
DigitalOut blueLED(LED3);

int main() {
    t.start();

    while(1) {
        if (t.read() >= 0.5) {
            blueLED = !blueLED;
            t.reset();
        }
        
    }
}