#ifndef __str2int_h
#define __str2int_h 1

#include <stdint.h>

/**
 * length:3 [capped by 3 bits] => 0b1000 --> 1..8.
 * j:
 * 1 = satuan       n                   ... 0 loop
 * 2 = puluhan      n * 10              ... 1 loop
 * 3 = ratusan      n * 10 * 10         ... 2 loop
 * 4 = ribuan       n * 10 * 10 * 10    ... 3 loop
 *
 * loop: (j - 1)
 *
 * @param char*     numeric_str     Numeric string (max length: 0b1000).
 * @param uint8_t   length          Capped by 3 bits.
 *
 * @return uint32_t
 */
uint32_t str2int(const char *numeric_str, uint8_t length);

#endif