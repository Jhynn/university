#include "point.hpp"
// Alinne Grazielle & Matheus Miranda.
using namespace std;

int
main(int argc, char const *argv[]) {
    Point p1(4, 9);
    Point p2(p1);
    Point p3;

    double d[2];
    p1.distance(p2, d);
    cout << "A distancia é: " << d[0] << " nas abscissas"
         << "e " << d[1] << " nas ordenadas." << endl;
    
    cout << "P1: ";
    p1.show();

    cout << "P2: ";
    p2.show();
    
    cout << "P3: ";
    p3.show();

    p3.movimentar(p2);
    cout << "P3: ";
    p3.show();
    

    p2.movimentar(7, -9);
    p2.show();

    p2 += p3;
    p2.show();

    if (p1 == p2)
        cout << "São iguais." << endl;
    else
        cout << "São diferentes." << endl;

    p2.clone(p1);

    if (p1 == p2)
        cout << "São iguais." << endl;
    else
        cout << "São diferentes." << endl;

    return 0;
}
