#include <ctype.h>
#include <stdio.h>

int htol(const char *s);

int main() {
    printf("%d\n", htol("0xFF"));          // 255
    printf("%d\n", htol("   -0X1A3f"));    // -6719
    printf("%d\n", htol("+7B"));           // 123
    printf("%d\n", htol("z123"));          // -1 (invalid input)
    printf("%d\n", htol("invalid input")); // -1 (invalid input)
    return 0;
}

int htol(const char *s) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (isspace(s[i])) {
        i++;
    }

    // Optional sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Optional 0x or 0X prefix
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
        i += 2;
    }

    // Convert hex digits
    for (; s[i] != '\0'; i++) {
        char c = s[i];
        int value;

        if (isdigit(c)) {
            value = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            // Invalid character
            return -1;
        }

        result = result * 16 + value;
    }

    return result * sign;
}
