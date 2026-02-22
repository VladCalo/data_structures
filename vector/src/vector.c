#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
  int *data;
  size_t size;
  size_t capacity;
};

// O(1)
Vector *create(size_t inital_cap) {
  Vector *v = (Vector *)malloc(sizeof(Vector));

  if (!v)
    return NULL;

  v->size = 0;
  v->data = NULL;
  v->capacity = inital_cap;

  if (inital_cap > 0) {
    v->data = (int *)malloc(inital_cap * sizeof(int));
    if (!v->data) {
      free(v);
      return NULL;
    }
  }

  return v;
}

// O(1)
void destroy(Vector *v) {
  if (v) {
    if (v->data) {
      free(v->data);
    }
    free(v);
  }
}

// O(1) or O(n) if realloc (capacity exceeded)
void push_back(Vector *v, int elem) {
  if (v->size == v->capacity) {
    size_t new_capacity = v->capacity > 0 ? v->capacity * 2 : 1;
    int *p = realloc(v->data, new_capacity * sizeof(int));
    if (!p)
      return;
    v->data = p;
    v->capacity = new_capacity;
  }

  v->data[v->size++] = elem;
}

// O(1)
int back(Vector *v) {
  if (!v)
    return -1;
  return v->data[v->size - 1];
}

// O(1)
int pop_back(Vector *v) {
  if (!v || v->size == 0)
    return -1;
  return v->data[--v->size];
}

// O(n)
bool find_elem(Vector *v, int elem) {
  if (v && v->size > 0) {
    for (size_t i = 0; i < v->size; i++) {
      if (v->data[i] == elem)
        return 1;
    }
  }

  return 0;
}

// O(n)
void insert_at_index(Vector *v, size_t index, int elem) {
  if (!v || index > v->size)
    return;

  push_back(v, 0);

  for (size_t i = v->size - 1; i > index; i--) {
    v->data[i] = v->data[i - 1];
  }

  v->data[index] = elem;
}

// O(n)
void remove_at_index(Vector *v, size_t index) {
  if (!v || v->size <= index)
    return;

  for (size_t i = index; i < v->size - 1; i++) {
    v->data[i] = v->data[i + 1];
  }

  pop_back(v);
}
