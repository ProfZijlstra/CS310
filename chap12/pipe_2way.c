#include <unistd.h>
#include <stdio.h>
#include <string.h>

int pipe_2way(char *cmd[], int piped[]) {
    int wt[2];
    int rd[2];
    pipe(wt); // outgoing pipe, write to child
    pipe(rd); // incoming pipe, read from child
    int pid;
    if ( (pid=fork()) == 0) {
        close(wt[1]);
        dup2(wt[0], 0); // child stdin now wt[0]
        close(wt[0]);
        close(rd[0]);
        dup2(rd[1], 1); // child stdout now rd[1]
        close(rd[1]);
        execv(cmd[0], cmd);
        perror("execv failed"); // should not happen
        _exit(1);
    }
    // in parent
    close(wt[0]);
    piped[1] = wt[1];
    close(rd[1]);
    piped[0] = rd[0];
    return 0;
}

int readl(int fd, char s[], int size) {
    int i, r;
    for (i = 0; i < size - 1; i++) {
        r = read(fd, &s[i], 1);
        if (r == 0 || s[i] == '\n') {
            break;
        }
    }
    s[i+1] = '\0';
    return i;
/*
    char* tmp = s;
    while (0 < --size 
            && read(fd, tmp, 1) != 0 
            && *tmp++ != '\n');
    *tmp = '\0';
    return tmp - s;
*/
}

#define SIZE 256
int main() {
    char test_string[] = "This is a TEST with UPPERCASE characterS\n";
    char buf[SIZE];

    // start our 2way pipe with the lowercase cmd
    char* str[2];
    str[0] = "./lowercase";
    str[1] = NULL;
    int pd[2];
    pipe_2way(str, pd);

    write(pd[1], test_string, strlen(test_string)); // write to child
    readl(pd[0], buf, SIZE);                        // read from child
    printf("Received from lowercase:\n%s", buf);
}

