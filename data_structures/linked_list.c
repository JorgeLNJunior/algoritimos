#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

List *list_create()
{
  List *list = malloc(sizeof(List));
  list->head = list_create_node(0);
  list->tail = list_create_node(0);
  return list;
}

void list_free(List *list)
{
  Node *current = list->head;

  while(current != NULL)
  {
    Node *next = current->next;
    free(current);
    current = next;
  }

  free(list);
}

Node *list_create_node(int value)
{
  Node *node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = value;
  return node;
}

unsigned int list_size(List *list)
{
  unsigned int size = 0;

  for(Node *node = list->head->next; node != NULL; node = node->next) {
    size++;
  }

  return size;
}

bool list_is_empty(List *list)
{
  if(list->head->next == NULL) return true;
  return false;
}

int list_value_at(List *list, int position)
{
  Node *node = list->head->next;

  for(int i = 1; i <= position; i++)
  {
    if(i == position) return node->value;
    node = node->next;
  }

  return -1;
}

void list_push_front(List *list, int value)
{
  Node *old = list->head->next;
  Node *node = list_create_node(value);

  node->next = old;
  list->head->next = node;
}

int list_pop_front(List *list)
{
  Node *first_node = list->head->next;
  if(first_node == NULL) exit(1);

  Node *secondNode = first_node->next;
  list->head->next = secondNode;

  int const value = first_node->value;
  free(first_node);

  return value;
}

void list_push_back(List *list, int value)
{
  Node *node = list_create_node(value);

  Node *temp = list->head;
  while(temp->next != NULL) temp = temp->next;

  temp->next = node;
  list->tail->next = node;
}

int list_front(List *list)
{
  if (list->head->next == NULL) exit(1);
  return list->head->next->value;
}

int list_back(List *list)
{
  return list->tail->next->value;
}

void list_insert(List *list, unsigned int index, int value)
{
  unsigned int current_index = 0;
  Node *node = list_create_node(value);

  Node *previous_node = list->head;
  Node *current_node = list->head;

  while(current_index < index)
  {
    previous_node = current_node;
    current_node = current_node->next;
    current_index++;
  }

  node->next = current_node;
  previous_node->next = node;
}

void list_erase(List *list, unsigned int index)
{
  int unsigned current_index = 0;

  Node *previous_node = list->head;
  Node *current_node = list->head;

  while(current_index < index)
  {
    previous_node = current_node;
    current_node = current_node->next;
    current_index++;
  }

  previous_node->next = current_node->next;
  free(current_node);
}

void list_reverse(List *list)
{
  Node *previous_node = list->head->next;
  Node *current_node = list->head->next;
  Node *next_node = NULL;

  while(current_node->next != NULL)
  {
    next_node = current_node->next;
    current_node->next = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }

  list->tail->next = list->head->next;
  list->head->next = current_node;
}

void list_remove_value(List *list, int value)
{
  Node *previous_node = list->head;
  Node *current_node = list->head;

  while(current_node != NULL)
  {
    if (current_node->value == value)
    {
      previous_node->next = current_node->next;
      free(current_node);
      break;
    }

    previous_node = current_node;
    current_node = current_node->next;
  }
}
