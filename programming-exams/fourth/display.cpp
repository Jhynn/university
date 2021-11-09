#include "analitic_geometry.hpp"
// Matheus Miranda.
int
main(int argc, char const *argv[]) {
    Vector a(6, 3), b(3, 5), c(a), r;
    a.show();
    b.show();

    (a.sum(b)).show();

    r = b * 2;
    r.show();

    r.set(3, 4);
    printf("%lf\n", r.module());

    (a != a) ? printf("Diferentes.\n") : printf("Iguais.\n");

    return 0;
}
