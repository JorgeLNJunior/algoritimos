#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct List {
  Node *head;
} List;

// creates a linked list.
List *list_create();

// destroys a linked list.
void list_free(List *list);

// created a linked list node;
Node *list_create_node(int value);

// returns the number of elements in the list.
unsigned int list_size(List *list);

// returns true if the list is empty.
bool list_is_empty(List *list);

// returns the value of the nth item.
int list_value_at(List *list, int position);

// adds an item to the front of the list.
void list_push_front(List *list, int value);

// remove the front item and return its value.
int list_pop_front(List *list);

// adds an item at the end.
void list_push_back(List *list, int value);

// get the value of the front item.
int list_front(List *list);

// get the value of the end item.
int list_back(List *list);

//  insert value at index.
void list_insert(List *list, unsigned int index, int value);

// removes node at given index.
void list_erase(List *list, unsigned int index);

// reverses the list.
void list_reverse(List *list);

// removes the first item in the list with this value.
void list_remove_value(List *list, int value);

#endif
