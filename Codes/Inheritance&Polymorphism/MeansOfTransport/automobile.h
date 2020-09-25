#ifndef __automobile_h
#define __automobile_h

#include "vehicle.h"

class Automobile : public Vehicle
{
private:
    float enginePower;

public:
    Automobile();
    Automobile(float power);

    void  setEnginePower(float power);
    float getEnginePower();

    void show();
};

#endif
