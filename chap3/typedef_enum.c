enum Boolean {FALSE, TRUE};

// writing enum in front of Boolean is a pain
enum Boolean a = TRUE;

// typedef to the rescue!
typedef enum Boolean Bool;
Bool b = False;

// you can also do both in one go with
typedef enum Boolean {FALSE, TRUE} Bool;

