#include "employee.h"
#include <stdio.h>

Employee::Employee() {
    name = "";
    time = 0;

    salary     = 0.00;
    department = "";
}

Employee::Employee(std::string name, std::string department, float salary) {
    this->name = name;
    this->time = 0;

    this->salary     = salary;
    this->department = department;
}

void
Employee::setName(std::string userName) {
    name = userName;
}

void
Employee::setSalary(float salary) {
    this->salary = salary;
}

void
Employee::setDepartment(std::string department) {
    this->department = department;
}

std::string
Employee::getName() {
    return name;
}

std::string
Employee::getDepartment() {
    return department;
}

float
Employee::getSalary() {
    return salary;
}

void
Employee::getTime() {
    printf("You've been with us for about.\n");
    printf(" Years: %u\n", time / 365);
    printf("Months: %u\n", time % 365 / 30);
    printf("  Days: %u\n", time % 365 % 30);
    printf("Thank you!\n");
}

void
Employee::advanceTime(unsigned int time) {
    this->time += time;
}

void
Employee::show() {
    printf("Name: %s.\n\tDepartment: %s.\n\tSalary: R$%.2f\n", 
            name.c_str(), department.c_str(), salary);
    getTime(); // this->getTime();
}
