int sum_squares(int n) {
    int sum, i;
    sum = i = 1;
    n *= 2;
    while ( (i += 2) < n ) {
        sum += (i * i);
    }
    return sum;
}
