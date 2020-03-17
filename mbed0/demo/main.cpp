#include "mbed.h"

void Led(DigitalOut& ledpin, int times);

DigitalOut redLED(LED_RED);

DigitalOut greenLED(LED_GREEN);

   
int Led(DigitalOut& ledpin);

   
int main()

{

   redLED = 1;

   greenLED = 1;

   while (true) {

       Led(redLED, 6);

       Led(greenLED, 4);

   }

}

void Led(DigitalOut& ledpin, int times)
{

   for(int i=0; i< times; ++i) { //blink for 10 times

       ledpin = !ledpin; // toggle led

       wait(0.2f);

   }
}
