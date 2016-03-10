#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int mtime(char *file) {
    struct stat stb;
    if ( stat(file, &stb) < 0) {
        return -1;
    }
    return stb.st_mtime;
}

int newer(char* file1, char* file2) {
    int t1 = mtime(file1);
    int t2 = mtime(file2);
    return t1 - t2; 
}

int main() {
    int diff = newer("read_dir.c", "lowercase.c");
    if (diff > 0) {
        printf("read_dir.c is newer\n") ;
    } else if (diff < 0){
        printf("lowercase.c is newer\n"); 
    } else {
        printf("read_dir.c and lowercase.c have same mtime\n"); 
    }
}

