#include "str2int.h"

/**
 * DO NOT USE THIS FUNCTION.
 * This function designed for this project only.
 */
int _is_int(uint8_t chr)
{
    return chr >= 48 && chr <= 57;
}

/**
 * DO NOT USE THIS FUNCTION.
 * This function designed for this project only.
 */
uint8_t _strlen(const char *str)
{
    uint8_t res = 0;
    int i = 0;
    for (; str[i] != 0 && _is_int(str[i]); ++i) {
        ++res;
    }
    return res;
}

uint32_t str2int(const char *numeric_str)
{
    /**
     * Just to make sure the length is valid.
     */
    uint8_t length = _strlen(numeric_str);

    if ((length < 0b1) || (length > (0b01001))) {
        return 0;
    }

    /**
     * tmp: 0 -> First digit.
     * ...
     * tmp: n -> Last digit.
     */
    uint32_t tmp = 0;

    uint32_t result = 0;

    /**
     * if -> length == 3
     * let:
     *  i = 0: j => length
     *  i = 1: j => length - i
     *  i = 2: j => length - i
     *
     * Formula:
     * [j = length - i]
     */
    uint8_t i = 0;
    for (; i < length; ++i) {
        tmp = numeric_str[i] == 48 ? 0 :
            numeric_str[i] == 49 ? 1 :
            numeric_str[i] == 50 ? 2 :
            numeric_str[i] == 51 ? 3 :
            numeric_str[i] == 52 ? 4 :
            numeric_str[i] == 53 ? 5 :
            numeric_str[i] == 54 ? 6 :
            numeric_str[i] == 55 ? 7 :
            numeric_str[i] == 56 ? 8 :
            numeric_str[i] == 57 ? 9 : -1;
        
        if (tmp == -1) {
            return result;
        }

        uint8_t j = length - i;
        if (j > 0) {
            uint8_t k = j - 1;
            for (; k > 0; --k) {
                tmp *= 10;
            }
        }
        result += tmp;
    }

    return result;
}