#include "str2int.h"

uint32_t str2int(const char *numeric_str, uint8_t length)
{
    if ((length < 0b1) || (length > (0b1000))) {
        return 0;
    }

    /**
     * tmp: 0 -> First digit.
     * ...
     * tmp: n -> Last digit.
     */
    unsigned int tmp = 0;

    unsigned int result = 0;

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
    int i;
    for (i = 0; i < length; ++i) {
        tmp = numeric_str[i] == 48 ? 0 :
            numeric_str[i] == 49 ? 1 :
            numeric_str[i] == 50 ? 2 :
            numeric_str[i] == 51 ? 3 :
            numeric_str[i] == 52 ? 4 :
            numeric_str[i] == 53 ? 5 :
            numeric_str[i] == 54 ? 6 :
            numeric_str[i] == 55 ? 7 :
            numeric_str[i] == 56 ? 8 :
            numeric_str[i] == 57 ? 9 : 0;

        int j = length - i;
        if (j > 0) {
            int k = j - 1;
            for (k; k > 0; --k) {
                tmp *= 10;
            }
        }
        result += tmp;
    }

    return result;
}