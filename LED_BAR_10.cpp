#include "LED_BAR_10.h"
#include "Arduino.h"

void setup_led_bar_10(const int *pins)
{
  for(int i=0; i<MAX_LED; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
  
  Serial.println("setup_led_bar_10 OK");
}


void turn_on_leds(const int *pins, const bool *leds_on)
{
  for(int i=0; i<MAX_LED; i++)
  {
    if (leds_on[i])
    {
      digitalWrite(pins[i], HIGH);
    }
    else
    {
      digitalWrite(pins[i], LOW);
    }
  }
}

void reset_leds(const int *pins)
{
  for(int i=0; i<MAX_LED;i++)
  {
    digitalWrite(pins[i], LOW);
  }
}