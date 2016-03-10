#include <stdlib.h>
#include <stdio.h>

int main() {
    char cmd[80];
    sprintf(cmd, "cp %s %s\n", "wait.c", "w.c");
    system(cmd);
}

