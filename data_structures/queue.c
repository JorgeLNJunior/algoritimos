#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "linked_list.h"

Queue *queue_create()
{
  List *data = list_create();
  Queue *queue = malloc(sizeof(Queue));

  if (queue == NULL) {
    printf("not enough memory");
    exit(1);
  }

  queue->data = data;
  return queue;
}

void *queue_free(Queue *queue)
{
  list_free(queue->data);
  free(queue);
}

void queue_enqueue(Queue *queue, int value)
{
  list_push_back(queue->data, value);
}

int queue_dequeue(Queue *queue)
{
  return list_pop_front(queue->data);
}

bool queue_is_empty(Queue *queue)
{
  return list_is_empty(queue->data);
}
