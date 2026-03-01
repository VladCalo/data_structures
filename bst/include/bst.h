#ifndef BST_H
#define BST_H

#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

typedef struct BST {
  Node *root;
  size_t size;
} BST;

void init(BST *bst);
void destroy(BST *bst);

Node *find(BST *bst, int key);

bool insert(BST *bst, int key);
bool delete(BST *bst, int key);

#endif
