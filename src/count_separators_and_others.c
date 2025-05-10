#include <stdio.h>

#define MIN_DIGIT '0'
#define MAX_DIGIT '9'

#define bool int

bool shouldBeCountedAsWhitespace(char c);

// Counting separators & other symbols
int main() {
    int c, nwhite, nother;
    int ndigit[10] = {0};
    nwhite = nother = 0;
    while ((c = getchar()) != EOF) {
        if (c >= MIN_DIGIT && c <= MAX_DIGIT) {
            ++ndigit[c - MIN_DIGIT];
        } else if (shouldBeCountedAsWhitespace(c)) {
            ++nwhite;
        } else {
            ++nother;
        }
    }
    printf("Digits: ");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", whitespaces: %d, other: %d\n", nwhite, nother);
    return 0;
}

bool shouldBeCountedAsWhitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}