/**
* @file main.c
* @brief Main program body
*
* @date 22/04/2026
*
*/

/*** Includes ***/
#include <stdint.h>
#include "GPIO_stm32f4.h"
#include "led.h"
#include "push_button.h"

/*** Preprocessor Definitions ***/

/*** Type Prototypes ***/

/*** Local Variables ***/

/*** Global Variables ***/

/*** Function Prototypes ***/

/*** Function Definitions ***/

int main(void)
{
    /* Initialize the GPIO system */
    gpio_init();

    /* Initialize the led on pin 5 and button on pin 13 */
    led_init();
    button_init();

    while (1)
    {
        if (button_get_state() == 1)
        {
            led_toggle();
        }
    }

    return 0;
}