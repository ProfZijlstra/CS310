#include <stdio.h>

int main() {
    char buf[10];
    fgets(buf, 10, stdin);
    puts(buf);
}
