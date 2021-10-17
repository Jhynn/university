#include <stdio.h>

int
main(int argc, char const *argv[]) {
    int born_year, current_year;

    printf("Informe o ano atual: ");
    scanf("%d", &current_year);

    printf("Informe o ano de seu nascimento: ");
    scanf("%d", &born_year);

    if (current_year + 1 - born_year > 17)
        printf("Você pode votar proximo ano!");    
    else
        printf("Você não pode votar proximo ano!");

    return 0;
}
