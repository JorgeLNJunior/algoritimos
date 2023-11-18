#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

List *list_create()
{
  List *list = malloc(sizeof(List));
  list->head = list_create_node(0);
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
  Node *firstNode = list->head->next;
  if(firstNode == NULL) exit(1);

  Node *secondNode = firstNode->next;
  list->head->next = secondNode;

  int const value = firstNode->value;
  free(firstNode);

  return value;
}

void list_push_back(List *list, int value)
{
  Node *node = list_create_node(value);

  Node *temp = list->head;
  while(temp->next != NULL) temp = temp->next;

  temp->next = node;
}

int list_front(List *list)
{
  if (list->head->next == NULL) exit(1);
  return list->head->next->value;
}

int list_back(List *list)
{
  Node *node = list->head;
  while(node->next != NULL) node = node->next;
  return node->value;
}

void list_insert(List *list, unsigned int index, int value)
{
  unsigned int currentIndex = 0;
  Node *node = list_create_node(value);

  Node *previousNode = list->head;
  Node *currentNode = list->head;

  while(currentIndex < index)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
    currentIndex++;
  }

  node->next = currentNode;
  previousNode->next = node;
}

void list_erase(List *list, unsigned int index)
{
  int unsigned currentIndex = 0;

  Node *previousNode = list->head;
  Node *currentNode = list->head;

  while(currentIndex < index)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
    currentIndex++;
  }

  previousNode->next = currentNode->next;
  free(currentNode);
}

void list_reverse(List *list)
{
  Node *previousNode = list->head->next;
  Node *currentNode = list->head->next;
  Node *nextNode = NULL;

  while(currentNode->next != NULL)
  {
    nextNode = currentNode->next;
    currentNode->next = previousNode;
    previousNode = currentNode;
    currentNode = nextNode;
  }

  list->head->next = currentNode;
}

void list_remove_value(List *list, int value)
{
  Node *previousNode = list->head;
  Node *currentNode = list->head;

  while(currentNode != NULL)
  {
    if (currentNode->value == value)
    {
      previousNode->next = currentNode->next;
      free(currentNode);
      break;
    }

    previousNode = currentNode;
    currentNode = currentNode->next;
  }
}
