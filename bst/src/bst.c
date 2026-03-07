#include "bst.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O(1)
static Node *createNode(int data) {
  Node *node = malloc(sizeof(Node));

  if (!node)
    return NULL;

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// O(1)
void init(BST *bst) {
  bst->root = NULL;
  bst->size = 0;
}

// O(n)
static void free_subtree(Node *node) {
  if (!node)
    return;
  free_subtree(node->left);
  free_subtree(node->right);
  free(node);
}

// O(n)
void destroy(BST *bst) {
  if (!bst)
    return;
  free_subtree(bst->root);
  bst->root = NULL;
  bst->size = 0;
}

// O(log n) average, O(n) worst case
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
      printf("Node already in BST %d\n", key);
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
    parent->left = newNode;
  }
  bst->size++;
  return true;
}

// O(log n) average, O(n) worst case
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

// O(log n) average, O(n) worst case
Node *successor(Node *node) {
  if (!node)
    return NULL;

  if (node->right) {
    Node *succ = node->right;
    while (succ->left) {
      succ = succ->left;
    }
    return succ;
  }

  Node *parent = node->parent;
  while (parent && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

// O(log n) average, O(n) worst case
bool delete(BST *bst, int key) {
  if (!bst)
    return false;

  Node *node = find(bst, key);
  if (!node)
    return false;

  // leaf node
  if (!node->right && !node->left) {
    Node *parent = node->parent;

    if (!parent)
      bst->root = NULL;

    else if (parent->left == node)
      parent->left = NULL;

    else if (parent->right == node)
      parent->right = NULL;

    free(node);
    bst->size--;

    return true;
  }

  // 1 child
  if ((node->left && !node->right) || (!node->left && node->right)) {
    Node *child;

    if (node->left)
      child = node->left;
    else
      child = node->right;

    if (!node->parent) {
      bst->root = child;
      child->parent = NULL;
    } else {
      Node *parent = node->parent;
      if (parent->left == node)
        parent->left = child;
      else
        parent->right = child;

      child->parent = parent;
    }

    free(node);
    bst->size--;
    return true;
  }

  // 2 children
  if (node->left && node->right) {
    Node *succ = successor(node);
    node->data = succ->data;

    Node *parent = succ->parent;
    Node *child = succ->right;

    if (child)
      child->parent = parent;

    if (parent->left == succ)
      parent->left = child;
    else
      parent->right = child;

    free(succ);
    bst->size--;
    return true;
  }

  return false;
}

// O(n)
void print(BST *bst, const char *mode) {
  if (!bst) {
    printf("Not a valid BST!\n");
    return;
  }

  Node *root = bst->root;

  if (strcmp(mode, "inorder") == 0)
    inorder(root);
  else if (strcmp(mode, "postorder") == 0)
    postorder(root);
  else if (strcmp(mode, "preorder") == 0)
    preorder(root);
  else
    printf("Not a valid mode!\n");

  printf("\n");
}

// O(n)
void inorder(Node *root) {
  if (!root)
    return;
  inorder(root->left);
  printf("%d, ", root->data);
  inorder(root->right);
}

// O(n)
void preorder(Node *root) {
  if (!root)
    return;
  printf("%d, ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// O(n)
void postorder(Node *root) {
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d, ", root->data);
}
