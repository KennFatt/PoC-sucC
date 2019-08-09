#ifndef __int_len_h
#define __int_len_h 1

#include <stdint.h>

/**
 * This function is measuring the length of a Integer.
 * For example: 1249125 has 7 digits.
 *              551 has 3 digits; and so on.
 * 
 * @param uint32_t  value       Value to be calculated
 * @param double    divider     Divider to determine the length, this should start from 10.
 * @param uint32_t* buffer      Final answer.
 * 
 * @return uint32_t
 */
uint32_t int_len(uint32_t value, double divider, uint32_t *buffer);

#endif