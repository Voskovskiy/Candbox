#include <stdio.h>

int largerOne(int a, int b);

int main() {
    printf("The larger one for %d & %d is %d\n", 25, 15, largerOne(25, 15));

    return 0;
}

int largerOne(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}
