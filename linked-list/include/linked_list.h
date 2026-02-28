#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  size_t size;
} LinkedList;

LinkedList *init(void);

void insert_at(LinkedList *list, int data, size_t index);

void delete_at(LinkedList *list, size_t index);

void print(LinkedList *list);

Node *find(LinkedList *list, int data);

void clear(LinkedList *list);

void reverse(LinkedList *list);

#endif // LINKED_LIST_H
