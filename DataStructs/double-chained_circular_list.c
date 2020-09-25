#include <stdio.h>
#include <stdlib.h>

// Double-chained Circular List - Lista Circular duplamente encadeada

struct cell {
    int key;
    struct cell *previous;
    struct cell *next;
};

struct circular_list {
    struct cell *start;
    unsigned int counter;
};


void 
initialize(struct circular_list *list) {
    list->start = NULL;
    list->counter = 0;
}

int 
is_empty(struct circular_list *list) {
    return list->start == NULL;
}

void 
add(struct circular_list *list, int element) {
    struct cell *new = (struct cell*) malloc(sizeof(struct cell));
    new->key = element;
    if (list->start == NULL) {
        new->next = new->previous = new;
        list->start = new;
        list->counter++;
        return;
    } else {
        struct cell *aux = list->start;
        while(aux->next != list->start) {
            aux = aux->next;
        }
        aux->next = new;
        new->previous = aux;
        new->next = list->start;
        list->start->previous = new;
        list->counter++;
        return;
    }
}

int 
to_remove(struct circular_list *list, int element) {
    struct cell *aux = (struct cell*) malloc(sizeof(struct cell));
    aux = list->start;
    if (aux == NULL) {
        return 0;
    } else if (aux == NULL) {
        return 0;
    } do {
        if (aux->key == element) {
            aux->previous->next = aux->next;
            free(aux);
            list->counter--;
            return 1;
        }
        aux = aux->next;
    } while (aux != list->start);
    return 0;
}

void 
find_out(struct circular_list *list, unsigned int key) {
    if (list->start == NULL) {
        printf("Lista vazia!");
    } else {
        struct cell *artifice;
        artifice = list->start;
        int not_found = 1; // Não encontrado -> verdadeiro.

        while(not_found) {
            if (artifice->key == key) {
                printf("Soldado %0d.", list->start->key);
                return;
            }
            artifice = artifice->next;
            if (artifice == list->start) {
                printf("Soldado não encontrado!");
                return; // Para, pois irá começar a dar loops.
            }
        }
    }
}

void 
to_show(struct circular_list *list) {
    struct cell *aux = list->start;
    do {
        printf("%d\n", aux->key);
        aux = aux->next;
    } while (aux != list->start);
}

int 
josephus_problem(struct circular_list *list, int element, unsigned int number) {
    struct cell *aux = (struct cell*) malloc(sizeof(struct cell));
    unsigned int k = 0;
    if (aux == NULL) {
        return 0;
    } else {
        aux = list->start;
        do {
            if (aux->key == element) {
                break;
            }
            aux = aux->next;
        } while (aux != list->start);

        do {
            if (k == number) {
                to_remove(list, aux->key);
            }
        } while (k++ <= number);
        return 1;
    }

    return 0;
}

int 
main(int argc, char const *argv[]) {
    struct circular_list lista;

    initialize(&lista);
    add(&lista, 4);
    add(&lista, 9);
    add(&lista, 8);

    josephus_problem(&lista, 9, 6);
    to_show(&lista);

    return 0;
}
