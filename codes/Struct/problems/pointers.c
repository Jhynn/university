#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int v[5] = {10, 20, 30, 40, 50};
    int* pv  = &v[1]; // Endereço do segundo elemento do vetor v.
    int* ppv = (v+4); // Endereço do último elemento do vetor v.

    for (int i = 0; i < 5; i++)
        printf("%d, ", v[i]);
    printf("\b\b "); // retorna (com \b) duas colunas e sobreescreve
                     // a vírgula com um espaço em branco.
    printf("\n%d - %d\n", *pv, *ppv);

    return 0;
}
