#include <stdio.h>
#include <stdlib.h>
#define size 10

struct element {
    unsigned int value;
};

typedef struct sequencial_chained_list {
    unsigned int length;
    struct element list[size];
} chained_list;


void 
initialize(chained_list *list) {
    list->length = 0; // A lista inicia com tamanho 0.
}

int 
isEmpty(const chained_list *list) {
    return list->length == 0; // Se o tamanho da lista for igual a 0.
}

int 
isFull(const chained_list *list) {
    return list->length >= size; // Se o tamanho da lista for maior ou igual a size.
}

void 
clean_list(chained_list *list) {
    list->length = 0;
}

int 
insert(chained_list *list, unsigned int index, int value) {
    if (isFull(list) || index >= size || index < 0) return 0;

    list->list[index].value = value;
    list->length++;

    return 1;
}

int 
sorted_insert(chained_list *list, int value) {
    int position = 0;

    while (position < list->length && value > list->list[position].value)
        position++;

    return insert(list, position, value);
}

int 
find_out(chained_list *list, int value) {
    for (unsigned int i = 0; i < list->length; i++) {
        if (list->list[i].value == value) {
            return i;
        }
    }

    return -256;
}

int 
binary_search(chained_list *list, int value) {
    int above, middle, below;
    if (!isEmpty(list)); {
        below = 0, above = list->length -1;
        while (below <= above) {
            middle = (above + below) /2;
            if (list->list[middle].value == value) {
                return middle;
            } else if (list->list[middle].value < value) {
                below = middle +1;
            } else {
                above = middle -1;
            }
        }
    }
    return list->list[list->length-1].value; // Ultimo elemento.
}

void 
remove_element(chained_list *list, unsigned int index) {
    /*
    for (int i = 0; i < size; i++) {
        if (list->list->key == index) {
            
        }
    }
    */
}

void 
to_show(chained_list *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d\n", list->list[i].value);
    }
}

int 
main(int argc, char const *argv[]) {
    chained_list chain_lis;
    initialize(&chain_lis);
    insert(&chain_lis, 0, 4);
    insert(&chain_lis, 1, 94);
    insert(&chain_lis, 2, 48);
    insert(&chain_lis, 3, 47);
    insert(&chain_lis, 4, 44);

    to_show(&chain_lis);

    return 0;
}
