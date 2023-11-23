#if !defined(QUEUE_H)
#define QUEUE_H

#include "linked_list.h"

typedef struct Queue {
  List *data;
} Queue;

// create a queue.
Queue *queue_create();

// deletes a queue.
void *queue_free(Queue *queue);

// adds an item to the queue.
void queue_enqueue(Queue *queue, int value);

// removes the first item from the queue and returns it.
int queue_dequeue(Queue *queue);

// checks if the queue is empty or not.
bool queue_is_empty(Queue *queue);

#endif
