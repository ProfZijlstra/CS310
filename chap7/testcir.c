#include <stdio.h>
#include "cirbuf.h"

int main() {
    Cirbuf x = make_cirbuf(5);
    produce('C', &x);
    produce('+', &x);
    produce('U', &x);
    produce('N', &x);
    int i;
    for (i = 0; i < 3; i++) {
        printf("%c", consume(&x));
    }
    produce('I', &x);
    produce('X', &x);
    for (i = 0; i < 3; i++) {
        printf("%c", consume(&x));
    }
    delete_cirbuf(x);
}


