#include "rational.hpp"


int
main(int argc, char const *argv[]) {
    Rational r, a, b;

    /*
     * a.setAB(1, 6);
     * b.setAB(5, 6);
     * r = a * b;
    */

    r.setAB(5, 36);
    printf("%s", r.str().c_str());

    return 0;
}
