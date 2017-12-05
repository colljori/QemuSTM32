#include "mbed.h"

/*------------------------------------------------------------------------------
Before to use this example, ensure that you an hyperterminal installed on your
computer. More info here: https://developer.mbed.org/handbook/Terminals

The default serial comm port uses the SERIAL_TX and SERIAL_RX pins (see their
definition in the PinNames.h file).

The default serial configuration in this case is 9600 bauds, 8-bit data, no parity

If you want to change the baudrate for example, you have to redeclare the
serial object in your code:

Serial pc(SERIAL_TX, SERIAL_RX);

Then, you can modify the baudrate and print like this:

pc.baud(115200);
pc.printf("Hello World !\n");
------------------------------------------------------------------------------*/

DigitalOut led(LED1);

int main()
{
    int i = 1;

    printf("Hello World !\n");
}
