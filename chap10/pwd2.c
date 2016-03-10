#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char name[30];
    getcwd(name, 29);
    printf("%s\n", name);
}


