#include "vector.h"
#include <stdio.h>

int main(void) {
  Vector *v = create(4);

  push_back(v, 10);
  push_back(v, 20);
  push_back(v, 30);
  push_back(v, 40);
  push_back(v, 50);

  printf("back: %d\n", back(v));
  printf("pop_back: %d\n", pop_back(v));
  printf("back after pop: %d\n", back(v));

  printf("find 20: %d\n", find_elem(v, 20));
  printf("find 99: %d\n", find_elem(v, 99));

  insert_at_index(v, 1, 99);
  printf("after insert_at_index(1, 99) -> find 99: %d\n", find_elem(v, 99));

  remove_at_index(v, 1);
  printf("after remove_at_index(1)     -> find 99: %d\n", find_elem(v, 99));

  destroy(v);
  return 0;
}
