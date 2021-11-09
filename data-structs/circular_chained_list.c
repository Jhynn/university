#include <stdio.h>
#include <stdlib.h>


struct cell { // Célula.
    unsigned int id;
    // char *name;
    struct cell *next;
};


typedef struct circular_chained_list { // Lista encadeada circular.
    unsigned int counter;
    struct cell *first, *last;
} circular_list;

void 
initialize(struct circular_chained_list *list) {
    list->first = NULL;
    list->last = NULL;
    list->counter = 0;
}

void 
add(struct circular_chained_list *list, unsigned int key) {
    struct cell *new;
    new->id = key; new->next = NULL;

    if (list->first == NULL) {
        list->first = new; // O novo elemento é o único da lista.
        return;
    } else if (list->first->next == NULL) { // O novo será o segundo,
        list->last = new; // e último.
        list->first->next = new; // Primeiro aponta para o segundo e último.
        new->next = list->first;
        return;
    } else {
        list->last->next = new; // O último aponta para o novo.
        new->next = list->first;
        struct cell *aux;
        aux = list->first;
        while(aux->next != list->last){
            if (aux->next == list->last) {
                aux->next = new;
                break;
            }
            aux = aux->next;
        }
    }

    list->last = new; // O novo elemento se torna o último.
    new->next = list->first; // O último (novo) aponta para o primeiro.
    // list->counter++; // Conta os itens adicionados.
}

void 
remove_element(struct circular_chained_list *list, unsigned int key) {
    if (list->first == NULL) {
        printf("Lista vazia!");
        return;
    } 
    /* Não sei se funciona.
    else if (list->first->id == to_remove) { // Se o primeiro for o elemento.
        list->last->next = list->first->next; // Último aponta para o segundo.
        free(list->first); // Primeiro é excluso.
        // list->counter--; // Decrementa no total de elementos.
        list->first = list->last->next; // Segundo se torna o primeiro.
        return;
    }
    */
    struct cell *current, *predecessor; // Atual e seu antecessor.
    current = list->first; predecessor = list->first; 
    // Ambos são o primeiro elemento.

    do {
        if (current->id == key) {
            if (current == list->first) { // Se a key for o primeiro elemento.
                list->first = current->next; // O primeiro recebe o segundo.
                list->last->next = current->next; 
                // O último aponta para o segundo (primeiro).
                free(current); // Desaloca o (antigo) primeiro.
                // list->counter--; // Decrementa no total de elementos.
                return;
            } else {
                predecessor->next = current->next;
                if (current == list->last) { // Se a key for o último elemento.
                    list->last = predecessor; 
                    // Último recebe o anterior ao atual.
                }
                free(current); // Desaloca o atual.
                // list->counter--; // Decrementa no total de elementos.
                return;
            }
        } else {
            predecessor = current; // Antecessor recebe o atual.
            current = current->next; // Atual recebe o próximo.
        }
    } while (current != list->first);
}

void find_out(struct circular_chained_list *list, unsigned int key) {
    if (list->first == NULL) {
        printf("Lista vazia!");
    } else {
        struct cell *artifice;
        artifice = list->first;
        int not_found = 1; // Não encontrado -> verdadeiro.

        while(not_found) {
            if (artifice->id == key) {
                printf("Soldado %0d.", list->first->id);
                return;
            }
            artifice = artifice->next;
            if (artifice == list->first) {
                printf("Soldado não encontrado!");
                return; // Para, pois irá começar a dar loops.
            }
        }
    }
}

void to_show(struct circular_chained_list *list) { // Imprime a lista.
    if (list->first == NULL) {
        printf("Lista vazia!");
        return;
    }
    /*
    Usando o contador.

    unsigned int k = 0;
    while(k++ != list->counter) {
        printf("Soldado %0d.\n", list->first->id);
        list->first->next;
    }
    */
    struct cell *aux;
    aux = list->first;

    do {
        printf("Soldado %0d.\n", aux->id);
        aux = aux->next;
    } while (aux != list->first);
}

int
main(int argc, char const *argv[]) {
    circular_list list_test;
    initialize(&list_test);

    add(&list_test, 0); add(&list_test, 1);
    add(&list_test, 2); add(&list_test, 3);
    add(&list_test, 4); add(&list_test, 5);
    to_show(&list_test);

    remove_element(&list_test, 2);
    to_show(&list_test);

    remove_element(&list_test, 0);
    to_show(&list_test);

    return 0;
}
