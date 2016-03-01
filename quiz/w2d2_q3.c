/* Write a program called wrdcnt that asks the user
   to enter some text, and then prints how many words 
   there were
   */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int wordcount(int first, char* buf) {

    // if this is the first time 
    if (first == TRUE) {
        // check if there is at least one word
        if (strtok(buf, " \n\r\t\f") != NULL) {
            return 1 + wordcount(FALSE, buf);
        }
    } else if (strtok(NULL, " \n\r\t\f") != NULL) {
        return 1 + wordcount(FALSE, NULL);
    } else { // no more tokens
        return 0;
    }
}


int main() {
    char *buf = (char*) calloc(1024, sizeof(char));
    fgets(buf, 1023, stdin);
    printf("Words: %d\n", wordcount(TRUE, buf));
}
