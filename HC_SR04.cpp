#include "HC_SR04.h"
#include "Arduino.h"

void setup_hc_sr04(const int trig, const int echo)
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.println("setup_hc_sr04 OK");
}

long calculate_distance(const int trig, const int echo) 
{
  long duration, distance;

  // Send pulse.
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Recieve pulse.
  duration = pulseIn(echo, HIGH);

  // Calculate distance.

  // vel_sound = 343 m/s = 1/29.2 cm/us
  // x = v/t*2
  // distance = 1/(29.2 * 2 * t)
  distance = ((duration * 10) / 292) / 2;

  return distance;
}