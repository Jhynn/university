#include "car.h"
#include <stdio.h>

Car::Car()
{
    this->numberOfDoors = 2;
}

Car::Car(unsigned int numberOfDoors)
{
    this->numberOfDoors = numberOfDoors;
}

void Car::setNumberOfDoors(unsigned int numberOfDoors) {
    this->numberOfDoors = numberOfDoors;
}

unsigned int Car::getNumberOfDoors() {
    return this->numberOfDoors;
}

void Car::show() {
    Vehicle::show();
    printf("\tNumber of Doors: %u.\n", this->numberOfDoors);
}
