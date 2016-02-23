int power(int a, int n) {
    int i, ans = 1;
    for (i = 1; i <=n; i++) {
        ans *= a;
    }
    return ans;
}
