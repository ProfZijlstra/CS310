#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char *buf = (char *)calloc(1024, sizeof(char));
    fgets(buf, 1023, stdin);
    puts(strtok(buf, " \n\r\t\f"));
    puts(strtok(NULL, " \n\r\t\f"));
    puts(strtok(NULL, " \n\r\t\f"));
    puts(strtok(NULL, " \n\r\t\f"));
    puts(strtok(buf, " \n\r\t\f"));
}
