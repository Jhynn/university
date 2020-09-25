#include <iostream>
#include "cars.h"

Car::Car() {
    km_l      = 0;
    fuel_tank = 0;
}

Car::~Car() {

}

void Car::show() {
    std::cout << "Combustivel:    " << fuel_tank << std::endl;
    std::cout << "Km percorridos: " <<    km_l   << std::endl;
}

void Car::driveUp(int km) {
    int i;
    for (i = 0; i < km; i++) {
        if (i % 15 == 0)
            fuel_tank--;

        if (fuel_tank == 0) {
            km_l = i;
            km_l = km / fuel_tank;
            std::cout << "Sem combustivel." << std::endl;
            return;
        }
    }
    km_l = i;
}

void Car::refuelTank(float liters) {
    fuel_tank += liters;
    if (fuel_tank > 50.0) fuel_tank = 50;
}
