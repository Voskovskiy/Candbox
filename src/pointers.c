#include <stdio.h>

int main() {
    int num = 10;       // Declare an integer variable
    int *ptr = &num;    // Pointer to an integer, storing the address of num

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Pointer ptr: %p\n", ptr);  // Pointer holds the address of num
    printf("Dereferenced pointer: %d\n", *ptr);  // Dereferencing pointer to get value

    return 0;
}