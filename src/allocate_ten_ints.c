#include <stdio.h>
#include <stdlib.h>

int main()
{
  int count = 10;
  int *arr = (int *)malloc(count * sizeof(int));

  if (arr == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  for (int i = 0; i < count; i++)
  {
    arr[i] = i;
  }

  for (int i = 0; i < count; i++)
  {
    printf("Value stored in [%d] is %d\n", i, arr[i]);
  }

  free(arr);
  return 0;
}