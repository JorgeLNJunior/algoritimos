#include "../libs/unity/unity.h"
#include "binary_search_tree.h"
#include <stdio.h>

void test_create() {
  BinarySearchTree *bst = bst_create();

  TEST_ASSERT_NOT_NULL(bst);
}

void test_create_node() {
  int const value = 10;
  BSTreeNode *node = bst_create_node(value);

  TEST_ASSERT_NOT_NULL(node);
  TEST_ASSERT_EQUAL_INT(value, node->value);
}

void test_insert() {
  // insert root
  int value = 10;
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, value);
  TEST_ASSERT_EQUAL_INT(value, bst->root->value);

  // insert left
  value = 5;
  bst_insert(&bst->root, value);
  TEST_ASSERT_EQUAL_INT(value, bst->root->left->value);

  // insert right
  value = 18;
  bst_insert(&bst->root, value);
  TEST_ASSERT_EQUAL_INT(value, bst->root->right->value);
}

void test_is_in_tree() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 3);
  bst_insert(&bst->root, 6);
  bst_insert(&bst->root, 9);
  bst_insert(&bst->root, 15);
  bst_insert(&bst->root, 0);

  bool is_in_tree = bst_is_in_tree(bst->root, 15);
  TEST_ASSERT_EQUAL_INT(1, is_in_tree);

  is_in_tree = bst_is_in_tree(bst->root, 55);
  TEST_ASSERT_EQUAL_INT(0, is_in_tree);
}

void test_get_height() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 10);
  bst_insert(&bst->root, 20);
  bst_insert(&bst->root, 30);
  bst_insert(&bst->root, 40);
  bst_insert(&bst->root, 0);
  bst_insert(&bst->root, 5);

  const int height = bst_get_height(bst->root);

  TEST_ASSERT_EQUAL_INT(3, height);
}

void test_get_min() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 10);
  bst_insert(&bst->root, 2);
  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 1);

  BSTreeNode *min = bst_get_min(bst->root);

  TEST_ASSERT_EQUAL_INT(1, min->value);
}

void test_get_max() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 3);
  bst_insert(&bst->root, 2);
  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 8);

  BSTreeNode *max = bst_get_max(bst->root);

  TEST_ASSERT_EQUAL_INT(8, max->value);
}

void test_is_bst() {
  // true
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 3);
  bst_insert(&bst->root, 2);
  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 4);

  bool is_bst = bst_is_bst(bst->root);

  TEST_ASSERT_EQUAL_INT(1, is_bst);

  // false
  bst = bst_create();
  bst->root = bst_create_node(10);
  bst->root->right = bst_create_node(5);
  bst->root->left = bst_create_node(6);

  is_bst = bst_is_bst(bst->root);

  TEST_ASSERT_EQUAL_INT(0, is_bst);
}

void test_delete() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 3);
  bst_insert(&bst->root, 2);
  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 6);
  bst_insert(&bst->root, 4);

  BSTreeNode *root = bst_delete_value(bst->root, 5);

  TEST_ASSERT_EQUAL_INT(4, bst->root->right->value);
}

void test_get_successor() {
  BinarySearchTree *bst = bst_create();

  bst_insert(&bst->root, 3);
  bst_insert(&bst->root, 2);
  bst_insert(&bst->root, 5);
  bst_insert(&bst->root, 6);
  bst_insert(&bst->root, 4);

  BSTreeNode *successor = bst_get_successor(bst->root, 5);

  TEST_ASSERT_EQUAL_INT(6, successor->value);
}

void setUp() {}
void tearDown() {}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_create);
  RUN_TEST(test_create_node);
  RUN_TEST(test_insert);
  RUN_TEST(test_is_in_tree);
  RUN_TEST(test_get_height);
  RUN_TEST(test_get_min);
  RUN_TEST(test_get_max);
  RUN_TEST(test_is_bst);
  RUN_TEST(test_get_successor);

  return UNITY_END();
}
