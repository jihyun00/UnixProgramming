#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    printf("1. stat : test.txt ---\n");
    stat("test.txt", &buf);
    printf("test.txt : Link Count = %d\n", (int)buf.st_nlink);
    printf("test.txt : Inode = %d\n", (int)buf.st_ino);

    printf("2. stat : test.sym ---\n");
    stat("test.sym", &buf);
    printf("test.sym : Link Count = %d\n", (int)buf.st_nlink);
    printf("test.sym : Inode = %d\n", (int)buf.st_ino);

    printf("3. lstat : test.sym ---\n");
    lstat("test.sym", &buf);
    printf("test.sym : Link Count = %d\n", (int)buf.st_nlink);
    printf("test.sym : Inode = %d\n", (int)buf.st_ino);

    //심볼릭 링크를 stat 함수를 이용하여 검색하면 원본 파일에 대한 정보 검색

    return 0;
}
