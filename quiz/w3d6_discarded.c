#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    char* fname;
    char* lname;
    char phone[20];
    char email[50];
}

int main() {
    struct contact contacts[1000];
    int i =0;

    FILE* cts = fopen("contacts.txt", "r");
    char fname[41];
    char lname[41];
    char phone[21];
    char email[51];
    while (fscanf(cts, "%40s, %40s, %20s, %50s\n", 
                fname, lname, phone, email) != EOF) {
        contacts[i].fname = malloc(41 * sizeof(char));
        strcpy(contacts[i].fname, fname);
        contacts[i].lname = malloc(41 * sizeof(char));
        strcpy(contacts[i].lname, lname);
        strcpy(contacts[i].phone, phone);
        strcpy(contacts[i].email, email);
        i++;
    }

    // print to check that it worked
    for (int j = 0; j < i; j++) {
        printf("%s, %s, %s, %s\n", contacts[j].fname, 
                contacts[j].lname, contacts[j].phone, contacts[j].email);
    }
}
