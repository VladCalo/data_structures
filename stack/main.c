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
  return 0;
}
