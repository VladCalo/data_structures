#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int *data;
  size_t size;
  size_t capacity;
};

Stack *
create(size_t inital_cap) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  if (!s)
    return NULL;

  s->size = 0;
  s->capacity = inital_cap;
  s->data = NULL;

  if (inital_cap > 0) {
    s->data = (int *)malloc(inital_cap * sizeof(int));
    if (!s->data) {
      free(s);
      return NULL;
    }
  }

  return s;
}

void destroy(Stack *s) {
  if (!s)
    return;
  free(s->data);
  free(s);
}

StackResult push(Stack *s, int val) {
  if (!s)
    return STACK_ERR_NULL;
  if (s->size == s->capacity)
    return STACK_ERR_FULL;

  s->data[s->size] = val;
  s->size++;

  return STACK_OK;
}

StackResult pop(Stack *s, int *out) {
  if (!s)
    return STACK_ERR_NULL;
  if (s->size == 0)
    return STACK_ERR_EMPTY;

  s->size--;
  *out = s->data[s->size];
  return STACK_OK;
}

StackResult top(const Stack *s, int *out) {
  if (!s || !out)
    return STACK_ERR_NULL;
  if (s->size == 0)
    return STACK_ERR_EMPTY;

  *out = s->data[s->size - 1];
  return STACK_OK;
}

size_t stack_size(Stack *s) { return s ? s->size : 0; }

bool stack_empty(const Stack *s) { return !s || s->size == 0; }
