int mystery(int a, int b, int (*fn)(int, int)) {
    return (*fn)(a,b);
}

int mystery(int a, int b, INT_FN fn) {
    return (*fn)(a,b);
}

