#include <stdio.h>

#define IN 1
#define OUT 0

#define bool int
#define YES 1
#define NO 0

bool isNewLine(char c);
bool isSpace(char c);
bool isTab(char c);
bool shouldSetOutState(char c);

// Counting rows, words & simbols
int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (isNewLine(c))
            ++nl;

        if (shouldSetOutState(c)) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}

bool isNewLine(char c) { return c == '\n'; }

bool isSpace(char c) { return c == ' '; }

bool isTab(char c) { return c == '\t'; }

bool shouldSetOutState(char c) {
    return isSpace(c) || isNewLine(c) || isTab(c);
}