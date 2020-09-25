#include <iostream>
#include "elevator.h"

Elevator::Elevator(unsigned int elevator_capacity, unsigned int elevator_total_floors) {
        lift_capacity  = elevator_capacity;
        total_floors   = elevator_total_floors;
        present_people = 0;
        current_floor  = 0;
}

Elevator::~Elevator() {

}

unsigned int Elevator::getCurrentFloor() {
    return current_floor;
}

unsigned int Elevator::getPresentPeople() {
    return present_people;
}

void Elevator::goUp(unsigned int up_to) {
    if (current_floor != total_floors && up_to == 0) {
        current_floor++;
        return;
    }
    unsigned int aux = current_floor + up_to;

    if (aux <= total_floors)
        current_floor = aux;
}

void Elevator::enterTheElevator(unsigned int people) {
    if (present_people != lift_capacity && people == 0) {
        present_people++;
        return;
    }
    unsigned int aux = present_people + people;
    if (aux <= lift_capacity)
        present_people = aux;
}

void Elevator::skirt(unsigned int minus_people) {
    if (present_people > 0 && minus_people == 0) {
        present_people--;
        return;
    }
    signed int aux = present_people - minus_people;
    if (aux >= 0)
        present_people = aux;
}

void Elevator::goDown(unsigned int down_to) {
    if (current_floor != 0 && down_to == 0) {
        current_floor--;
        return;
    }
    signed int aux = current_floor - down_to;
    if (aux >= 0)
        current_floor = aux;
}

void Elevator::show() {
    std::cout << "Pessoas presentes: " << present_people << std::endl << \
    "Andar atual: " << current_floor << std::endl << "Último andar: " << total_floors << \
    std::endl << "Capacidade do Elevador: " << lift_capacity << \
    std::endl << "---------------------------" << std::endl;
}
