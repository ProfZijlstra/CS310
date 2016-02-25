#include <stdio.h>

void example_goto() {
    goto places;
somewhere:
    printf("I'm somewhere\n");
    goto end;
places:
    printf("I'm going places\n");
    goto somewhere;
end:
    return;
}

int main() {
    example_goto();
}
