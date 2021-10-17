#include <stdio.h>

int
main(int argc, char const *argv[]) {
    // Instancia o ponteiro para arquivo.
    FILE* archive = fopen("DADOS.txt", "a");
    // NULL é uma área de memória que não temos permissão para sobreescrever.
    if (archive == NULL) // Aconteceu algum erro, pois
        return 1;        // o ponteiro não pôde ser instanciado.
    int numbers[10] = {4, 9, 8, 2, 3, 5, 7, 0, 6, 1};

    for (int i = 0; i < 10; i++)
        fprintf(archive, "%d, ", numbers[i]);
    fprintf(archive, "\n");
    // Em archive, vamos imprimir um decimal, %d, neste caso
    // numbers[i], como esta instrução está dentro de uma repetição,
    // então será mais de um decimal.

    fclose(archive); // Fecha o arquivo (sempre feche o arquivo).

    return 0; // Sim, este zero/falso,
              // significa que não aconteceu algum erro.
}
