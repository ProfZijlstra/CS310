#include <stdio.h>
#include <stdlib.h>

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

int *matmul(const int* x, const int* y, int r, int s, int t){
    int *matrix = (int*) malloc(r * t * sizeof(int));
    int *z = matrix;
    for (int i=0; i < r; i++) {
        x += i*s;
        for (int j=0; j < t; j++) {
            *z = rtc(x, y+j, s, t);
            z++;
        }
    }
    return matrix;
}

int main() {
    int a[2][3] = {{1, -2, 5}, {1, 2, 3}};
    int b[3][2] = {{9, 7}, {-2, 3}, {-1, 4}};
    //matmul(&a[0][0], &b[0][0], &c[0][0], 2, 3, 2);
    int *c = (int*) matmul(*a, *b, 2, 3, 2);
    int row = 3;
    printf("( %d  %d )\n( %d  %d )\n", 
            *(c + row*0 + 0), *(c + row*0 + 1), *(c + row*1 + 0), *(c + row*1 + 1));
}

