#include <stdio.h>
#include <assert.h>

int main() {
    int x = 9;
    int y = 8;

    assert(x == (y+1));
    printf("first\n");
    assert(x > y);
    printf("second\n");
    assert(x < y);
    printf("third\n");
}

