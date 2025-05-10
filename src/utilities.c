#include "utilities.h"

// ASCII character to lower case
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

// Custom strlen
int override_strlen(char s[]) {
    int i = 0;
    while (s[i] != END_OF_STRING)
        ++i;
    return i;
}