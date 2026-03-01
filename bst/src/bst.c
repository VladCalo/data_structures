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

static void free_subtree(Node *node) {
  if (!node)
    return;
  free_subtree(node->left);
  free_subtree(node->right);
  free(node);
}

void destroy(BST *bst) {
  if (!bst)
    return;
  free_subtree(bst->root);
  bst->root = NULL;
  bst->size = 0;
}

bool insert(BST *bst, int key) {
  if (!bst)
    return false;

  Node *parent = NULL;
  Node *curr = bst->root;

  while (curr) {
    parent = curr;

    if (curr->data < key) {
      curr = curr->right;
    } else if (curr->data > key) {
      curr = curr->left;
    } else {
      printf("Node already in BST\n");
      return false;
    }
  }

  Node *newNode = createNode(key);
  if (!newNode)
    return false;

  newNode->parent = parent;

  if (parent == NULL) {
    bst->root = newNode;
  } else if (parent->data < key) {
    parent->right = newNode;
  } else {
    parent->left = newNode
  }
  bst->size++;
}

Node *find(BST *bst, int key) {
  if (!bst)
    return NULL;

  Node *curr = bst->root;
  if (!curr)
    return NULL;

  while (curr) {
    if (curr->data < key) {
      curr = curr->right;
    } else if (curr->data > key) {
      curr = curr->left;
    } else {
      return curr;
    }
  }
  return NULL;
}
