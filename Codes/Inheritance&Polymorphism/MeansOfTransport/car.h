#ifndef __car_h
#define __car_h

#include "vehicle.h"

class Car : public Vehicle
{
private:
    unsigned int numberOfDoors;
public:
    Car();
    Car(unsigned int numberOfDoors);

    void setNumberOfDoors(unsigned int numberOfDoors);
    unsigned int getNumberOfDoors();

    void show();
};

#endif
