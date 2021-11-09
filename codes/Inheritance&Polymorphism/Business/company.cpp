#include "company.h"
#include <stdio.h>

unsigned int Company::id = 1;

Company::Company() {
    name = "";
    this->id++;
    employees[0] = NULL;
}

Company::Company(std::string companyName) {
    this->id++;
    this->name = companyName;
    employees[0] = NULL;
}

void
Company::setName(std::string newName) {
    name = newName;
}

std::string
Company::getName() const {
    return name;
}

unsigned int
Company::getId() const {
    return id;
}

void
Company::toHire(Employee &employee) {
    employeesQuantity++;

    for (int i = 0; i < employeesQuantity; i++) {
        if (employees[i] == NULL) {
            employees[i]   = &employee;
            employees[++i] = NULL;
            return;
        }
    }
}

void
Company::toDismiss(std::string employeeName) {
    int i = 0;
    while (i++ != employeesQuantity) {
        if (employees[i]->getName().c_str() == employeeName.c_str()) {
            employees[i] = NULL;
            employeesQuantity--;
            return;
        }
    }
}

void
Company::toSubsidize(std::string department, float percents) {
    if (percents > 1)
        percents /= 100;
    else if (percents < 0) // Realmente deve existir?
        return;

    for (int i = 0; i < employeesQuantity; i++) {
        if (employees[i]->getDepartment().c_str() == department.c_str()) {
            employees[i]->setSalary(employees[i]->getSalary() 
            + percents * employees[i]->getSalary());
        }
    }
}

void
Company::show() {
    for (int i = 0; i < employeesQuantity; i++) {
        printf("%s.\n", employees[i]->getName().c_str());
        printf("\t%s.\n", employees[i]->getDepartment().c_str());
        printf("\t%.2f\n", employees[i]->getSalary());
    }
}

void
Company::info() {
    if (name == "")
        name = "Desconhecido";

    printf("%s.\n", name.c_str());
    printf("Possui %d funcionários.\n\n", employeesQuantity);
}
