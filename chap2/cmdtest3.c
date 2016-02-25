#include <stdio.h>
int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        char *j = argv[i];
        while (*j!= '\0') {
            printf("%c", *j);
            j++;
        }
        printf("\n");
    }
}
