#include "../libs/unity/unity.h"
#include "./array.h"

#define ARRAY_CAPACITY 10

void test_array_create()
{
  int const initial_size = 0;

  struct Array arr = array_create(ARRAY_CAPACITY);

  TEST_ASSERT_EQUAL_UINT(ARRAY_CAPACITY, arr.capacity);
  TEST_ASSERT_EQUAL_UINT(initial_size, arr.size);

  array_free(&arr);
}

void test_array_free()
{
  int const initial_size = 0;
  int const final_capacity = 0;
  int const final_size = 0;

  struct Array arr = array_create(ARRAY_CAPACITY);

  array_free(&arr);

  TEST_ASSERT_EQUAL_UINT(final_capacity, arr.capacity);
  TEST_ASSERT_EQUAL_UINT(final_size, arr.size);
}

void test_array_at()
{
  struct Array arr = array_create(ARRAY_CAPACITY);
  int const item = 55;
  int const index = 3;

  *(arr.data + index) = item;

  int const value = array_at(index, &arr);

  TEST_ASSERT_EQUAL_UINT(item, value);

  array_free(&arr);
}

void test_array_push()
{
  struct Array arr = array_create(ARRAY_CAPACITY);
  int const item = 55;

  array_push(item, &arr);

  int const value = *(arr.data);

  TEST_ASSERT_EQUAL_UINT(item, value);

  array_free(&arr);
}

void test_array_pop()
{
  struct Array arr = array_create(ARRAY_CAPACITY);
  int const item = 55;

  array_push(item, &arr);

  int const value = array_pop(&arr);

  TEST_ASSERT_EQUAL_UINT(item, value);

  array_free(&arr);
}

void test_array_find()
{
  struct Array arr = array_create(ARRAY_CAPACITY);
  int item = 55;
  int index = 0;

  array_push(item, &arr);

  int value = array_find(item, &arr);

  TEST_ASSERT_EQUAL_UINT(index, value);

  // item not found

  item = 20;
  index = -1;

  value = array_find(item, &arr);

  TEST_ASSERT_EQUAL_UINT(index, value);

  array_free(&arr);
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_array_create);
  RUN_TEST(test_array_free);
  RUN_TEST(test_array_at);
  RUN_TEST(test_array_push);
  RUN_TEST(test_array_pop);
  RUN_TEST(test_array_find);

  return UNITY_END();
}
