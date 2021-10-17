#include <stdio.h>

// Structures em C.
// Uma struct é um tipo, composto e, definido pelo o desenvolvedor.
// Uma structure define um tipo, que agrupa tipos primitivos ou outras
// structures, possibilitando um tipo mais
// adequado e elegante para solucionar o problema.

// Definindo uma structure...
// Palavra reservada struct, seguida do nome da estrutura.
struct address { 
    int   cep;
    char* name;   // Membros ou 
    char* street; // campos da
    char* city;   // structure.
    char* state;
}; // Struct é uma instrução, por isso o ";" em seu fim.

// Importante: structures não permitem que 
// membros/campos tenham valores padrão.

// Porque?
// Quando uma definição é feita, nenhuma memória é
// alocada para esta, memória só é alocada quando variáveis
// são criadas.

int
main(int argc, char const *argv[]) {
    // Criando um identificador para uma variável structure address...
    struct address example;

    // E inicializando, atribuindo valores para, os membros da structure.
    example.name   = "Marcela Lopes";
    example.street = "Ainda não sei...";
    example.city   = "Pedro II";
    example.state  = "Piauí";
    example.cep    = 12345678;

    typedef struct address Address; // struct address = Address
    // Você, também, pode instanciar um array ou ponteiro de structure.
    Address adresses[4];
    struct address* pointer;

    pointer     = &example; // Pointer recebe o endereço de memória de example.
    adresses[1] = *pointer; // Um elemento de adresses recebe o conteúdo de pointer.

    // Para acessar os campos da estrutura, usamos o operador ".".
    // Formas de acessar os membros, a partir de:
    printf("Nome..: %s\n", (*pointer).name);     // O conteúdo de um ponteiro.
    printf("Rua...: %s\n", pointer->street);     // Um ponteiro.
    printf("Cidade: %s\n", adresses[1].city);    // Um vetor (que é ponteiro).
    printf("Estado: %s\n", (adresses+1)->state); // (vetor+indice)->membro == vetor[indice].membro
    printf("CEP...: %d\n", (*(adresses+1)).cep); // *(vetor+indice) == vetor[indice]
    printf("CEP...: %d\n", example.cep);         // Uma estrutura, propriamente.

    return 0;
}
