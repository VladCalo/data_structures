#include "hashmap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLISIONS 1
#define MODULO 3

// O(k) - k is key length
static uint64_t djb2_hash(const char *key) {
  uint64_t hash = 5381;
  int c;

  while ((c = *key++))
    hash = ((hash << 5) + hash) + c; // hash * 33 + c

  return hash;
}

// O(k) - k is key length
// so collision is caused 3+ elems
static uint64_t simple_hash(const char *key) {
  uint64_t sum = 0;
  uint64_t hash = 0;
  while (*key) {
    sum += (unsigned char)*key;
    key++;
  }

  hash = sum % MODULO;
  return hash;
}

// O(k) - k is key length
static uint64_t hash_function(const char *key) {
  uint64_t hash = 0;
  if (COLISIONS) {
    hash = simple_hash(key);
  } else {
    hash = djb2_hash(key);
  }

  return hash;
}

// O(n) - n is capacity (calloc zeroes the bucket array)
bool init(HashMap *map, size_t capacity) {
  if (!map || capacity == 0)
    return false;

  map->buckets = calloc(capacity, sizeof(Entry *));
  if (!map->buckets)
    return false;

  map->capacity = capacity;
  map->size = 0;

  return true;
}

// O(n) - n is total number of entries
void destroy(HashMap *map) {
  if (!map || !map->buckets)
    return;

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

// O(1) average, O(n) worst case (all keys in one bucket)
bool insert(HashMap *map, const char *key, int value) {
  if (!map || !key || map->capacity == 0)
    return false;

  uint64_t hash = hash_function(key);
  size_t index = hash % map->capacity;

  Entry *curr = map->buckets[index];
  while (curr) {
    if (curr->hash == hash && strcmp(curr->key, key) == 0) {
      curr->value = value;
      return true;
    }
    curr = curr->next;
  }

  Entry *entry = (Entry *)malloc(sizeof(*entry));
  if (!entry)
    return false;

  size_t klen = strlen(key);
  entry->key = (char *)malloc(klen + 1);
  if (!entry->key) {
    free(entry);
    return false;
  }

  memcpy(entry->key, key, klen + 1);

  entry->value = value;
  entry->hash = hash;

  entry->next = map->buckets[index];
  map->buckets[index] = entry;

  map->size++;
  return true;
}

// O(1) average, O(n) worst case (all keys in one bucket)
bool lookup(HashMap *map, const char *key, int *out_value) {
  if (!map || !key || map->capacity == 0)
    return false;

  uint64_t hash = hash_function(key);
  size_t index = hash % map->capacity;

  Entry *curr = map->buckets[index];
  while (curr) {
    if (curr->hash == hash && strcmp(curr->key, key) == 0) {
      *out_value = curr->value;
      return true;
    }
    curr = curr->next;
  }

  return false;
}

// O(1) average, O(n) worst case (all keys in one bucket)
bool hm_remove(HashMap *map, const char *key) {
  if (!map || !key || map->capacity == 0)
    return false;

  uint64_t hash = hash_function(key);
  size_t index = hash % map->capacity;

  Entry *curr = map->buckets[index];
  Entry *prev = NULL;
  while (curr) {
    if (curr->hash == hash && strcmp(curr->key, key) == 0) {
      if (prev)
        prev->next = curr->next;
      else
        map->buckets[index] = curr->next;
      free(curr->key);
      free(curr);
      map->size--;
      return true;
    }
    prev = curr;
    curr = curr->next;
  }

  return false;
}

// O(n)
void print_map(const HashMap *map) {
  if (!map)
    return;

  printf("HashMap [size=%zu, capacity=%zu]\n", map->size, map->capacity);
  for (size_t i = 0; i < map->capacity; i++) {
    printf("  bucket[%zu]: ", i);
    Entry *curr = map->buckets[i];
    if (!curr) {
      printf("NULL");
    }
    while (curr) {
      printf("\"%s\":%d", curr->key, curr->value);
      curr = curr->next;
      printf(curr ? " -> " : " -> NULL");
    }
    printf("\n");
  }
}
