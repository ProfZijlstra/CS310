// Write a program that uses the std library functions
// to count the chacters from user input, using a 1024
// sized buffer

#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024


int main() {
    char buf[BUFSIZE];
    fgets(buf, BUFSIZE - 1, stdin);
    printf("Characters read: %d\n", (int)strlen(buf));
}
