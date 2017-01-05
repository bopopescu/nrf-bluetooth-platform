#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"

const uint8_t leds_list[5] = {18,19,20,21,22};

int main(void) {
  uint8_t i;
  uint8_t counter = 0;
  uint32_t pins;
  nrf_gpio_cfg_input(16,NRF_GPIO_PIN_NOPULL);
  for (i=0;i<5;i++) nrf_gpio_cfg_output(leds_list[i]);  
  while (true) {
    nrf_delay_ms(1000);
    counter++;
    for (i=0;i<5;i++) {
      if (counter & (1<<i)) nrf_gpio_pin_set(leds_list[i]);
      else nrf_gpio_pin_clear(leds_list[i]);
      }
    pins = nrf_gpio_pin_read(16);     
    if (!pins) counter = 0;
    }
  }
