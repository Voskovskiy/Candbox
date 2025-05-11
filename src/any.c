#include "constants.h"
#include <ctype.h>
#include <stdio.h>

int any(const char s1[], const char s2[]);
int any_fast(const char s1[], const char s2[]);
int any_string_is_nil_or_empty(const char s1[], const char s2[]);

char to_lower(char c);

int any(const char s1[], const char s2[]) {
    if (any_string_is_nil_or_empty(s1, s2))
        return NOT_FOUND;

    for (int i = 0; s1[i] != END_OF_STRING; i++) {
        for (int j = 0; s2[j] != END_OF_STRING; j++) {
            if (to_lower(s1[i]) == tolower(s2[j]))
                return i;
        }
    }

    return NOT_FOUND;
}

int any_fast(const char s1[], const char s2[]) {
    if (any_string_is_nil_or_empty(s1, s2))
        return NOT_FOUND;

    int lookup[256] = {0};

    for (int i = 0; s2[i] != END_OF_STRING; i++)
        lookup[to_lower(s2[i])] = 1;

    for (int i = 0; s1[i] != END_OF_STRING; i++) {
        if (lookup[to_lower(s1[i])]) {
            return i;
        }
    }

    return NOT_FOUND;
}

int any_string_is_nil_or_empty(const char s1[], const char s2[]) {
    return (!s1 || !s2 || s1[0] == END_OF_STRING || s2[0] == END_OF_STRING);
}

char to_lower(char c) { return (char)tolower((unsigned char)c); }