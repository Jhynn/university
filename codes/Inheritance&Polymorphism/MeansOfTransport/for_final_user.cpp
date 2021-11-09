#include "vehicle.h"
#include "bike.h"
#include "automobile.h"

#include "motocycle.h"
#include "car.h"
#include <string>

int main(int argc, char const *argv[]) {
    Car test;
    test.setModel("CLA-250");
    test.setSpeed(20);
    test.show();

    test.setBrand("AMG-Mercedes");
    test.setNumberOfDoors(4);
    test.speedUp(189);
    test.setWheels(4);
    test.show();

    return 0;
}
