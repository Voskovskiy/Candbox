#include "constants.h"
#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main() {
    char s1[] = "fizzbuzz";
    const char s2[] = "zz";
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], const char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != END_OF_STRING; i++) {
        for (k = 0; s2[k] != END_OF_STRING; k++) {
            if (s1[i] == s2[k])
                goto skip;
        }
        s1[j++] = s1[i];
    skip:;
    }
    s1[j] = END_OF_STRING;
}