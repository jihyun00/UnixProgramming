#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    struct utsname uts;

    if(uname(&uts) == -1) {
        perror("uname");
        exit(1);
    }

    printf("OSname : %s\n", uts.sysname); //OS 이름 저장
    printf("Nodename : %s\n", uts.nodename); //통신할 때 쓰는 시스템 이름
    printf("Release : %s\n", uts.release); //OS의 릴리즈된 번호 
    printf("Version : %s\n", uts.version); //OS Version
    printf("Machine : %s\n", uts.machine); //OS가 동작하는 하드웨어 표준 이름

    return 0;
}
