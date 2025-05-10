#include <stdio.h>
#include "constants.h"

int main(void)
{
  int c, pos = 0; // c — поточний символ, pos — позиція в рядку

  while ((c = getchar()) != EOF)
  {
    if (c == TAB)
    {
      // Розрахунок кількості пробілів до наступного стопа
      int spaces = TAB_WIDTH - (pos % TAB_WIDTH);
      for (int i = 0; i < spaces; i++)
      {
        putchar(WHITESPACE);
        pos++;
      }
    }
    else
    {
      putchar(c);
      pos++;

      if (c == NEW_LINE)
      {
        pos = 0; // Скидання позиції на новому рядку
      }
    }
  }

  return 0;
}