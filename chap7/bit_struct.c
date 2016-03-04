#include <stdio.h> 

struct access {
    unsigned int o_x : 1;
    unsigned int o_w : 1;
    unsigned int o_r : 1;
    unsigned int g_x : 1;
    unsigned int g_w : 1;
    unsigned int g_r : 1;
    unsigned int u_x : 1;
    unsigned int u_w : 1;
    unsigned int u_r : 1;
};

struct abc {
    unsigned int uu : 3;
    signed   int vv : 4;
};

int main() {
    struct abc x;
    x.uu = 0xB;
    x.vv = 0x3;
    if (x.uu == x.vv) {
        printf("Same!\n");
    }
}
