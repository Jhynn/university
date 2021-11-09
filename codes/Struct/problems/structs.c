#include <stdio.h>

struct Person {
    char* name; // Ponteiro para char, uma 'string'.
    int   age;  // Idade.
    float swag; // Ganhos.
};

void
ler_pessoa(struct Person* person) {
    // Como o paramêtro person é um ponteiro para struct Person,
    // então devemos usar o operador seta (->) ou (*ponteiro).campo.
    // (->) = (*ponteiro).campo, a seta deixa o código mais limpo e elegante.
    // *ponteiro.campo, é errado porque ponteiro não possui campos.
    // (*ponteiro) significa que você está usando o conteúdo de quem ele aponta,
    // neste caso, uma struct Person, ou seja, você está usando a própria struct.
    printf("%s.\n", (*person).name);        // Por isso, isto, funciona.
    printf("%d springs.\n", person->age);   // Mas assim é mais elegante
    printf("U$%.2f\n", person->swag);       // e intuitivo.
}

int
main(int argc, char const *argv[]) {
    struct Person marcela;
    marcela.name = "Marcela Lopes";
    marcela.age  = 17;    // Acho que estou certo.
    marcela.swag = 6000;  /* Espero que seja o suficiente,
                             em doláres, é claro. */
    ler_pessoa(&marcela); // Passamos o endereço de memória.
                          // Pois o paramêtro da função é um ponteiro.

    return 0;
}
