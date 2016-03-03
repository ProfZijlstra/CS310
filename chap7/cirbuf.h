/***************************
 * FIFO Circular Buffer
 ***************************/
typedef struct {
    char* buf;
    unsigned int size;
    unsigned int head;
    unsigned int tail;
    unsigned int length;
} Cirbuf;

// returns a new circular buffer of given size
extern Cirbuf make_cirbuf(unsigned int max);

// tests if buffer is empty
extern int isempty(Cirbuf* bp);

// tests if buffer is full
extern int isfull(Cirbuf* bp);

// puts c into the buffer, returns -1 on failure
extern int produce(char c, Cirbuf* bp);

// removes c from buffer, returns -1 on failure
extern int consume(Cirbuf* bp);

// be sure to call to free buffer_space
extern void delete_cirbuf(Cirbuf b);

