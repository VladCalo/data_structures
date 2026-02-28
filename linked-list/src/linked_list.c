#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// O(1)
static Node *createNode(int data) {
  Node *node = malloc(sizeof(Node));

  if (!node)
    return NULL;

  node->data = data;
  node->next = NULL;

  return node;
}

// O(1)
LinkedList *init(void) {
  LinkedList *list = malloc(sizeof(LinkedList));

  if (!list)
    return NULL;

  list->head = NULL;
  list->size = 0;

  return list;
}

// O(n)
void insert_at(LinkedList *list, int data, size_t index) {
  if (index > list->size) {
    printf("Specified index outside list boundaries\n");
    return;
  }

  Node *node = createNode(data);
  if (!node)
    return;

  if (index == 0) {
    node->next = list->head;
    list->head = node;
    list->size++;
    return;
  }

  Node *curr = list->head;
  for (size_t i = 0; i < index - 1; i++) {
    curr = curr->next;
  }

  node->next = curr->next;
  curr->next = node;

  list->size++;
}

// O(n)
void delete_at(LinkedList *list, size_t index) {
  if (!list || !list->head || index >= list->size) {
    printf("Specified index outside list boundaries\n");
    return;
  }

  Node *to_free;

  if (index == 0) {
    to_free = list->head;
    list->head = list->head->next;
  } else {
    Node *curr = list->head;
    for (size_t i = 0; i < index - 1; i++) {
      curr = curr->next;
    }
    to_free = curr->next;
    curr->next = to_free->next;
  }

  free(to_free);
  list->size--;
}

// O(n)
void print(LinkedList *list) {
  if (!list || !list->head)
    return;

  Node *curr = list->head;
  for (size_t i = 0; i < list->size; i++) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

// O(n)
Node *find(LinkedList *list, int data) {
  if (!list || !list->head)
    return NULL;

  Node *curr = list->head;
  while (curr) {
    if (curr->data == data)
      return curr;
    curr = curr->next;
  }

  return NULL;
}

// O(n)
void clear(LinkedList *list) {
  Node *curr = list->head;
  while (curr) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }
  list->head = NULL;
  list->size = 0;
}

// O(n)
void reverse(LinkedList *list) {
  Node *curr = list->head;
  Node *prev = NULL;

  while (curr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  list->head = prev;
}
