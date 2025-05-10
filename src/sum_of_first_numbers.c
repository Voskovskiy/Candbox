#include <stdio.h>

int sumOfNumbers(int n);

int main() {
  int n = 3;
  printf("Sum of first %d is %d", n, sumOfNumbers(n));
  return 0;
}

int sumOfNumbers(int n) {
  if (n == 0) {
    return 0;
  }

  return n + sumOfNumbers(n - 1);
}
