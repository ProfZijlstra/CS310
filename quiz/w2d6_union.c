#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[40];
    char name[40];
    int age;
} Pet;

typedef union {
    Pet pet;
    char character;
} Stupid;

int main() {
    printf("Size of Pet: %lu\n", sizeof(Pet));
    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of stupid: %lu\n", sizeof(Stupid));

    Stupid* p = malloc(sizeof(Stupid));
    strcpy(p[0].pet.type, "Dog");
    strcpy(p[0].pet.name, "Mimi");
    p[0].pet.age = 5;

    printf("%s %s %d\n", p[0].pet.type, p[0].pet.name, 
            p[0].pet.age);
    printf("%c\n", p[0].character);
    p[0].character = 'M';
    printf("%s %s %d\n", p[0].pet.type, p[0].pet.name, 
            p[0].pet.age);
    free(p);
}
