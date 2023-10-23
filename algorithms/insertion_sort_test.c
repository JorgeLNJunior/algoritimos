#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"

bool run_test()
{
  size_t const ARR_LEN = 10;
  int arr[ARR_LEN];

  for (size_t index = 0; index < ARR_LEN; index++)
  {
    arr[index] = rand();
  }

  int const *sorted_arr = insertion_sort(arr, ARR_LEN);

  int previous_value = 0;
  for (size_t index = 0; index < ARR_LEN; index++)
  {
    int const current_value = sorted_arr[index];
    if(previous_value > current_value) {
      printf("[insertion_sort] the value '%d' is greater than '%d'", previous_value, current_value);
      return false;
    }
    previous_value = current_value;
  }

  return true;
}

int main()
{
  bool const result = run_test();
  if (result == true) {
    printf("[insertion_sort] all tests have been executed with success");
    return 0;
  }
  return 1;
}
