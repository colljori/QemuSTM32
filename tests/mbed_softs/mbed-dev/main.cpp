#include "mbed.h"


int main() {
    while(1) {
        wait(0.3); // 200 ms
		int *p = (int*)0x2000E000;
		*p = 0xDEADCE11; 
        wait(1.0); // 1 sec
    }
}
