#include "constants.h"
#include <stdio.h>

#define TAB_WIDTH 4 // фіксована ширина табуляції

int main(void) {
    int c, pos = 0;      // поточна позиція в рядку
    int space_count = 0; // лічильник пробілів

    while ((c = getchar()) != EOF) {
        if (c == WHITESPACE) {
            space_count++;
            pos++;
            // Якщо дійшли до стопа — перевіряємо, чи вставити табуляцію
            if (pos % TAB_WIDTH == 0) {
                putchar(TAB);
                space_count = 0;
            }
        } else {
            // Спочатку виводимо залишкові пробіли
            while (space_count > 0) {
                putchar(WHITESPACE);
                space_count--;
            }

            putchar(c);
            pos++;

            if (c == NEW_LINE) {
                pos = 0;         // скидання позиції
                space_count = 0; // скидання пробілів
            }
        }
    }

    return 0;
}
