#define FILE struct _iobuf;

struct _iobuf {
    int   _cnt;     // number of chars in buffer
    char* _ptr;     // current position pointer
    char* _base;    // start of buffer pointer
    int   _bufsiz;  // capacity of buffer
    short _flag;    // error and eof bits
    char  _file;    // file descriptor number
}
