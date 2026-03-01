#include "hashmap.h"
#include <stdio.h>

int main(void) {
  HashMap hashmap;
  init(&hashmap, 4);

  insert(&hashmap, "key1", 10);
  insert(&hashmap, "key2", 20);
  insert(&hashmap, "key3", 30);
  insert(&hashmap, "key4", 40);
  insert(&hashmap, "key5", 50);

  printf("--- after inserts ---\n");
  print_map(&hashmap);

  int value;
  lookup(&hashmap, "key2", &value);
  printf("\nlookup key2: %d\n", value);

  hm_remove(&hashmap, "key2");

  printf("\n--- after remove(key2) ---\n");
  print_map(&hashmap);

  destroy(&hashmap);
  return 0;
}
