#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int k, *p, **pp, v[5];
    printf("The size: %lu bytes.\n", sizeof(k));
    printf("Pointer: %lu\n", sizeof(p));
    printf("Pointer: %lu\n", sizeof(*pp[0]));
    printf("Vector: %lu\n", sizeof(v));

    return 0;
}
