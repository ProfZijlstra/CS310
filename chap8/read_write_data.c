#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_data(void *m, size_t size, const char* name) {
    FILE* stream = fopen(name, "wb");
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
    FILE* stream = fopen(name, "rb");
    if (stream == NULL) {
        fprintf(stderr, "Cannot open %s for reading\n", name);
        return -1;
    }
    int read = fread(m, size, 1, stream);
    if ( ferror(stream) ) {
        read = -1; // return -1 on error
    }
    fclose(stream);
    return read;
}

int main() {
    double d[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0.5};
    int w = write_data(d, sizeof(double) * 10, "data.dat");
    printf("written: %d\n", w);

    double* read = malloc(sizeof(double) * 10);
    int r = read_data(read, sizeof(double) * 10, "data.dat");
    printf("read: %d\n", r);

    for (int i =0; i< 10; i++) {
        printf("%g ", read[i]);
    }
    printf("\n");
}

