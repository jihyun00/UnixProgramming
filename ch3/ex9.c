#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    symlink("test.txt", "test.sym");

    return 0;
}
