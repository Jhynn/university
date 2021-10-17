#include "polar.hpp"
#include "spherical.hpp"
#include "cartesian.hpp"
#include "cylindrical.hpp"

// Acontece erros, não deveria, quando tenta converter!

int main(int argc, char const *argv[]) {
    Cartesian cartesian(4, 6, 9);
    printf("%s", cartesian.str("Cartesiana").c_str());

    Polar polar;
    polar = cartesian;
    printf("%s", polar.str("Polar").c_str());

    Cartesian cart(cartesian);
//    cart = polar;
    printf("%s", cart.str("Covertida").c_str());

    Cylindrical cylindrical(4, 265, 7);
    printf("%s", cylindrical.str("Cilindrica").c_str());

    Spherical spherical(9, 46, 78);
    printf("%s", spherical.str("Esférica").c_str());

    return 0;
}
