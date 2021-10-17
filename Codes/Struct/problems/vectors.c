#include <stdio.h>

void
transpor(int** v) {
    int proper_size = sizeof(**v)*sizeof(*v[0]);
    // Tamanho (quantidade de elementos) da matriz.
    int k[proper_size], z = 0;
    // k é um vetor com a mesma capacidade de armazenamento da matriz.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            k[z++] = v[i][j]; // e possui todos os elementos da matriz.
    }

    for (int l = 0; l < 4; l++) {
        z = l; // O valor de z é atualizado, para o inicio da linha, a cada interação.
        for (int m = 0; m < 4; m++) {
            v[l][m] = k[z]; // Possibilitando que os valores sejam correspodentes, ou seja,
                            // 1ª linha recebe todos os valores da 1ª coluna.
                            // 2ª linha recebe todos os valores da 2ª coluna e assim por diante.
            z += 4; // O tamanho da linha é: quatro unidades, então
                    // a cada 4 saltos é o inicio da proxima linha.
                    // E adicionamos esse valor na coluna atual.
        }
    }
}

int
main(int argc, char const *argv[]) {
    int line1[4] = {1, 1, 1, 1};
    int line2[4] = {2, 2, 2, 2};
    int line3[4] = {3, 3, 3, 3};
    int line4[4] = {4, 4, 4, 4};

    int* matrix[4] = {line1, line2, line3, line4};

    printf("Original.\n"); // Impressão da matriz.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }

    transpor(matrix); // Como a função tem como paramêtro um ponteiro,
                      // de ponteiro de inteiro, passamos o ponteiro matrix.

    printf("Transposta.\n"); // Impressão da matriz.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
