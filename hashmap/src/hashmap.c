#include "hashmap.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define COLLISIONS 0;

static uint64_t djb2_hash(const char *key) {
  uint64_t hash = 5381;
  int c;

  while ((c = *key++))
    hash = ((hash << 5) + hash) + c; // hash * 33 + c

  return hash;
}

// so collision is caused 3+ elems
static uint64_t simple_hash(const char *key) {
  uint64_t sum = 0;
  uint64_t hash = 0;
  while (*key) {
    sum += (unsigned char)*key;
    key++;
  }

  hash = sum % 3;
  return hash;
}

static uint64_t hash_function(const char *key) {
  uint64_t hash = 0;
  if (COLLISIONS) {
    hash = simple_hash(key);
  } else {
    hash = djb2_hash(key);
  }

  return hash;
}

bool init(HashMap *map, size_t capacity) {
  if (!map || capacity == 0)
    return false;

  map->buckets = calloc(capacity, sizeof(Entry *));
  if (!map->buckets)
    return false;

  map->capacity = capacity;
  map->size = 0;
}

void destroy(HashMap *map) {
  if (!map || !map->buckets)
    return false;

  for (size_t i = 0; i < map->capacity; i++) {
    Entry *curr = map->buckets[i];
    while (curr) {
      Entry *next = curr->next;
      free(curr->key);
      free(curr);
      curr = next;
    }
  }
  free(map->buckets);
  map->buckets = NULL;
  map->capacity = 0;
  map->size = 0;
}

bool insert(HashMap *map, const char *key, int value) {
  uint64_t hash = djb2_hash(key);
}
