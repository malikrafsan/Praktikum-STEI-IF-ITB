#include "boolean.h"
#include "queue.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Queue q;
  CreateQueue(&q);
  if (isEmpty(q))
    printf("Empty queue\n");
  else
    printf("Queue isn't empty\n");
  
  enqueue(&q,1);
  enqueue(&q,3);
  enqueue(&q,5);
  enqueue(&q,7);
  enqueue(&q,9);

  displayQueue(q);
  printf("\n");
  displayQueue(q);
  printf("\n");

  return 0;
}