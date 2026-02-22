#include "stack.h"
#include <stdio.h>

static const char *stack_result_str(StackResult r) {
  switch (r) {
  case STACK_OK:
    return "OK";
  case STACK_ERR_NULL:
    return "NULL arg";
  case STACK_ERR_EMPTY:
    return "EMPTY";
  case STACK_ERR_FULL:
    return "FULL";
  default:
    return "UNKNOWN";
  }
}

int main(void) {
  Stack *s = create(2);

  StackResult rp = push(s, 10);
  printf("Result of push: %s\n", stack_result_str(rp));

  StackResult rp1 = push(s, 20);
  printf("Result of push1: %s\n", stack_result_str(rp1));

  print(s);
  int top_elem;
  StackResult r = top(s, &top_elem);
  printf("Top: %d with result %s\n", top_elem, stack_result_str(r));

  int elem;
  StackResult rr = pop(s, &elem);
  printf("Elem: %d with result: %s\n", elem, stack_result_str(rr));

  print(s);

  destroy(s);

  return 0;
}
