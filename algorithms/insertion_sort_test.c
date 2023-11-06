#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"
#include "../libs/unity/unity.h"

void test_sort()
{
  size_t const ARR_LEN = 50;
  int arr[ARR_LEN];

  for (int index = 0; index < ARR_LEN; index++)
  {
    arr[index] = rand();
  }

  int const *sorted_arr = insertion_sort(arr, ARR_LEN);

  int previous_value = arr[0];
  for (int index = 1; index < ARR_LEN; index++)
  {
    int const current_value = sorted_arr[index];
    TEST_ASSERT_GREATER_OR_EQUAL_INT(previous_value, current_value);
    previous_value = current_value;
  }
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_sort);
  return UNITY_END();
}
