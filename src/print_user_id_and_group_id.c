#include "apue.h"

int
main(void)
{
    prinf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}