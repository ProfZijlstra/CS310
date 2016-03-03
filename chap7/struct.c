#include <stdio.h>

struct fraction {
    int num;
    int denum;
};

int main() {
    struct fraction fr = {2,3};
    printf("num: %d denum: %d\n", fr.num, fr.denum);
}
