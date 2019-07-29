#ifndef __microsecond_h
#define __microsecond_h 1

#include <sys/time.h>

/**
 * This function would return a UNIX Epoch Time with its nearest microsecond percision.
 *
 * @return double
 */
double microsecond();

#endif