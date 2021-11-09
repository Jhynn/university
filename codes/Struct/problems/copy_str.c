#include <stdio.h>

void
copy_string(char* from, char* to) {
    while (*from != '\0')
        *(to++) = *(from++);
    *to = '\0';
}

void
concat(char* str1, char* str2, char* str) {
    while (*str1 != '\0')
        *(str)++ = *(str1)++;

    while (*str2 != '\0')
        *(str)++ = *(str2)++;

    *str = '\0';
}

void
transpose(int** v) {
    int auxiliar;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("v[i][++j]: %d, v[++j][i]: %d\n", v[i][++j], v[++j][i]);
            auxiliar  = v[i][++j];
            v[i][++j] = v[++j][i];
            v[++j][i] = auxiliar;
        }
    }
}

int main(int argc, char const *argv[]) {
    char str1[] = "That's a test!";
    char str2[20];

    copy_string(str1, str2);
    printf("%s\n", str2);

    char part1[] = "This is ";
    char part2[] = "an example.";
    char complete[32];

    printf("%s%s\n", part1, part2);
    concat(part1, part2, complete);
    printf("%s\n", complete);

    // Transpose

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

    transpose(matrix); // Como a função tem como paramêtro um ponteiro,
                      // de ponteiro de inteiro, passamos o ponteiro matrix.

    printf("Transposta.\n"); // Impressão da matriz.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}

