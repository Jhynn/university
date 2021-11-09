#include <stdio.h>
#include <string.h>

void
encrypt(char* phrase, char* encrypted, int pass) {
    while (*phrase != '\0')
        *(encrypted++) = (*(phrase++) + pass);
    *encrypted = '\0';
}

void
decrypt(char* encrypted, char* decrypted, int pass) {
    while (*encrypted != '\0')
        *(decrypted++) = (*(encrypted++) - pass);
    *decrypted = '\0';
}

int
main(int argc, char const *argv[]) {
    puts("Enter a phrase, please.");
    char string[] = "";
    fgets(string, 256, stdin);
    int proper_size = strlen(string);   // Tamanho adequado.

    char auxiliar[proper_size];
    char artificie[proper_size];

    // printf("%s\n", string);             // Original.

    encrypt(string, auxiliar, 3);       // Encrypted.
    printf("%s\n", auxiliar);

    decrypt(auxiliar, artificie, 3);    // Decrypted.
    printf("%s\n", artificie);

    return 0;
}
