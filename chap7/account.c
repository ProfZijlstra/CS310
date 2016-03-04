typedef enum {
    SAVINGS,
    CHECKING
} Act_type; 

typedef union {
    float apy;
    int over;
} Apy_or_over;

typedef struct {
    Act_type type;
    int number;
    char* name;
    float balance;
    Apy_or_over ao; 
} account;

