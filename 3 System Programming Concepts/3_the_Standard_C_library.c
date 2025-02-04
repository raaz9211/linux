#include <stdio.h>
#include <gnu/libc-version.h>

int main()
{

    const char *libc_version = gnu_get_libc_version();
    printf("GNU libc version: %s\n", libc_version);
}