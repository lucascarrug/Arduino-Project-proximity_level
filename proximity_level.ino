#include "HC_SR04.h"
#include "LED_BAR_10.h"
#include "config.h"

const int led_pins[10] = {L0, L1, L2, L3, L4, L5, L6, L7, L8, L9};

long cm;
bool leds_on[10] = {false,false,false,false,false,false,false,false,false,false};


void setup() 
{
  Serial.begin(115200);
  setup_hc_sr04(TRIG, ECHO);
  setup_led_bar_10(led_pins);
}

void loop() 
{
  cm = calculate_distance(TRIG, ECHO);
  Serial.print("Distancia: ");
  Serial.println(cm);

  calculate_leds_by_distance(cm, leds_on);

  turn_on_leds(led_pins, leds_on);

  delay(500);
}


void calculate_leds_by_distance(const long distance, bool *leds_on)
{
  // Checks limits.
  if (distance < 3)
  {
    for(int i=9; i>=0; i--) leds_on[i] = true;
    return;
  }

  if (distance > 50)
  {
    for(int i=9; i>=0; i--) leds_on[i] = false;
    return;
  }

  // Calculate proximity.
  int proximity_level = map(distance, 3, 50, 0, 9);

  // Reset leds.
  for(int i=9; i>=0; i--)
  {
    leds_on[i] = true;
  }

  // Set leds.
  for(int i=0; i<=proximity_level; i++)
  {
    leds_on[i] = false;
  }
} 
