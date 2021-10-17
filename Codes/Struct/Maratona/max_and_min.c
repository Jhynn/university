#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int counter = 0;
    float min, max, number;

    printf("Informe um número: ");
    scanf("%f", &number);

    min = max = number;

    while (counter++ < 9) {
        if (number > max)
            max = number;
        else if (number < min)
            min = number;

        printf("Informe um número: ");
        scanf("%f", &number);
    }
    printf("Menor valor informado: %f", min);
    printf("Maior valor informado: %f", max);

    return 0;
}
