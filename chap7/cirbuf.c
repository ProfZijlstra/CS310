#include "cirbuf.h"
#include <stdlib.h>
#include <stdio.h>

#define EMPTY_CIR(bp) (bp->length == 0)
#define FULL_CIR(bp) (bp->length == bp->size)

Cirbuf make_cirbuf(unsigned int max) {
    Cirbuf b = {NULL, 0, 0, 0};
    b.size = max;
    b.buf = (char*) malloc(max*sizeof(char));
    return b;
}

int produce(char c, Cirbuf* bp) {
    if (FULL_CIR(bp)) {
        fprintf(stderr, "produce: buffer full\n");
        return -1;
    }

    bp->buf[bp->tail] = c;
    bp->tail++;
    bp->length++;
    if (bp->tail == bp->size) {
        bp->tail = 0; // wrap around
    }
    return 0;
}

int consume(Cirbuf* bp) {
    if (EMPTY_CIR(bp)) {
        fprintf(stderr, "consume: buffer empty\n");
        return -1;
    }

    char c = bp->buf[bp->head];
    bp->head++;
    bp->length--;
    if (bp->head == bp->size) {
        bp->head = 0; // wrap around
    }
    return c;
}

int isempty(Cirbuf* bp) {
    return EMPTY_CIR(bp);
}

int isfull(Cirbuf* bp) {
    return FULL_CIR(bp);
}

void delete_cirbuf(Cirbuf b) {
    free(b.buf); 
}

