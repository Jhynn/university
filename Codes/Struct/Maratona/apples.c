#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int my_apples;

    printf("Quantas maçãs você comprou? ");
    scanf("%d", &my_apples);

    if (my_apples < 12)
        my_apples *= 1.3; // Custo das maçãs.

    printf("Você deve pagar R$%.2f", my_apples);

    return 0;
}
