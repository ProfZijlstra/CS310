#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s: needs a file name as argument\n", argv[0]);
        return -1;
    }
    FILE* update;
    if ( (update = fopen(argv[1], "r+")) == NULL) {
        fprintf(stderr, "%s: cannot open %s for updating\n", argv[0], argv[1]);
        return -2;
    }

    char c;
    int fpos;
    while ( (c = fgetc(update)) != EOF) {
        if (isupper(c)) {
            ungetc(c, update); // put character back into stream (go back 1)
            // flush by seeking
            fpos = ftell(update); // get current pos in file
            fseek(update, fpos, SEEK_SET); // goto that pos for writing
            fputc(tolower(c), update); // put lowercase in place
            // flush by seeking
            fpos = ftell(update); // get current pos in file
            fseek(update, fpos, SEEK_SET); // goto that pos for reading
        }
    }
    fclose(update);
}

