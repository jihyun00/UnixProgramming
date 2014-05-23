#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    stat("test.txt", &buf);
    printf("Before Link Count = %d\n", (int)buf.st_nlink);

    link("test.txt", "test.ln");

    stat("test.txt", &buf);
    printf("After Link Count = %d\n", (int)buf.st_nlink);


    return 0;
}
