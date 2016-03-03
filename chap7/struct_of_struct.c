#define SSIZE 20;

typedef struct {
    char first[SSIZE];
    char middle[SSIZE];
    char last[SSIZE];
    char title[SSIZE];
} Name;

typedef struct {
    char street[4*SSIZE];
    char city[SSIZE];
    char state[SSIZE];
    char zip[SSIZE];
} Addr;

struct addr_entry {
    Name name;
    Addr addr;
} Addr_entry;

