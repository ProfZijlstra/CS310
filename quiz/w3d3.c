#include <stdio.h>

int main() {
    char buf[41];
    scanf("%40[a-zA-Z]", buf);
    puts(buf);
}
