#include <stdio.h>

int
main(int argc, char const *argv[]) {
    float number;
    printf("Informe o número: ");
    scanf("%f", &number);

    if (number < 0)  {
        printf("Número negativo.");
    } else if (number > 0) {
        printf("Número positivo.");
    } else {
        printf("Número é zero!");
    }

    return 0;
}
