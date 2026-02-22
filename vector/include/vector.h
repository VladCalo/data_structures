#ifndef VECTOR_H
#define VECTOR_H

#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct Vector Vector;

Vector *create(size_t inital_cap);
void destroy(Vector *v);

void push_back(Vector *v, int elem);
int back(Vector *v);
int pop_back(Vector *v);
bool find_elem(Vector *v, int elem);
void insert_at_index(Vector *v, size_t index, int elem);
void remove_at_index(Vector *v, size_t index);

#endif
