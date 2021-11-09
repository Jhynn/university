#include "bike.h"
#include <string>
#include <stdio.h>

Bike::Bike() : Vehicle() {
    luggageRack  = false;
    gaitQuantity = 24; // 3 coroas e 8 catracas.
}

Bike::Bike(bool luggageRack, unsigned int gait) : Vehicle() {
    gaitQuantity      = gait;
    this->luggageRack = luggageRack;
}

void
Bike::setGaitQuantity(unsigned int howMany) {
    gaitQuantity = howMany;
}

void
Bike::setLuggageRack(bool itHas) {
    luggageRack = itHas;
}

unsigned int
Bike::getGaitQuantity() {
    return gaitQuantity;
}

bool
Bike::getLuggageRack() {
    return luggageRack;
}

void
Bike::show() {
    Vehicle::show();
    std::string itHas = luggageRack ? "yes" : "no";

    printf("\tLuggage rack: %s,\n\tGait quantity: %u\n", \
            itHas.c_str(), gaitQuantity);
}
