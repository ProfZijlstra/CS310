#include <stdio.h>

void test_switch(int n) {
    switch(n) {
        case 1:
            printf("case 1\n");
        case 2:
            printf("case 2\n");
            break;
        default:
            printf("Neither case 1 or 2\n");
    }
}

int main() {
    test_switch(1);
    test_switch(2);
    test_switch(3);
}

