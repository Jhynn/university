#ifndef __bike_h
#define __bike_h

#include "vehicle.h"

class Bike : public Vehicle {
private:
    bool         luggageRack;  // Bagageiro.
    unsigned int gaitQuantity; // Quantidade de marchas.

public:
    Bike();
    Bike(bool luggageRack, unsigned int gait);

    void setLuggageRack(bool itHas);
    void setGaitQuantity(unsigned int howMany);

    bool         getLuggageRack();
    unsigned int getGaitQuantity();

    void show();
};

#endif
