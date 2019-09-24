#include <stdio.h>
#include <limits.h>
#include "intlen.h"

int unit_test(int op, int expected)
{
    return op == expected;
}

int main(int argc, char **argv)
{
    uint32_t buffer = 1;
    int ut = unit_test(int_len(123456789, 10, &buffer), 9);
    fprintf(stdout, "UT: %s, Buffer: %ld\n", ut == 0 ? "false" : "true", buffer);

    return 0;
}