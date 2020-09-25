#include <stdio.h>
#include <stdlib.h>
#define len 6

struct cell {
    int value;
    struct cell *next;
};

struct linked_list {
    int counter;
    struct cell *first, *last;
};

void initialize(struct linked_list* list) {
    list->first = list->last = NULL;
    list->counter = 0;
}

int is_empty(struct linked_list* list) {
    return list->first == NULL;
}

void add(struct linked_list* list, int element) {
    struct cell *new;
    //new = (struct cell*) malloc(sizeof(struct cell));
    new->value = element;
    new->next = NULL;

    if (list->first == NULL) {
        list->first = new;
        list->counter++;
        return;
    }
    
    list->last = new;
    list->counter++; // list->++counter = list->last;
}

void remove(struct linked_list* list, int element) {
    if (is_empty(list)) {
        printf("Lista vazia!");
        return;
    }

    struct cell* aux = list->first;
    if (list->first->value == element) { // Remove o primeiro elemento.
        aux = aux->next;
        free(list->first->value);
        return;
    }

    while(list->first->next != NULL) {
        if (list->first->value == element) {
            aux->next = list->first->next; // Faz a anterior apontar para outra
            list->counter--;              // célula duas vezes à sua frente.
            free(list->first->value);
        }
        list->first->next;
    }
}

void to_show(struct linked_list *list) {
    while(list->first->value != NULL){
        printf("Valor: %d.", list->first->value);
        list->first->next;
    }
}

int main(int argc, char const *argv[]) {
    struct linked_list list;
    initialize(&list);

    return 0;
}
