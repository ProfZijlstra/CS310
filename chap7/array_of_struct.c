#include <string.h>

typedef struct {
    char *cur; // currency name
    float amt; // exchange rate
} Rate;

Rate table[] = {
    {"British Pound", 0.71},
    {"Euro", 0.92},
    {"Japanese Yen", 113.81}
};

#define TABLEN (sizeof(table) / sizeof(table[0]))

// use binary search to locate entry
Rate *find_entry(char *cur) {
    int low = 0;
    int high = TABLEN - 1;
    int mid;
    int test;
    while (low <= high) {
        mid = (high + low) / 2;
        test = strcmp(cur, table[mid].cur);
        if (test == 0) {
            return table + mid;
        } else if (test > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL; // no exchange rate found
}

// find the exchange rate for a given name
float ex_rate(char *cur) {
    Rate *tmp = find_entry(cur);
    if (tmp == NULL) {
        return 0.0;
    } else {
        return tmp->amt;
    }
}

// modify the exchange rate of a currency
int upd_rate(char *cur, float amt) {
    Rate *tmp = find_entry(cur);
    if (tmp == NULL) {
        return -1; // no such currency
    } else {
        tmp->amt = amt;
        return 0;
    }
}

int main() {
}
