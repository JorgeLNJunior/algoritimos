#include <stdlib.h>
#include <stdio.h>

int *insertion_sort(int *arr, size_t size)
{
  for (int i = 1; i < size; i++)
  {
    int current_value = arr[i];
    int previous_index = i - 1;

    while (arr[previous_index] > current_value)
    {
      arr[previous_index + 1] = arr[previous_index];
      previous_index = previous_index - 1;
    }

    arr[previous_index + 1] = current_value;
  }

  return arr;
}

