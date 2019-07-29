#include "microsecond.h"

double microsecond()
{
    struct timeval tv;
    gettimeofday(&tv, ((void *) 0)); // tz is evaluated as null ptr.
    return ((tv.tv_sec / 1.0) + (tv.tv_usec / 1000000.0));
}