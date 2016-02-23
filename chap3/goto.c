#include <stdio.h>

void example_goto() {
    goto places;
somewhere:
    printf("I'm somewhere\n");
places:
    printf("I'm going places\n");
    goto somewhere;
}

int main() {
    example_goto();
}
