#include "constants.h"
#include <stdio.h>

int override_strlen(char s[]) {
    int i = 0;
    while (s[i] != END_OF_STRING)
        ++i;
    return i;
}