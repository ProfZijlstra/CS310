#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR* dir = opendir(".");
    struct stat stb;
    struct dirent* entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry->d_name);

        // if directory, go into it and print files there
        stat(entry->d_name, &stb);
        if ( (stb.st_mode & S_IFMT) == S_IFDIR) {
        //if (S_ISDIR(entry->d_name)) {
            DIR* deep = opendir(entry->d_name);
            entry = readdir(deep);
            while (entry != NULL) {
                printf("\t%s\n", entry->d_name);
                entry = readdir(deep);
            }
            closedir(deep);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}
