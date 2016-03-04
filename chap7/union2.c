#include <stdio.h>

typedef union {
    int ival;
    float fval;
} Int_or_float;

int div_flag = 0;

Int_or_float divide(int a, int b) {
    div_flag = a % b;
    Int_or_float ans;
    if (div_flag == 0) {
        ans.ival = a / b;
    } else {
        ans.fval = a / (float) b;
    }
    return ans;
}

void test(int a, int b) {
    printf("%d/%d = ", a, b);
    Int_or_float x = divide(a,b);
    div_flag == 0 ? printf("%d\n", x.ival) 
                  : printf("%f\n", x.fval);  
}

int main() {
    test(8, 4);
    test(2, 3);
}


