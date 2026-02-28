#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  LinkedList *list = init();

  insert_at(list, 0, 0);
  insert_at(list, 1, 1);
  insert_at(list, 2, 2);
  insert_at(list, 3, 3);

  print(list);

  Node *node = find(list, 2);
  printf("Found node with value %d", node->data);

  delete_at(list, 2);

  print(list);

  insert_at(list, 9, 2);
  reverse(list);

  print(list);

  return 0;
}
