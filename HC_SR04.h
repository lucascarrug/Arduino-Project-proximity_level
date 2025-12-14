#ifndef HC_SR04_H
#define HC_SR04_H

void setup_hc_sr04(const int trig, const int echo);
long calculate_distance(const int trig, const int echo);

#endif