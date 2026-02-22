#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
  int *data;
  size_t size;
  size_t capacity;
};

Vector *create(size_t inital_cap) {
  Vector *v = (Vector *)malloc(sizeof(Vector));

  if (!v)
    return NULL;

  v->size = 0;
  v->data = NULL;
  v->capacity = inital_cap;

  if (inital_cap > 0) {
    v->data = (int *)malloc(intial_cap * sizeof(int));
    if (!v->data) {
      free(v);
      return NULL;
    }
  }

  return v;
}

void destroy(Vector *v) {
  if (v) {
    if (v->data) {
      free(v->data);
    }
    free(v);
  }
}

void push_back(Vector *v, int elem) {}
