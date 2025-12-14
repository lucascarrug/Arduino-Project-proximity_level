#ifndef LED_BAR_H
#define LED_BAR_H

#define MAX_LED 10

void setup_led_bar_10(const int *pins);
void turn_on_leds(const int *pins, const bool *leds_on);
void reset_leds();

#endif