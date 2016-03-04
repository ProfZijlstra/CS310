#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int head;
    void** array;
} ArrayList;

ArrayList* ArrayList_construct() {
    ArrayList *a = (ArrayList*) malloc(sizeof(ArrayList));
    a->size = 10;
    a->head = 0; // length
    a->array = malloc(10 * sizeof(void*));
    return a;
}

void ArrayList_desctruct(ArrayList* a) {
    free(a->array); 
}

void ArrayList_add(ArrayList* a, void* item) {
    if (a->head == a->size) {
        // create a new array with double the space
        void** morespace = malloc(a->size * 2 * sizeof(void*));
        // copy all the stuff into the first half
        memcpy(morespace, a->array, a->size * sizeof(void*));
        // free the old array
        free(a->array);
        // replace it with the new one
        a->array = morespace;
        a->size *= 2;
        printf("Resized to: %d\n", a->size);
    } 
    a->array[a->head] = item;
    a->head++;
}

void* ArrayList_get(ArrayList* a, int idx) {
    if (idx >= a->head) {
        return NULL; 
    }
    return a->array[idx];
}

int ArrayList_remove(ArrayList* a) {
    if (a->head == 0) {
        return -1;
    } 
    a->head--; 
    return 0;
}

int ArrayList_remove_idx(ArrayList* a, int idx) {
    if (idx >= a->head) {
        return -1;
    }
    // move everything from index to head one space left
    // essentially destroying the item that was at idx
    for (int i = idx; i < a->head -1; i++) {
        a->array[i] = a->array[i+1];
    }
    a->head--;
    return 0;
}

int* Integer_construct(int n) {
    int* p = malloc(sizeof(int));
    *p = n;
    return p;
}


int main() {
    ArrayList *a = ArrayList_construct();
    for (int i = 0; i < 100; i++) {
        ArrayList_add(a, (void*)Integer_construct(i));
    }
    for (int i = 0; i < a->head; i++) {
        int* data = (int*) ArrayList_get(a, i);
        printf("%d ", *data);
    }
}
