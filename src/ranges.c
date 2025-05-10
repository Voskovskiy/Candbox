#include "constants.h"
#include "utilities.h"
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define TABLE_WIDTH 69         // 3 columns × 21 + 2 separators
#define MAX_SEPARATOR_WIDTH 71 // Max width for padding adjustment
#define COL "%-21s | %-21s | %-21s\n"

void section_header(const char *title, const char *source);
char *separator();

int main() {
    section_header("Integer Ranges", "limits.h");

    printf("%-21s | %-21d | %-21d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%-21s | %-21d | %-21d\n", "signed char", SCHAR_MIN, SCHAR_MAX);
    printf("%-21s | %-21u | %-21u\n", "unsigned char", 0, UCHAR_MAX);

    printf("%-21s | %-21d | %-21d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%-21s | %-21u | %-21u\n", "unsigned short", 0, USHRT_MAX);

    printf("%-21s | %-21d | %-21d\n", "int", INT_MIN, INT_MAX);
    printf("%-21s | %-21u | %-21u\n", "unsigned int", 0u, UINT_MAX);

    printf("%-21s | %-21ld | %-21ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%-21s | %-21lu | %-21lu\n", "unsigned long", 0ul, ULONG_MAX);

    section_header("Floating - Point Ranges", "float.h");

    printf("%-21s | %-21.3e | %-21.3e\n", "float", FLT_MIN, FLT_MAX);
    printf("%-21s | %-21.3e | %-21.3e\n", "double", DBL_MIN, DBL_MAX);
    printf("%-21s | %-21.3Le | %-21.3Le\n", "long double", LDBL_MIN, LDBL_MAX);

    return 0;
}

void section_header(const char *title, const char *source) {
    char full_title[128];

    if (source)
        snprintf(full_title, sizeof(full_title), "%s (via %s)", title, source);
    else
        snprintf(full_title, sizeof(full_title), "%s", title);

    int title_len = override_strlen(full_title);
    int total_len = title_len + 8; // "### " + " ###" = 8 characters
    int padding = (TABLE_WIDTH - total_len) / 2;

    if (padding < 0)
        padding = 0;

    printf("\n%.*s### %s ###%.*s\n", padding, separator(), full_title, padding,
           separator());
    printf(COL, "Type", "Min", "Max");
    printf("----------------------|-----------------------|--------------------"
           "--\n");
}

char *separator() {
    static char buffer[MAX_SEPARATOR_WIDTH];
    memset(buffer, '#', MAX_SEPARATOR_WIDTH);

    buffer[sizeof(buffer) - 1] = END_OF_STRING; // Buffer musrt end with '\0'

    return buffer;
}