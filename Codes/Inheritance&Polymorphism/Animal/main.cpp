#include "cat.hpp"
#include "ox.hpp"
#include "shark.hpp"
#include "whale.hpp"

#include "animal.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int quantity = 0;
    Animal* anyone[quantity];

    anyone[quantity++] = new Ox("Bovino");
    anyone[quantity++] = new Cat("Felina");
    anyone[quantity++] = new Shark("Tubarão");
    anyone[quantity++] = new Whale("Baleia");

    for (unsigned int i = 0; i < quantity; i++) {
        cout << "Nome.....: " << anyone[i]->getName() << endl;
        cout << "Movimento: " << anyone[i]->getMove() << endl;
    //  cout << "Sound....: " << anyone[i]->getSound() << endl;
        cout << "Ambiente.: " << anyone[i]->getEnvironment() << endl;
        cout << endl;
    }

    delete[] anyone;

    return 0;
}
