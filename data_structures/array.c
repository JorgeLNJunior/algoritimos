#include <stdlib.h>

#include "array.h"

struct Array array_create(unsigned int capacity)
{
  int *pointer = malloc(sizeof(int) * capacity);

  struct Array arr;
  arr.size = 0;
  arr.capacity = capacity;
  arr.data = pointer;

  return arr;
}

void array_resize(struct Array *arr)
{
  int const new_capacity = arr->capacity * 2;
  int *new_data = realloc(arr->data, sizeof(int) * new_capacity);

  arr->capacity = new_capacity;
  arr->data = new_data;
}

void array_free(struct Array *arr)
{
  free(arr->data);
  arr->size = 0;
  arr->capacity = 0;
}

int array_at(unsigned int position, struct Array *arr)
{
  return *(arr->data + position);
}

void array_push(int item, struct Array *arr)
{
  if (arr->size == arr->capacity) array_resize(arr);
  *(arr->data + arr->size) = item;
  arr->size = ++arr->size;
}

void array_insert(unsigned int index, int item, struct Array *arr)
{
  if (arr->size == arr->capacity) array_resize(arr);

  for (int i = (arr->size - 1); i >= index; i--) {
    *(arr->data + (i + 1)) = *(arr->data + i);
  }

  *(arr->data + index) = item;
  arr->size = ++arr->size;
}

int array_pop(struct Array *arr) {
  int const last_index = arr->size - 1;
  int const last_value = *(arr->data + last_index);

  int *new_data = realloc(arr->data, sizeof(int) * (arr->capacity - 1));
  arr->data = new_data;
  arr->size = --arr->size;
  arr->capacity = --arr->capacity;

  return last_value;
}

int array_find(int item, struct Array *arr) {
  for (int i = 0; i < arr->size; i++) {
    if (*(arr->data + i) == item) return i;
  }
  return -1;
}
