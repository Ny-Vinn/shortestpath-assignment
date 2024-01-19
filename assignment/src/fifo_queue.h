#ifndef FIFO_QUEUE_H_INCLUDED
#define FIFO_QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*--------- Opaque Struct definitions ---------*/

typedef struct qNode qNode;
typedef struct fifo_queue fifo_queue;

/*--------- Public Function definitions ---------*/

fifo_queue* createQueue(fifo_queue *q);
int isEmpty(fifo_queue *q);
void push(fifo_queue *q, int cityIndex);
int pop(fifo_queue *q);

#endif
