#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char* name;
    name = getcwd(NULL, 0);
    printf("%s\n", name);
    free(name);
}


