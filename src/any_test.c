#include "constants.h"
#include <stdio.h>
#include <strings.h>

// Declare the functions to test
int any(const char s1[], const char s2[]);
int any_fast(const char s1[], const char s2[]);

void run_test(const char *s1, const char *s2, int expected);
void show_summary();

// Test counters
int total_tests = 0;
int passed_tests = 0;

int main() {
    run_test("fizzbuzz", "buzz", 2);
    run_test("hello", "xyz", NOT_FOUND);
    run_test("apple", "p", 1);
    run_test("", "a", NOT_FOUND);
    run_test("a", "", NOT_FOUND);
    run_test("abc", "CBA", 0);
    run_test("CBA", "abc", 0);
    run_test("123456", "6", 5);
    run_test("abcdef", "xyz", NOT_FOUND);

    show_summary();

    return 0;
}

void run_test(const char *s1, const char *s2, int expected) {
    total_tests++;

    int result1 = any(s1, s2);
    int result2 = any_fast(s1, s2);

    int pass1 = (result1 == expected);
    int pass2 = (result2 == expected);

    printf("Test %-2d: s1=\"%-10s\" s2=\"%-10s\" → expected: %-2d\n",
           total_tests, s1, s2, expected);
    printf("    any:        %s (got %d)\n", pass1 ? "✅ PASS" : "❌ FAIL",
           result1);
    printf("    any_fast:   %s (got %d)\n", pass2 ? "✅ PASS" : "❌ FAIL",
           result2);
    printf("--------------------------------------------------------------\n");

    if (pass1 && pass2)
        passed_tests++;
}

void show_summary() {
    printf("\n🧪 Tests Passed: %d/%d\n", passed_tests, total_tests);
    if (passed_tests == total_tests)
        printf("✅ ALL TESTS PASSED — SUCCESS 🎉\n");
    else
        printf("❌ SOME TESTS FAILED — CHECK LOG ❗️\n");
}