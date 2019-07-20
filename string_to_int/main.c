#include <stdio.h>

/**
 * length:3 [capped by 3 bits] => 0b111 + 1 --> 1..8.
 * j:
 * 1 = satuan       n                   ... 0 loop
 * 2 = puluhan      n * 10              ... 1 loop
 * 3 = ratusan      n * 10 * 10         ... 2 loop
 * 4 = ribuan       n * 10 * 10 * 10    ... 3 loop
 *
 * loop: (j - 1)
 *
 * @param char *numeric Numeric string (max length: 0b111 + 1).
 * @param uint8_t length Capped by 3 bits.
 *
 * @return uint32_t
 */
unsigned int to_int(char *numeric, unsigned char length)
{
    if ((length < 0b1) || (length > (0b111 + 1))) {
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
        /**
         * Benchmark:
         *
         * OS: Linux 5.0.0-20 64-bit
         * CC: gcc 8.3.0
         * Executed in:
         * - VS Code terminal.
         * - Konsole - Native terminal.
         * Header:
         * - stdio.h
         *
         * #0 (i3-4005u @ 1.7GHz ~ Highest):
         * - Ternary operation: 8 digit case = 0.001s. Highest peak 0.002s (extremely rare).
         * - Switch-case: 8 digit case = 0.001s. Constantly.
         *
         * #1 (i3-4005u @ 0.8GHz ~ Lowest):
         * - Ternary operation: 8 digit case = 0.002s. Highest peak 0.003s.
         * - Switch-case: 8 digit case = 0.002s. Highest peak 0.003s.
         */
        tmp = numeric[i] == 48 ? 0 :
            numeric[i] == 49 ? 1 :
            numeric[i] == 50 ? 2 :
            numeric[i] == 51 ? 3 :
            numeric[i] == 52 ? 4 :
            numeric[i] == 53 ? 5 :
            numeric[i] == 54 ? 6 :
            numeric[i] == 55 ? 7 :
            numeric[i] == 56 ? 8 :
            numeric[i] == 57 ? 9 : 0;

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

int main(int argc, char **argv)
{
    char *deb = argv[1];
    int len = to_int(argv[2], 1);
    int res = to_int(deb, len);
    printf("res: %d\n", res);

    return 0;
}
