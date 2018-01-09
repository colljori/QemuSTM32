#include "mbed.h"
 
Ticker timer;
DigitalOut led1(LED1);
DigitalOut led2(LED2);
 
int flip = 0;
 
void attime() {
	flip = !flip;
}
 
int main() {
	timer.attach(&attime, 0.5);
 
	while(1) {
		if(flip==0)
			led1 = !led1; 
		else
			led2 = !led2;
	}
}
