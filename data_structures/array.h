#if !defined(ARRAY_H)
#define ARRAY_H

struct Array
{
  int size;
  int capacity;
  int *data;
};

// Create an array with a given capacity.
struct Array array_create(unsigned int capacity);

// Free a given array.
void array_free(struct Array *arr);

// Return the value at a given index.
int array_at(unsigned int position, struct Array *arr);

// Insert an item at the end of the array.
void array_push(int item, struct Array *arr);

// Insert an item at an index.
void array_insert(unsigned int index, int item, struct Array *arr);

// Remove the item at the and of the array and return it.
int array_pop(struct Array *arr);

// Find an item and return its index. Return -1 if not found.
int array_find(int item, struct Array *arr);

#endif
