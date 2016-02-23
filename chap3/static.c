#include <stdio.h>

void test_static() {
    static int test = 0;
    test++;
    printf("%d\n", test);
}

int main() {
    test_static();
    test_static();
}

