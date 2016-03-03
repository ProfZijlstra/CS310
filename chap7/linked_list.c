#include <stdlib.h>
#include <stdio.h>

#define EMPTY_LIST NULL
#define IS_EMPTY(list) ( (list) == EMPTY_LIST)

typedef struct list_item {
    int number;
    struct list_item *next;
} List_item;

typedef List_item *List;

// inserts into the front of the list
List insert_list(List lx, int n) {
    List ly = (List) malloc(sizeof(List_item));
    ly->number = n;
    ly->next = lx;
    return ly;
}

// display items in nice format
// wouldn't work if we had void* data
void display_list(List a) {
    List item;
    printf("(");
    for (item = a; item != EMPTY_LIST; item = item->next) {
        item->next ? printf("%d ", item->number) 
                   : printf("%d", item->number);
    }
    printf(")\n");
}

// delete the requested value
// where ever it may be
List delete_ent(List a, int n) {
    List ans;
    if (IS_EMPTY(a)) {
        return a;
    }
    if (a->number == n) {
        ans = a->next;
        free(a);
        return ans;
    }
    a->next = delete_ent(a->next, n); //recurse
    return a;
}


int main() {
    List list = EMPTY_LIST;
    list = insert_list(list, 3);
    list = insert_list(list, 2);
    list = insert_list(list, 1);
    display_list(list);
    list = delete_ent(list, 2);
    display_list(list);
}
