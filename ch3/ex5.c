#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    stat("test.txt", &buf);
    printf("Mode = %o (16진수 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    //소유자의 읽기 권한 확인
    if((buf.st_mode & S_IREAD) != 0)
        printf("test.txt : user has a read permission\n");

    //소유자 읽기 권한 확인할 수 있는 것에서 3비트 오른쪽으로 이동 -> 그룹 읽기 권한 확인
    if((buf.st_mode & (S_IREAD >> 6)) != 0)
        printf("test.txt : group has a read permission\n");

    //기타 사용자 읽기 권한 확인
    if((buf.st_mode & S_IROTH) != 0)
        printf("test.txt : other have a read permission\n");

    return 0;
}
