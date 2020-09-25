#include <iostream>
#include "person.h"

Person::Person() {
    name = "";
    cpf  = cep = 0;
}

Person::Person(std::string user_name, unsigned int cep, unsigned int cpf) {
    name = user_name;
    cpf  = cep = 0;
}

Person::~Person() {
    //delete this;
}

void
Person::setName(std::string user_name) {
    name = user_name;
}

std::string
Person::getName() {
    return name;
}

void
Person::setCpf(unsigned int long user_cpf) {
    cpf = user_cpf;
}

void
Person::setCep(unsigned int user_cep) {
    cep = user_cep;
}

unsigned long int
Person::getCpf() {
    return cpf;
}

unsigned int
Person::getCep() {
    return cep;
}

void
Person::show() {
    if (!name.empty()) std::cout << "Nome: " << name << std::endl;
    std::cout << "CPF: " << cpf << "\nCEP: " << cep << std::endl;
}
