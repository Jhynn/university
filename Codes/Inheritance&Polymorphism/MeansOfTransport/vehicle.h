#ifndef __means_of_transport_h
#define __means_of_transport_h

#include <string>

class Vehicle {
private:
    std::string  brand;
    std::string  model;
    float        speed;
    unsigned int wheels; // Wheels quantity of the vehicle.

public:
    Vehicle();
    Vehicle(std::string  brand, std::string  model,
            unsigned int wheels, float speed = 0);

    float        getSpeed();
    std::string  getBrand();
    std::string  getModel();
    unsigned int getWheels();

    void setSpeed(float currentSpeed);
    void setBrand(std::string newBrand);
    void setModel(std::string model);
    void setWheels(unsigned int updateWheels);

    void show();
    void toBreak(float intensity = 1);
    void speedUp(float intensity = 1);
};

#endif
