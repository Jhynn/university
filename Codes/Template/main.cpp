#include <iostream>

#include <vector>
#include "contact.hpp"

using namespace std;


int
main(int argc, char const *argv[]) {
    std::vector<Contact> collection;
    int option = 5;
    
    do {
        cout << "1. Cadastrar novo contato."     << endl;
        cout << "2. Ver informações do contato." << endl;
        cout << "3. Atualizar contato."          << endl;
        cout << "4. Excluir contato."            << endl;
        cout << "5. Sair do menu."               << endl;
        cin  >> option;

        if (0 >= option || option >= 5) {
            option = 5;
        }

        switch (option) {
            case 1:
                cout << "Por favor informe o nome: " << endl;
                std::string n;
                cin >> n;

                cout << "Por favor informe o numero: " << endl;
                std::string np;
                cin >> np;

                collection.insert(Contact(n, np));
                break;

            default:
                break;
        }
    } while (option != 5);

    return 0;
}
