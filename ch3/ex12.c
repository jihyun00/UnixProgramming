#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char buf[BUFSIZ];

    realpath("test.sym", buf);
    printf("test.sym : REALPATH = %s\n", buf);

    return 0;
}
