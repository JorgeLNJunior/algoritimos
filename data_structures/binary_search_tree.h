#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./queue.h"

#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

typedef struct BSTreeNode {
  struct BSTreeNode *left;
  struct BSTreeNode *right;
  int value;
} BSTreeNode;

typedef struct BinarySearchTree {
  BSTreeNode *root;
} BinarySearchTree;

// creates a new binary search tree.
BinarySearchTree *bst_create();

// deletes a binary search tree
void *bst_delete(BinarySearchTree *tree);

// creates a new binary search tree node.
BSTreeNode *bst_create_node(int value);

// deletes a binary search tree node.
BSTreeNode *bst_delete_node(BSTreeNode **node);

// inserts a value into a tree.
void bst_insert(BSTreeNode **root, int value);

// prints the values in the tree, from min to max
void bst_print_values(BSTreeNode *root);

// returns true if a given value is in the tree.
bool bst_is_in_tree(BSTreeNode *root, int value);

// returns the height in nodes.
unsigned int bst_get_height(BSTreeNode *root);

// returns the minimum value in the tree.
BSTreeNode *bst_get_min(BSTreeNode *root);

// return the maximum value in the tree.
BSTreeNode *bst_get_max(BSTreeNode *root);

// returns true if is a BinarySearchTree.
bool bst_is_bst(BSTreeNode *root);

// deletes a value from the tree.
BSTreeNode *bst_delete_value(BSTreeNode *root, int value);

// returns the next-highest value in the tree after given value, -1 if none
BSTreeNode *bst_get_successor(BSTreeNode *root, int value);

#endif
