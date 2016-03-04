#include <stdlib.h>
#include <stdio.h>

typedef struct list_item {
    void *data;
    struct list_item *next;
} List_item;

typedef List_item *LList;
typedef int (*CMP_FN)(void *, void *);
typedef void (*DSP_FN)(void*);

LList LL_find(const LList a, void *item, CMP_FN cmp_fn) {
    for (LList b = a; b != NULL; b = b->next) {
        if (cmp_fn(b->data, item) == 0) {
            return b;
        }
    }
    return NULL;
}

LList LL_delete(LList a, void* item, CMP_FN cmp_fn) {
    if (a == NULL) {
        return NULL;
    }
    if (cmp_fn(a->data, item) == 0) {
        LList b = a->next;
        free(a); 
        return b;
    }
    // otherwise recurse to next link
    a->next = LL_delete(a->next, item, cmp_fn);
    return a;
}

// deletes the link with the given data item
// always returns a pointer to the first link
LList LL_del(LList a, void* item, CMP_FN cmp_fn) {
    LList prev = NULL;
    for (LList b = a; b != NULL; b = b->next) {
        if (cmp_fn(b->data, item) == 0) {
            if (prev == NULL) {
                LList next = b->next;
                free(b);
                return next;
            } else {
                prev->next = b->next;
                free(b);
                return a;
            }
        }
        prev = b;
    }
    return a;
}

LList LL_insert(LList a, void* item) {
    LList x = (LList) malloc(sizeof(List_item));
    x->data = item;
    x->next = a;
    return x;
}

void LL_display(LList a, DSP_FN dsp_fn) {
    printf("(");
    for (LList b = a; b != NULL; b = b->next) {
        dsp_fn(b->data);
        if (b->next != NULL) {
            printf(", ");
        }
    }
    printf(")\n");
}


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
Fraction FR_make(int n, int d) {
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

int FR_cmp(Fraction* a, Fraction* b) {
    return a->num * b->denom - b->num * a->denom;
}

void FR_disp(Fraction *p) {
    printf("%d/%d", p->num, p->denom);
}

int main() {
    LList s = NULL;
    Fraction a = FR_make(1,3);
    Fraction b = FR_make(2,5);
    Fraction c = FR_make(3,7);
    s = LL_insert(s, &a);
    s = LL_insert(s, &b);
    s = LL_insert(s, &c);
    LL_display(s, (DSP_FN) FR_disp);
    s = LL_del(s, &b, (CMP_FN) FR_cmp);
    LL_display(s, (DSP_FN) FR_disp);
}
