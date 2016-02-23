int monotonic(int a[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (a[i+1] < a[i]) {
            break;
        }
    }
    if (i == n -1) {
        return 1; // increasing
    }
    for (i = 0; i < n - 1; i++) {
        if (a[i+1] > a[i]) {
            return 0; // not monotonic
        }
    }
    return 1; // decreasing
}
