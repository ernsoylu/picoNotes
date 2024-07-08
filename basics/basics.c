#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/sendHello/sendHello.h"


int main()
{
    stdio_init_all();

    while (true) {
        sendHello();
        sleep_ms(1000);
    }
}
