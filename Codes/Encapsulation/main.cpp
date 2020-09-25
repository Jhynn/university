#include <string>
#include <stdio.h>

#include "clock.h"

int main(int argc, char const *argv[]) {
    Clock *clocks = new Clock[2];
    clocks[0].setTime(3600); // 1h
    clocks[0] + 60;          // 1m
    clocks[0] + 130;         // 2m10s
    clocks[0].show();
    printf("\n");

    clocks[1].setTime(7200); // 2h
    clocks[1] + 360;         // 6m
    clocks[1] + 170;         //2m50s
    clocks[1].show();
    printf("\n");

    Clock clock(3500);       // 58m20s
    clock.show();
    clock + 3360;

    clock.show();
    clock.proceede(8640);
    clock.show();

    clock - 3600;
    clock.show();

    delete[] clocks;

    return 0;
}
