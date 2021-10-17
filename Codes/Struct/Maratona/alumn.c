#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int counter = 0;
    float score, average;
    
    while (counter++ < 4) {
        printf("Informe a %dª nota: ", counter+1);
        scanf("%f", &score);
        average += score;
    }

    average /= 4;

    if (average >= 7)
        printf("Aprovado, parabéns!");
    else if (average >=4)
        printf("Você está de exame final, estude.");
    else
        printf("Infelizmente, você reprovou.");

    return 0;
}
