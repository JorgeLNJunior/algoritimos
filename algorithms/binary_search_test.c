#include "./binary_search.h"
#include "../libs/unity/unity.h"

void should_return_the_index()
{
  int arr[] = { 10, 20, 30, 40, 50 };

  int index = binary_search(arr, 20, 0, 4);

  TEST_ASSERT_EQUAL_INT(1, index);

  index = binary_search(arr, 40, 0, 4);

  TEST_ASSERT_EQUAL_INT(3, index);
}

void should_return_minus_one()
{
  int arr[] = { 10, 20, 30, 40, 50 };

  int index = binary_search(arr, 80, 0, 4);

  TEST_ASSERT_EQUAL_INT(-1, index);
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(should_return_the_index);

  UNITY_END();
}
