/* lowercase filter, written with system calls*/
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
// stdio has #define BUFSIZ 1024 

int lower(char *buf, int length) {
    for (int i = 0; i < length; i++) {
        if (isupper(buf[i])) {
            buf[i] = tolower(buf[i]);
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    char buf[BUFSIZ];
    int nc = 0;
    int fd = -1;
    if ( (fd = open("lowerKase.c", O_RDONLY) == -1)) {
        perror("lowerKase.c");
        return -1;
    }

    while ( (nc = read(fd, buf, BUFSIZ)) > 0) {
        lower(buf, nc);
        nc = write(1, buf, nc);
        if (nc == -1) {
            break;
        }
    }
    if (nc == -1) {
        perror(argv[0]);
        return 1;
    }
    return 0;
}

