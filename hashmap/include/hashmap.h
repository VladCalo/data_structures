#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstddef>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Entry Entry {
  char *key;
  int value;
  uint64_t hash;
  Entry *next;
}

typedef struct HashMap {
  Entry **buckets;
  size_t capacity; // nr buckets
  size_t size;     // number of entires
} HashMap;

bool init(HashMap *map, size_t capacity);
void destroy(Hashmap *map);

bool insert(HashMap *map, const char *key, int value);
bool lookup(HashMap *map, const char *key, int *out_value);
bool remove(HashMap *map, const char *key);

#endif HASHMAP_H
