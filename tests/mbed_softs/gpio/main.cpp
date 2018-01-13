#include "mbed.h"

DigitalOut myled(LED1);

int main() {
    uint32_t gpio_port_mask = gpio_set(PA_0);
    gpio_t obj;
    gpio_init(&obj, PA_0);
    gpio_mode(&obj, PullDefault);
     
    gpio_dir(&obj, PIN_INPUT);

    int write_value = 1234;

    gpio_write(&obj, write_value);

    int read_value = gpio_read(&obj);

    if (write_value == read_value) {
        while(1) {
            myled = 1; // LED is ON
            wait(0.2); // 200 ms
            myled = 0; // LED is OFF
            wait(1.0); // 1 sec
        }    
    } else {
        myled = 0;
    }

}
