#include <stdio.h>

enum days {SUN, MON, TUE, WED, THU, FRI, SAT};

int main() {
    for (enum days x = SUN; x <= SAT; x++) {
        printf("%d\n", x);
    }
}

