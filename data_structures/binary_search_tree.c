#include "binary_search_tree.h"
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>

BinarySearchTree *bst_create() {
  BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));
  bst->root = NULL;
  return bst;
}

BSTreeNode *bst_create_node(int value) {
  BSTreeNode *node = malloc(sizeof(BSTreeNode));
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  return node;
}

void bst_insert(BSTreeNode **root, int value) {
  if (*root == NULL) {
    BSTreeNode *node = bst_create_node(value);
    *root = node;
    return;
  }

  if (value < (*root)->value) {
    return bst_insert(&(*root)->left, value);
  }
  if (value >= (*root)->value) {
    return bst_insert(&(*root)->right, value);
  }
}

void bst_print_values(BSTreeNode *root) {
  if (root == NULL) {
    return;
  }

  bst_print_values(root->left);
  printf("%d, ", root->value);
  bst_print_values(root->right);
}

bool bst_is_in_tree(BSTreeNode *root, int value) {
  if (root == NULL) {
    return false;
  }
  if (value == root->value) {
    return true;
  }

  if (value < root->value) {
    return bst_is_in_tree(root->left, value);
  }
  if (value > root->value) {
    return bst_is_in_tree(root->right, value);
  }

  return false;
}

unsigned int bst_get_height(BSTreeNode *root) {
  if (root == NULL) {
    return -1;
  }

  int left = bst_get_height(root->left);
  int right = bst_get_height(root->right);

  return (left > right ? left : right) + 1;
}

BSTreeNode *bst_get_min(BSTreeNode *root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->left == NULL) {
    return root;
  }
  return bst_get_min(root->left);
}

BSTreeNode *bst_get_max(BSTreeNode *root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->right == NULL) {
    return root;
  }
  return bst_get_max(root->right);
}

bool is_subtree_lesser(BSTreeNode *root, int value) {
  if (root == NULL) {
    return true;
  }
  if (root->value <= value && is_subtree_lesser(root->left, value) &&
      is_subtree_lesser(root->right, value)) {
    return true;
  }
  return false;
}

bool is_subtree_greater(BSTreeNode *root, int value) {
  if (root == NULL) {
    return true;
  }
  if (root->value > value && is_subtree_greater(root->left, value) &&
      is_subtree_greater(root->right, value)) {
    return true;
  }
  return false;
}

bool bst_is_bst(BSTreeNode *root) {
  if (root == NULL) {
    return true;
  }

  if (is_subtree_lesser(root->left, root->value) &&
      is_subtree_greater(root->right, root->value) && bst_is_bst(root->left) &&
      bst_is_bst(root->right)) {
    return true;
  }

  return false;
}

BSTreeNode *bst_delete_value(BSTreeNode *root, int value) {
  if (root == NULL) {
    return root;
  }

  if (value < root->value) {
    root->left = bst_delete_value(root->left, value);
  }
  if (value > root->value) {
    root->right = bst_delete_value(root->right, value);
  }

  // No child
  if (root->left == NULL && root->right == NULL) {
    free(root);
    root = NULL;
    return root;
  }
  // Only left child
  if (root->right == NULL) {
    BSTreeNode *temp = root;
    root = root->right;
    free(temp);
    return root;
  }
  // Only right child
  if (root->left == NULL) {
    BSTreeNode *temp = root;
    root = root->left;
    free(temp);
    return root;
  }

  // Both children
  BSTreeNode *temp = bst_get_min(root->right);
  root->value = temp->value;
  root->right = bst_delete_value(root->right, temp->value);

  return root;
}

BSTreeNode *find(BSTreeNode *root, int value) {
  if (root == NULL) {
    return NULL;
  }

  if (value < root->value) {
    return find(root->left, value);
  }
  if (value > root->value) {
    return find(root->right, value);
  }

  return root;
}

BSTreeNode *bst_get_successor(BSTreeNode *root, int value) {
  BSTreeNode *current = find(root, value);
  if (current == NULL) {
    return NULL;
  }

  // Has right subtree
  if (current->right != NULL) {
    return bst_get_min(current->right);
  }

  // Has no right subtree
  BSTreeNode *successor = NULL;
  BSTreeNode *ancestor = root;
  while (ancestor != current) {
    if (current->value < ancestor->value) {
      successor = ancestor;
      ancestor = ancestor->left;
    } else {
      ancestor = ancestor->right;
    }
  }
  return successor;
}
