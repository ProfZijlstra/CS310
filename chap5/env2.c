#include <stdio.h>

typedef char* String;
extern String* environ;

int main() {
    for (int i = 0; environ[i] != '\0'; i++) {
        printf("%s\n", environ[i]);
    }
}

