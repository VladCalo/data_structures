#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct Entry {
  char *key;
  int value;
  uint64_t hash;
  struct Entry *next;
} Entry;

typedef struct HashMap {
  Entry **buckets;
  size_t capacity; // nr buckets
  size_t size;     // number of entires
} HashMap;

bool init(HashMap *map, size_t capacity);
void destroy(HashMap *map);

bool insert(HashMap *map, const char *key, int value);
bool lookup(HashMap *map, const char *key, int *out_value);
bool hm_remove(HashMap *map, const char *key);

void print_map(const HashMap *map);

#endif
