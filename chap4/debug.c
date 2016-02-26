#include <stdio.h>

int main() {
    printf("in main\n");
#ifdef DEBUG
    printf("debugging is on\n");
#else
    printf("debugging is off\n");
#endif

}
