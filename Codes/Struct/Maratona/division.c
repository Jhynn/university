#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int numerator, denominator;

    printf("Informe um numerador: ");
    scanf("%f", &numerator);

    if (!numerator) {
        printf("0 / n = 0");
        return 0;
    }

    printf("Informe um denominador: ");
    scanf("%f", &denominator);

    while (!denominator) {
        printf("Informe outro denominador, \
                não existe divisão por zero.");
        scanf("%f", &denominator);
    }

    printf("%f / %f = %f", numerator, \
        denominator, numerator / denominator);

    return 0;
}
