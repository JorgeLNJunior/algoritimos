#include <stdbool.h>
#include <stdlib.h>

#include "../libs/unity/unity.h"
#include "queue.h"

void test_create()
{
  Queue *queue = queue_create();

  TEST_ASSERT_NOT_EQUAL(NULL, queue);

  queue_free(queue);
}

void test_enqueue()
{
  int const pushed_value = rand();

  Queue *queue = queue_create();
  queue_enqueue(queue, pushed_value);

  int const actual_value = queue->data->tail->next->value;

  TEST_ASSERT_EQUAL_INT(pushed_value, actual_value);

  queue_free(queue);
}

void test_dequeue()
{
  int const pushed_value = rand();

  Queue *queue = queue_create();
  queue_enqueue(queue, pushed_value);

  int const actual_value = queue_dequeue(queue);

  TEST_ASSERT_EQUAL_INT(pushed_value, actual_value);

  queue_free(queue);
}

void test_is_empty()
{
  int const TRUE = 1;
  int const FALSE = 0;

  // is empty
  Queue *queue = queue_create();

  bool is_empty = queue_is_empty(queue);

  TEST_ASSERT_EQUAL_INT(TRUE, is_empty);

  queue_enqueue(queue, rand());
  is_empty = queue_is_empty(queue);

  TEST_ASSERT_EQUAL_INT(FALSE, is_empty);
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_create);
  RUN_TEST(test_enqueue);
  RUN_TEST(test_dequeue);
  RUN_TEST(test_is_empty);

  return UNITY_END();
}
