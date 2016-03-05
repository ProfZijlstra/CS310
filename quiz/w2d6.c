#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_odd(int a[], int l) {
    if (l < 0) {
        return 0;
    } else if (a[l-1] % 2 == 1){
        return 1 + count_odd(a, l - 1);
    } else {
        return count_odd(a, l - 1);
    }
}

typedef struct {
    char type[40];
    char name[40];
    int age;
} Pet;

typedef struct {
    char* type;
    char* name;
    int age;
} Pet2;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    printf("%d odd numbers\n", count_odd(a, 5));

    Pet* pets = (Pet*) malloc(2 * sizeof(Pet));
    strcpy(pets[0].type, "Cat"); // pets->type also works
    strcpy(pets[0].name, "Mimi");
    pets[0].age = 5;
    strcpy(pets[1].type, "Dog"); 
    strcpy(pets[1].name, "Fido");
    pets[1].age = 3;

    Pet2* other = (Pet2*) malloc(sizeof(Pet2));
    Pet2 yetother = {"Cat", "Mimi", 5};
    other[0] = {"Cat", "Mimi", 5};
    other[0].type = "Cat";
    other[0].name = "Mimi";
    other[0].age = 5;
    printf("%s %s %d\n", other[0].type, other[0].name, other[0].age);


    // you can also do pets++ and then use pets->type again
    
    printf("%s %s age %d\n", pets[0].type, pets[0].name, pets[0].age);
    printf("%s %s age %d\n", pets[1].type, pets[1].name, pets[1].age);
}

void invoke(void *data, void (*F)(void*)) {
    F(data);
}



