#ifndef __motocycle_h
#define __motocycle_h

#include "vehicle.h"

class Motocycle : public Vehicle {
private:
    bool electricTrigger;

public:
    Motocycle();
    Motocycle(bool electricTrigger);

    void setElectricTrigger(bool itHas);
    bool getElectricTrigger();

    void show();
};

#endif
