#include <stdio.h>

// helper: row times column
static int rtc(const int* row, const int* col, int s, int t) {
    int sum = 0;
    while ( s-- > 0) {
        sum += *row * *col;
        row++;
        col += t;
    }
    return sum;
}

void matmul(const int* x, const int* y, int* z, int r, int s, int t){
    for (int i=0; i < r; i++) {
        x += i*s;
        for (int j=0; j < t; j++) {
            *z = rtc(x, y+j, s, t);
            z++;
        }
    }
}

int main() {
    int a[2][3] = {{1, -2, 5}, {1, 2, 3}};
    int b[3][2] = {{9, 7}, {-2, 3}, {-1, 4}};
    int c[2][2];
    //matmul(&a[0][0], &b[0][0], &c[0][0], 2, 3, 2);
    matmul(*a, *b, *c, 2, 3, 2);
    printf("( %d  %d )\n( %d  %d )\n", 
            c[0][0], c[0][1], c[1][0], c[1][1]);
}

