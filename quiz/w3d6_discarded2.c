#include <stdio.h>
#include <string.h>

int main() {
    char fname[101];
    printf("name: ");
    scanf("%100s", fname);

    FILE* file = fopen("names.txt", "r+");
    char buf1[101];
    char* s = fgets(buf1, 100, file);
    while (s != NULL && strcmp(fname, buf1) < 0) {
        s = fgets(buf1, 100, file);
    }

    char buf2[101];
    int r = fread(buf2, 100, 1, file);
    fprintf(file, "%s\n", fname);

    char *b1 = buf1;
    char *b2 = buf2;
    char *temp;
    while (r != 0) {
        fwrite(b1, strlen(buf1), 1, file);
        r = fread(b1, 100, 1, file);
        temp = b1;
        b1 = b2;
        b2 = temp;
    }
}
