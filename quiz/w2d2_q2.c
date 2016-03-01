/* Write a program called wrdcnt that asks the user
   to enter some text, and then prints how many words 
   there were
   */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *buf = (char*) calloc(1024, sizeof(char));
    fgets(buf, 1023, stdin);

    char *tok = strtok(buf, " \n\t\f\r");
    int words = 0;
    if (tok != NULL) {
        words = 1;
        while ((tok = strtok(NULL, " \n\t\f\r")) != NULL){
            words++;
        }
    }
    printf("Words: %d\n", words);
}
