#include "vehicle.h"
#include <stdio.h>

Vehicle::Vehicle()
{
    brand  = "Unknown";
    model  = "Unknown";
    speed  = 0;
    wheels = 2;
}

Vehicle::Vehicle(std::string  brand, std::string  model,
                 unsigned int wheels, float speed)
{
    this->brand  = brand;
    this->model  = model;
    this->wheels = wheels;
    this->speed  = speed;
}

// Get methods.
std::string Vehicle::getBrand()
{
    return brand;
}

std::string Vehicle::getModel()
{
    return model;
}

float Vehicle::getSpeed()
{
    return speed;
}

unsigned int Vehicle::getWheels()
{
    return wheels;
}

// Set methods.
void Vehicle::setBrand(std::string newBrand)
{
    brand = newBrand;
}

void Vehicle::setModel(std::string newModel)
{
    model = newModel;
}

void Vehicle::setSpeed(float currentSpeed)
{
    speed = currentSpeed;
}

void Vehicle::setWheels(unsigned int updateWheels)
{
    wheels = updateWheels;
}

void Vehicle::speedUp(float intensity)
{
    speed += intensity;
}

void Vehicle::toBreak(float intensity)
{
    speed -= intensity;
}

void Vehicle::show()
{
    printf("%s － %s:\n\tCurrent speed: %.3fKm/h,\n\tWheels quantity: %u.\n", 
            brand.c_str(), model.c_str(), speed, wheels);
}
