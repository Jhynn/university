#include "automobile.h"
#include <stdio.h>

Automobile::Automobile() : Vehicle()
{
    enginePower = 0;
}

Automobile::Automobile(float power) : Vehicle()
{
    enginePower = power;
}

void Automobile::setEnginePower(float power) {
    enginePower = power;
}

float Automobile::getEnginePower() {
    return enginePower;
}

void Automobile::show() {
    Vehicle::show();
    printf("\tEngine power: %.3f.\n", enginePower);
}
