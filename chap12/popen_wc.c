#include <stdio.h>
// call wc for multiple files
// note that wc itself can do this
int main(int argc, char* argv[]) {
    char cmd[80];
    int count = 0;
    int total = 0;
    FILE* in;
    for (int i = 1; i < argc; i++) {
        sprintf(cmd, "wc -w %s\n", argv[i]);
        in = popen(cmd, "r");
        fscanf(in, "%d", &count);
        total += count;
        pclose(in);
    }
    printf("total count is %d words\n", total);
}

