#include "rational.hpp"


int
main(int argc, char const *argv[]) {
    Rational r;
    Rational a(79, 11), b(r);

    r.setAB(12, -36);
    printf("%s", r.str().c_str());

    a.setAB(-9, 4);
    b.setAB(13, 4);

    r = a + b;
    printf("%s", r.str().c_str());

    r = a - b;
    printf("%s", r.str().c_str());

    r = a * b;
    printf("%s", r.str().c_str());
/*
    r.setAB(4, -4);
    printf("%s", r.str().c_str());
*/

    a != b ? printf("São diferentes.\n") :
             printf("São iguais.\n");

    return 0;
}
