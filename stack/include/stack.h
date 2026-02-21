#ifndef STACK_H
#define STACK_H

#include <stdatomic.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Stack Stack;

typedef enum {
  STACK_OK = 0,
  STACK_ERR_NULL,
  STACK_ERR_EMPTY,
  STACK_ERR_FULL,
} StackResult;

Stack *create(size_t inital_cap);
void destroy(Stack *s);

StackResult push(Stack *s, int val);
StackResult pop(Stack *s, int *out);
StackResult top(const Stack *s, int *out);

size_t stack_size(Stack *s);
bool stack_empty(const Stack *s);

#endif
