#include <stdio.h>
#include "clock.h"

Clock::Clock(unsigned int time_in_secs) {
    hours   = 0;
    minutes = 0;
    seconds = 0;

    proceede(time_in_secs);
}

void 
Clock::setTime(unsigned int timeInSeconds) {
    proceede(timeInSeconds);
}

void 
Clock::proceede(int advance_seconds) {
    seconds += advance_seconds;

    if (seconds > 59)
    {
        seconds  = advance_seconds % 3600 % 60;
        minutes += advance_seconds % 3600 / 60;
        hours   += advance_seconds / 3600;
    }

    if (minutes > 59)
    {
        hours  += minutes / 60;
        minutes = advance_seconds % 3600 / 60;
    }

    if (hours > 23)
        hours = advance_seconds / 3600 / 60;
}

void 
Clock::show() {
    printf("%02dh%02dm%02ds\n", hours, minutes, seconds);
}

void 
Clock::operator+(int sec) {
    proceede(sec);
}

void 
Clock::operator-(int sec) {
    proceede(sec * -1);
}
