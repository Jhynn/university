#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int sold_cars;

    printf("Informe quantos carros você vendeu: ");
    scanf("%d", &sold_cars);

    float swag = 500 + 50*sold_cars; // Valor total das vendas.
    swag += .05*swag;

    printf("Você rendeu: R$%.2f", swag);

    return 0;
}
