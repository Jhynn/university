#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct cell { // Estrutura célula.
    Data value;
    struct cell *above; // Ponteiro para a célula que está acima.
};

struct stack { // Estrutura pilha.
    struct cell *base, *top; // Estruturas base e topo (acesso direto).
    unsigned int size;       // Tamanho.
};

void initialize(struct stack *user_stack) { // Inicializa a pilha.
    user_stack->base = NULL; // A base é nula, porque não tem valores
    user_stack->size = 0;   // definidos pelo o usuário. E o tamanho é zero.
}

int is_empty(struct stack *user_stack) { // Verifica se a pilha está vazia.
    return user_stack->base == NULL;     // Verdadeiro se a base é nulo.
}

void stack_up(struct stack *user_stack, Data value) { // Empilhar.
    if (is_empty(user_stack)) {           // Se a pilha estiver vazia.
        user_stack->base->value = value; // A base (primeiro elemento) recebe o valor.
        user_stack->top = user_stack->base; // E também se torna o topo da pilha.
        user_stack->base->above = NULL;     // Acima dela tem valor nulo.
        user_stack->size++;                 // A pilha cresce.
        return;                             // Abondona a função.
    } else {
        struct cell *aux;
        aux = user_stack->base;
        do {
            aux = aux->above; // aux vai se tornar um elemnto nulo.
        } while (aux->above != NULL);
        aux->value = value; // Então recebe o valor que o usuário inseriu.
        aux->above = NULL;  // Acima dele tem valor nulo.
        user_stack->top = aux; // E ele se torna o topo da pilha.
        user_stack->size++;   // A pilha cresce.
    }
}

void withdraw(struct stack *user_stack) { // Retirar (Desempilhar).
    if (is_empty(&user_stack)) {
        return; // Se a pilha estiver vazia, sai da função.
    }
    free(user_stack->top); // Desaloca o elemento que está no topo da pilha.
    user_stack->size--;    // Decrementa o tamanho da pilha.

    unsigned int limit = user_stack->size; // O limite é igual ao tamanho da pilha.
    struct cell *aux;
    aux = user_stack->base;

    while (limit-- > 0)
        aux = aux->above;    // O aux será o elemento que está no topo da pilha.
    user_stack->top = aux;   // E é definido como tal.
    user_stack->top = NULL; // O topo aponta para nulo.
}

void to_show(struct stack *user_stack) { // Imprime a pilha.
    if (is_empty(&user_stack)) {
        return; // Se a pilha estiver vazia, abondona a função.
    }

    struct cell *auxiliary;
    auxiliary = user_stack->base;
    do {
        printf("%d\n", auxiliary->value); // Imprime o valor atual de auxiliar.
        auxiliary = auxiliary->above;     // Auxiliar recebe o elemnto acima dele.
    } while (auxiliary != NULL);          // Quando for nulo para a repetição.
}
