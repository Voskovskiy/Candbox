#include <stdio.h>
#include "constants.h"

int max; // Max length for inputed string
char current[MAXLINE];
char longest[MAXLINE];

int override_getline(void);
void override_copy(void);

// Print the longest string, specialized version
int main()
{
  int len;
  extern int max;
  extern char longest[];
  max = 0;

  while ((len = override_getline()) > 0)
  {
    if (len > max)
    {
      max = len;
      override_copy();
    }
    if (max > 0) // at least 1 string were entered
    {
      printf("%s", longest);
    }
  }

  return 0;
}

int override_getline(void)
{
  int c, i;
  extern char current[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != NEW_LINE; i++)
  {
    current[i] = c;
  }
  if (c == NEW_LINE)
  {
    current[i] = c;
    ++i;
  }
  current[i] = END_OF_STRING;

  return i;
}

void override_copy(void)
{
  int i = 0;
  extern char current[], longest[];

  while ((longest[i] = current[i]) != END_OF_STRING)
  {
    ++i;
  }
}