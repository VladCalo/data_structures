#include "bst.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static Node *createNode(int data) {
  Node *node = malloc(sizof(Node));

  if (!node)
    return NULL;

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void init(BST *bst) {
  bst->root = NULL;
  bst->size = 0;
}
