#include <stdio.h>

typedef enum {
    SAVINGS,
    CHECKING
} Act_type; 


typedef struct {
    Act_type type;
    int number;
    double balance;
    char name[100];
    float apy;
} Savings;

typedef struct {
    Act_type type;
    int number;
    double balance;
    char name[100];
    int overdraft;
} Checking;

typedef union {
    Savings savings;
    Checking checking;
} Account;

int main() {
    Account a;
    a.savings.type = SAVINGS;

    if (a.checking.type == CHECKING) {
        printf("Checking\n");
    } else {
        printf("Savings\n");
    }

    a.savings.type = CHECKING;

    if (a.checking.type == CHECKING) {
        printf("Checking\n");
    } else {
        printf("Savings\n");
    }
}
