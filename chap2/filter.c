#include <stdio.h>

int main () {
    int c;
    // function prototypes can be declared inside other functions
    // Not considered particularly good style though
    int lower(int c); 

    // in C assignment operator returns a value that can be used
    while ( (c = getchar()) != EOF ) {
        putchar(lower(c));
    }
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 'a');
    }
    return c;
}

