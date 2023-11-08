#if !defined(ARRAY_H)
#define ARRAY_H

typedef struct
{
  int size;
  int capacity;
  int *data;
} Array;

// Create an array with a given capacity.
Array array_create(unsigned int capacity);

// Free a given array.
void array_free(Array *arr);

// Return the value at a given index.
int array_at(unsigned int position, Array *arr);

// Insert an item at the end of the array.
void array_push(int item, Array *arr);

// Insert an item at an index.
void array_insert(unsigned int index, int item, Array *arr);

// Remove the item at the and of the array and return it.
int array_pop(Array *arr);

// Find an item and return its index. Return -1 if not found.
int array_find(int item, Array *arr);

#endif
