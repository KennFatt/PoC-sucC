#include <stdio.h>
#include "intlen.h"

uint32_t int_len(uint32_t value, double divider, uint32_t *buffer)
{
    if (value < 10) {
        return 1;
    }

    if ((value / divider) < 1.0) {
        return *buffer;
    }

    ++*buffer;
    return int_len(value, divider * 10, buffer);
}