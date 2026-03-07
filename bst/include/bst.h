#ifndef BST_H
#define BST_H

#include <stdbool.h>
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

Node *successor(Node *node);

void print(BST *bst, const char *mode);
void inorder(Node *root);
void postorder(Node *root);
void preorder(Node *root);

#endif
