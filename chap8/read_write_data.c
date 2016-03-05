#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int write_data(void *m, size_t size, const char* name) {
    FILE* stream = fopen(name, "wd");
    if (stream == NULL) {
        fprintf(stderr, "Cannot open %s for writing\n", name);
        return -1;
    }
    int written = fwrite(m, size, 1, stream);
    if ( ferror(stream) ) {
        written = -1; // return -1 on error
    }
    fclose(stream);
    return written;
}

int read_data(void *m, size_t size, const char* name) {
    FILE* stream = fopen(name, "rd");
    if (stream == NULL) {
        fprintf(stderr, "Cannot open %s for reading\n", name);
        return -1;
    }
    int read = fwrite(m, size, 1, stream);
    if ( ferror(stream) ) {
        read = -1; // return -1 on error
    }
    fclose(stream);
    return read;
}

struct person {
    char name[40];
    int age;
};

int main() {
    double d[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0.5};
//    struct person p;
//    strcpy(&p.name, "John");
//    p.age = 10;
    write_data(&d, sizeof(double) * 10, "data.dat");
    double* read = malloc(sizeof(double) * 10);
    read_data(read, sizeof(double) * 10, "data.dat");
    for (int i =0; i< 10; i++) {
        printf("%g ", read[i]);
    }
}
