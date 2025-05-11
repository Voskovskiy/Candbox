#include "utilities.h"
#include "constants.h"

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

void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != END_OF_STRING; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[i] = END_OF_STRING;
}

void strcat(char s[], char t[]) {
    int i, j = 0;
    while (s[i] != END_OF_STRING)
        i++;
    while ((s[i++] = t[j++]) != END_OF_STRING)
        ;
}