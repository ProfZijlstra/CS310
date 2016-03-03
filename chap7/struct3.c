#include <stdio.h>

typedef struct {
    int num;
    int denom;
} Fraction;

static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// constructor that ensures canonical representation
Fraction make_fraction(int n, int d) {
    Fraction x = {0, 1};
    if (n == 0) {
        return x;
    }
    if (d < 0) {
        n = -n;
        d = -d;
    } 
    int g = gcd(n,d);
    if (g != 1) {
        n /= g;
        d /= g;
    }
    
    x.num = n;
    x.denom = d;
    return x; 
}

void display_fraction(Fraction x) {
    printf(" %d/%d ", x.num, x.denom);
}

int equal_fraction(Fraction x, Fraction y) {
    return x.num == y.num && x.denom == y.denom;
}

int main() {
    Fraction fr = make_fraction(4,6);
    display_fraction(fr);
}

