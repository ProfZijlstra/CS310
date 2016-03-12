#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("name: ");
    char name[101];
    scanf("%100s", name);

    // read all the names
    FILE* file = fopen("names.txt", "r+");
    char* names[1000];
    char buf[101];
    char *res;
    res = fgets(buf, 100, file);
    int i = 0;
    while (res != NULL && i < 1000) {
        names[i] = malloc(strlen(buf) * sizeof(char));
        strcpy(names[i], buf);
        res = fgets(buf, 100, file);
        i++;
    }

    if (i == 1000) {
        printf("Too bad, we're full\n!");
        exit(1);
    }

    // write the names that come before the given back into beginning
    fseek(file, 0, SEEK_SET); // 0 bytes from begin (begin = SEEK_SET)
    int j;
    for (j = 0; j < i; j++) {
        if (strcmp(name, names[j]) < 0) {
            break;
        }
        fputs(names[j], file);
    }
    // then write current name
    fprintf(file, "%s\n",name);

    // then write remaining names
    while (j < i) {
        fputs(names[j], file);
        j++;
    }
}
