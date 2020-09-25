#include <iostream>
#include "air_conditioner.h"

AirConditioner::AirConditioner() {
    air_conditioned  = 0;
    room_temperature = 0;
}

AirConditioner::~AirConditioner() {

}

void AirConditioner::toConditioner(unsigned int power_value) {
    air_conditioned = room_temperature - power_value * 1.8;
}

void AirConditioner::setRoomTemperature(float user_room_temperature) {
    room_temperature = user_room_temperature;
}

void AirConditioner::show() {
    std::cout << "Temperatura ambiente:     " << room_temperature << std::endl;
    std::cout << "Temperatura condicionada: " << air_conditioned  << std::endl;
}
