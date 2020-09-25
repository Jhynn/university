#include "motocycle.h"
#include <string>
#include <stdio.h>

Motocycle::Motocycle()
{
    Vehicle();
    electricTrigger = true;
}

Motocycle::Motocycle(bool electricTrigger)
{
    Vehicle();
    this->electricTrigger = electricTrigger;
}

void Motocycle::setElectricTrigger(bool itHas) {
    electricTrigger = itHas;
}

bool Motocycle::getElectricTrigger() {
    return electricTrigger;
}

void Motocycle::show() {
    Vehicle::show();
    std::string itHas = electricTrigger ? "yes" : "no";
    printf("\tElectric trigger: %s.\n", itHas.c_str());
}
