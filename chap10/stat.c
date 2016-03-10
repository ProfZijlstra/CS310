#include <sys/types>
#include <sys/stat.h>

int stat(const char* filem struct stat* buf);
int fstat(int fs, struct stat* buf);

#include <sys/file.h>
int access(char* name, int a_mode);


