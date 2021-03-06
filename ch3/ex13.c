#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    DIR *dp;
    struct dirent *dent;

    if((dp = opendir("test")) == NULL) {
        perror("opendir : test");
        exit(1);
    }

    while((dent = readdir(dp))) {
        printf("Name : %s ", dent->d_name);
        printf("Inode : %d\n", (int)dent->d_ino);
    }

    closedir(dp);

    return 0;
}
