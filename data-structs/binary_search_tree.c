#include <stdio.h>
#include <stdlib.h>

struct cell {
    unsigned int key;
    int value;
    struct cell *left, *right;

};

struct binary_search_tree {
    struct cell *root;
    unsigned int counter;
};

void
initialize(struct binary_search_tree *list) {
    list->root = NULL;
    list->counter = 0;
}

int
is_empty(struct binary_search_tree *list) {
    return list->root == NULL;
}

void
insert(struct binary_search_tree *list, int element) {
    if (list->root == NULL) {
        list->counter++;
        list->root->key = list->counter;
        list->root->value = element;
        list->root->left  = NULL;
        list->root->right = NULL;
        return;
    } else {
        struct cell* new_cell = (struct cell*) malloc(sizeof(struct cell));
        struct cell* artificie = (struct cell*) malloc(sizeof(struct cell));

        artificie = list->root;
        new_cell->value = element;
        new_cell->left  = NULL;
        new_cell->right = NULL;

        while (1) { // Não inserido.
            if (artificie->value == element) {
                printf("Elemento já salvo.");
                return;
            } else if (artificie->value < element) { 
                // Elemento maior que o valor atual!
                if (artificie->right == NULL) {     // Vai para à direita.
                    artificie->right = new_cell;
                    list->counter++;
                    new_cell->key = list->counter;
                    return;
                } else {
                    artificie = artificie->right;
                }
            } else {
                if (artificie->left == NULL) {
                    artificie->left = new_cell;
                    list->counter++;
                    new_cell->key = list->counter;
                    return;
                } else {
                    artificie = artificie->left;
                }
            }
        }
    }
}

int
find_out(struct binary_search_tree *list, int element) {
    if (is_empty(list)) {
        printf("Lista vazia!");
        return -1;
    } else {
        if (list->root->value == element) {
            return list->root->key;
        } else {
            if (element < list->root->value) {
                return find_out((struct binary_search_tree*) \
                    list->root->left, element);
            } else {
                return find_out((struct binary_search_tree*) \
                    list->root->right, element);
            }
        }
    }
}

struct cell*
find_out_cell(struct binary_search_tree *list, int element) {
    if (is_empty(list)) {
        printf("Lista vazia!");
        return NULL;
    } else {
        if (list->root->value == element) {
            return list->root;
        } else {
            if (element < list->root->value) {
                return find_out_cell((struct binary_search_tree*)\      
                    list->root->left, element);
            } else {
                return find_out_cell((struct binary_search_tree*)\
                    list->root->right, element);
            }
        }
    }
}

void
conclude(struct binary_search_tree *list) {
    if (!is_empty(list)) {
        conclude((struct binary_search_tree*) list->root->left);
        conclude((struct binary_search_tree*) list->root->right);
        free(list);
    } else if (list->root->left == NULL && list->root->right == NULL) {
        free(list->root);
    }   
}

void
remove_element(struct binary_search_tree *list, int element) {
    if (is_empty(list)) {
        printf("Lista Vazia!");
    } else {
        if (list->root->value == element) {
            conclude((struct binary_search_tree*) list->root);
            list->counter = 0;
        } else {
            struct cell* auxiliary = (struct cell*) malloc(sizeof(struct cell));
            auxiliary = list->root;
            if (element < auxiliary->value) {
                find_out_cell((struct binary_search_tree*) auxiliary->left, \
                    element);
            } else if (element > auxiliary->value) {
                find_out_cell((struct binary_search_tree*) \
                    auxiliary->right, element);
            } else {
                conclude((struct binary_search_tree*) auxiliary);
                list->counter--;
            }
        }
    }
}

void
to_show(struct binary_search_tree *list) {
    if (is_empty(list)) {
        printf("Lista vazia!");
        return;
    } else {
        printf("%d\n", list->root->value);
        to_show((struct binary_search_tree*) list->root->left);
        to_show((struct binary_search_tree*) list->root->right);
    }
}
/*
void to_show_a_cell(struct binary_search_tree* tree, int key) {
    if (is_empty(tree)) {
        printf("Lista vazia!");
    }
    struct cell* aux = (struct cell*) malloc(sizeof(struct cell));
    printf("Informações do Elemento:\n\tChave: %d \tValor: %d", aux->key, aux->value);
}
*/

int 
main(int argc, char const *argv[]) {
    struct binary_search_tree test_list;
    initialize(&test_list);
    insert(&test_list, 7);
    insert(&test_list, 4);
    insert(&test_list, 6);
    insert(&test_list, 3);
    insert(&test_list, 9);
    insert(&test_list, 10);
    insert(&test_list, 8);

    to_show(&test_list);
    remove_element(&test_list, 3);
    to_show(&test_list);
    remove_element(&test_list, 10);
    to_show(&test_list);
    find_out(&test_list, 4);
    remove_element(&test_list, 4);
    to_show(&test_list);
    conclude(&test_list);

    if(is_empty(&test_list))
        printf("A árvore está vazia!");

    return 0;
}
