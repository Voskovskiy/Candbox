#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void print_binary(unsigned char x);

int main() {
    unsigned x = 0b10111101;
    unsigned y = 0b00000111;
    int p = 3;
    int n = 3;

    unsigned result = setbits(x, p, n, y);

    print_binary(result);

    printf("Result: 0x%X (%u)\n", result, result); // Очікуємо: 0x9F (10011111)
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // 1. Маска для n правих бітів
    unsigned mask = (1U << n) - 1;

    print_binary(mask);

    // 2. Витягуємо n молодших бітів із y
    unsigned y_bits = y & mask;

    print_binary(y_bits);

    // 3. Зсуваємо ці біти в позицію p
    unsigned y_shifted = y_bits << (p - n + 1);

    print_binary(y_shifted);

    // 4. Очищаємо n бітів у x, починаючи з p
    unsigned x_cleared = x & ~(mask << (p - n + 1));

    print_binary(x_cleared);

    // 5. Об'єднуємо
    return x_cleared | y_shifted;
}

void print_binary(unsigned char x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}