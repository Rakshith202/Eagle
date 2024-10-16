#include "header.h"

float calculate_cycle_time(struct time start, struct time stop) 
{
    int start_minutes = start.hour * 60 + start.minute;
    int stop_minutes = stop.hour * 60 + stop.minute;
    
    int difference = stop_minutes - start_minutes;
    
    float cycle_time = difference / 60.0;
    
    return cycle_time;
}

