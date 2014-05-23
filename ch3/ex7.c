#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    //소유자 모든 권한 추가, 그룹 읽기,실행권한 추가, 기타 읽기 권한 추가
    chmod("test.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);
    stat("test.txt", &buf);
    printf("1.Mode = %o\n", (unsigned int)buf.st_mode);

    //그룹에 쓰기 권한 추가
    buf.st_mode |= S_IWGRP;
    //기타에 읽기 권한 해제
    buf.st_mode &= ~(S_IROTH);
    chmod("test.txt", buf.st_mode);
    stat("test.txt", &buf);
    printf("2.Mode = %o\n", (unsigned int)buf.st_mode);


    return 0;
}
