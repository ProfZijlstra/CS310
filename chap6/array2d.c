#include <stdio.h>

int main() {
    int a[3][4];
    // initialize the space as '1d'
    int *p = &a[0][0];
    for (int i = 0; i < 12; i++) {
        //*(p + i) = i + 1;
        p[i] = i + 1;
    }
    
    // print using '2d'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int b[][4] = {{11,12,13,14}, {21,22,23,24}, {31,32,33,34}};
    // print using '1d'
    p = &b[0][0];
    for (int i = 0; i < 12; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

/*
int main() {
    int cols = 4;
    int rows = 2;
    int a[rows][cols];

    int *p = &a[0][0];
    int row = 1;
    int col = 3;
    a[row][col] = 50;
    printf("%d %d\n", *(p + (row * cols) + col), a[row][col]);
}*/

