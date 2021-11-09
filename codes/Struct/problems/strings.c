#include <stdio.h>

void
concat_string(char* to, char* from) {
    // Traduções: 'to' significa 'para' e 'from' significa 'de'.
    // Enquanto o conteúdo do vetor 
    // for diferente do caractere terminador de string ('\0').
    while (*to != '\0')
        *(to)++;  // Avança em uma posição, e compara novamnete.

    // Então irá chegar no fim ('\0) da str, daí adiciona a outra
    // string em seu fim, na segunda repetição, concatenando-as.

    while (*from != '\0')
        *(to)++ = *(from)++;
    // Na posição em que to aponta é passado o conteúdo de from.
    *to = '\0'; // Por fim, adiciona o terminador de string.
}

int
main(int argc, char const *argv[]) {
    char part1[] = "I hope you had ";
    char part2[] = "understand, my dear Marcela.";

    printf("%s\n", part1); // String original.
    concat_string(part1, part2);
    printf("%s\n", part1); // String concatenada.

    return 0;
}
