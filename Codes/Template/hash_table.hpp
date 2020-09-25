#ifndef __hash_table_hpp_
#define __hash_table_hpp_

#include <new>
#include <stdio.h>

struct cell {
    int          value;
    bool         notUsed;
    unsigned int identifier;
    struct cell* next;
};

typedef struct cell Cell;

class HashTable {
private:
    Cell** vector;
    int    quantity;
private:
    int index(int identifier) {
        return 4 * identifier % 11;
    }
public:
    HashTable() {
        quantity = 0;
    }

    void
    insert(int element) {
        int aux = index(quantity);
        if (vector[aux]->notUsed) {
            vector[aux]->next       = NULL;
            vector[aux]->value      = element;
            vector[aux]->notUsed    = false;
            vector[aux]->identifier = quantity++;
        } else {
            Cell *penultimate = new Cell;

            if (!penultimate)
                throw std::bad_alloc();

            penultimate = vector[aux];

            while (!penultimate->next->notUsed)
                penultimate = penultimate->next;
            
            penultimate->next->next       = NULL;
            penultimate->next->value      = element;
            penultimate->next->notUsed    = false;
            penultimate->next->identifier = quantity++;
            
            penultimate->next = penultimate;
        }
    }

    void
    remove(int id) {

    }

    Cell*
    findOut(int id) {
        int aux = index(id);
        return;
    }
};

#endif
