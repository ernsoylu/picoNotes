#include <stdio.h>
#include "pico/stdlib.h"



int main()
{
    stdio_init_all();
    //Initialize GPIO pin 22
    gpio_init(22);
    // Set GPIO22 as output
    gpio_set_dir(22, true);

    //We can select multiple GPIO pins with binary mask
    //For example in order to select GPIO Pin 3 we need to send 100 in binary which means third bit of the mask is one
    //We can automatically done this with bit shifting function in binary operations
    //For 3rd pind we need do shift 1 in 3rd place with 1<<3
    //To select multiple pin we can use bitwise operations, we use | (or) operator to select multiple pins
    //According to this description we can select 3rd and 5th pin with (1<<3)|(1<<5)
    uint32_t sel_mask = (1<<3)|(1<<5)|(1<<7)|(1<<9);
    //Initialize masked pins
    gpio_init_mask(sel_mask);
    //Mask for output pins 3 and 7
    uint32_t out_mask = (1<<3)|(1<<7)|(1<<9);
    //Set direction to mask pins
    gpio_set_dir_masked(sel_mask, out_mask);
    //To enable a gpio pin as an input
    //We assign simple in and out function to the pin
    gpio_set_function(5,GPIO_FUNC_SIO);
    gpio_set_dir(5,false);
    //If you are connecting button directly to PIN use internal pull-down resistor.
    gpio_pull_down(7);

    while (true) {
        //GPIO ON AND OFF
        gpio_put(22,true);
        sleep_ms(500);
        gpio_put(22,false);
        sleep_ms(500);
        //GPIO ON AND OFF WITH MASK
        gpio_set_mask(out_mask);
        sleep_ms(700);
        gpio_clr_mask(out_mask);
        sleep_ms(700);
        if(gpio_get(5)==1){
            gpio_put(9, true);
        } else {
            gpio_put(9, false);
        }
        
    }
}
