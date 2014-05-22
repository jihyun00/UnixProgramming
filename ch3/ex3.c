#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat buf;
    int kind;

    stat("test.txt", &buf);

    printf("Mode = %o (16진수 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    //S_IFMT 값이 0xf000이므로 파일 권한과 AND 연산하면 파일 종류 비트부분만 남게 됨.
    kind = buf.st_mode & S_IFMT;
    printf("Kind = %x\n", kind);

    switch(kind) {
        case S_IFIFO:
            printf("test.txt : FIFO\n");
            break;
        case S_IFDIR:
            printf("test.txt : Directory\n");
            break;
        case S_IFREG:
            printf("test.txt : Regular File\n");
            break;
    }

    return 0;
}
