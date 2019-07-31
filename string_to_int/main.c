#include <stdio.h>
#include "str2int.h"

int main(int argc, char **argv)
{
    char *deb = argv[1];
    int len = str2int(argv[2], 1);
    int res = str2int(deb, len);
    printf("res: %d\n", res);

    return 0;
}
