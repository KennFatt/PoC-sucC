#include <stdio.h>

void _d(char val[], char identifier)
{
    for (int i = 0; val[i] >= 0; ++i) {
        // [{identifier}#{pointer}] index({i}), value({char}), decimal({int})
        printf(
            "[%c#%p] index(%d), value(%c), decimal(%d)\n",
               identifier,
               (void *) &val[i],
               i,
               val[i],
               val[i]
        );
    }
    printf(
        "--- END RESULT Case: \'%c\' Lenght: \'%d\' ---\n",
        identifier,
        strlen(val)
    );
}

int main(int argc, char **argv)
{
    char *a = "letter";
    char b[] = "letter";
    char c[7] = {'l', 'e', 't', 't', 'e', 'r'}; // include null terminator.
    _d(a, 'a');
    _d(b, 'b');
    _d(c, 'c');
    _d("letter", 'd'); // literal can't be modified by the function. It's also hardcoded.
    return 0;
}

/**
 * editor: kate
 * os: Linux 5.0.0-20 64-bit
 * cc: gcc 8.3.0
 * tabulators: 4 space
 */
