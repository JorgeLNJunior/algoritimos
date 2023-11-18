#include <stdbool.h>
#include <stdlib.h>

#include "../libs/unity/unity.h"
#include "linked_list.h"

void test_create_node()
{
  int value = rand();
  Node *node = list_create_node(value);

  TEST_ASSERT_EQUAL_UINT(value, node->value);
  TEST_ASSERT_EQUAL_MEMORY(NULL, node->next, sizeof(NULL));

  free(node);
}

void test_size()
{
  #define LIST_SIZE 1

  List *list = list_create();
  Node *node = list_create_node(rand());
  list->head->next = node;

  unsigned int const size = list_size(list);

  TEST_ASSERT_EQUAL_UINT(LIST_SIZE, size);

  list_free(list);
}

void test_is_empty()
{
  #define TRUE 1
  #define FALSE 0

  // is empty

  List *list = list_create();

  bool is_empty = list_is_empty(list);
  TEST_ASSERT_EQUAL_UINT(TRUE, is_empty);

  // is not empty

  Node *node = list_create_node(rand());
  list->head->next = node;

  is_empty = list_is_empty(list);
  TEST_ASSERT_EQUAL_UINT(FALSE, is_empty);

  list_free(list);
}

void test_value_at()
{
  int const value = rand();
  int const position = 1;

  List *list = list_create();
  Node *node = list_create_node(value);

  list->head->next = node;

  int result = list_value_at(list, position);

  TEST_ASSERT_EQUAL_INT(value, result);

  list_free(list);
}

void test_push_front()
{
  int const nodeValue = rand();

  List *list = list_create();
  Node *node = list_create_node(rand());
  list->head->next = node;

  list_push_front(list, nodeValue);

  int const result = list_value_at(list, 1);

  TEST_ASSERT_EQUAL_INT(nodeValue, result);

  list_free(list);
}

void test_pop_front()
{
  int const nodeValue = rand();

  List *list = list_create();
  Node *node = list_create_node(nodeValue);
  list->head->next = node;

  int const result = list_pop_front(list);

  TEST_ASSERT_EQUAL_INT(result, nodeValue);
  TEST_ASSERT_EQUAL_MEMORY(NULL, list->head->next, sizeof(NULL));

  list_free(list);
}

void test_push_back()
{
  int const nodeValue = rand();

  List *list = list_create();

  list_push_back(list, nodeValue);

  int const result = list_value_at(list, 1);

  TEST_ASSERT_EQUAL_UINT(nodeValue, result);

  list_free(list);
}

void test_front()
{
  int const nodeValue = rand();

  List *list = list_create();
  Node *node = list_create_node(nodeValue);
  list->head->next = node;

  int const result = list_front(list);

  TEST_ASSERT_EQUAL_INT(nodeValue, result);

  list_free(list);
}

void test_back()
{
  int const nodeValue = rand();

  List *list = list_create();
  Node *node = list_create_node(nodeValue);
  list->head->next = node;

  int const result = list_back(list);

  TEST_ASSERT_EQUAL_INT(nodeValue, result);

  list_free(list);
}

void test_insert()
{
  int const firstNodeValue = rand();
  int const insertNodeValue = rand();
  int unsigned const index = 1;

  List *list = list_create();
  Node *firstNode = list_create_node(firstNodeValue);
  list->head->next = firstNode;

  list_insert(list, index, insertNodeValue);

  int const insertNodeResult = list_value_at(list, index);
  int const firstNodeResult = list_value_at(list, index + 1);

  TEST_ASSERT_EQUAL_INT(insertNodeValue, insertNodeResult);
  TEST_ASSERT_EQUAL_INT(firstNodeValue, firstNodeResult);

  list_free(list);
}

void test_erase()
{
  List *list = list_create();
  Node *node = list_create_node(rand());
  list->head->next = node;

  list_erase(list, 1);

  TEST_ASSERT_EQUAL_MEMORY(NULL, list->head->next, sizeof(NULL));
}

void test_reverse()
{
  int const firtNodeValue = rand();
  int const secondNodeValue = rand();

  List *list = list_create();
  Node *firtsNode = list_create_node(firtNodeValue);
  Node *secondNode = list_create_node(secondNodeValue );

  firtsNode->next = secondNode;
  list->head->next = firtsNode;

  list_reverse(list);

  TEST_ASSERT_EQUAL_INT(list->head->next->value, secondNodeValue);
}

void test_remove_value()
{
  int const secondNodeValue = rand();

  List *list = list_create();
  Node *firstNode = list_create_node(rand());
  Node *secondNode = list_create_node(secondNodeValue);

  list->head->next = firstNode;
  firstNode->next = secondNode;

  list_remove_value(list, firstNode->value);

  TEST_ASSERT_EQUAL_INT(secondNodeValue, list->head->next->value);
}

void setUp() {}
void tearDown() {}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_size);
  RUN_TEST(test_is_empty);
  RUN_TEST(test_create_node);
  RUN_TEST(test_value_at);
  RUN_TEST(test_push_front);
  RUN_TEST(test_pop_front);
  RUN_TEST(test_push_back);
  RUN_TEST(test_front);
  RUN_TEST(test_back);
  RUN_TEST(test_insert);
  RUN_TEST(test_erase);
  RUN_TEST(test_reverse);
  RUN_TEST(test_remove_value);

  return UNITY_END();
}
