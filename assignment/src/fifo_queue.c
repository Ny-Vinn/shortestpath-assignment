#include "fifo_queue.h"

struct qNode {
    int cityIndex;
    struct qNode* next;
};

struct fifo_queue {
    int count;
    qNode* front;
    qNode* rear;
};

/* Set of functions to interact with a FIFO queue */

/* Initialises a q with default values and returns it */
fifo_queue* createQueue(fifo_queue* q) {
    q = malloc(sizeof(fifo_queue));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

/* Checks to see if a queue is empty based on the number of elements within it */
int isEmpty(fifo_queue* q) {
    int empty;
    if(q->count == 0){
        empty = 1;
    } else {
        empty = 0;
    }
    return empty;
}

/* Appends a cities' index to the end of the queue */
void push(fifo_queue* q, int cityIndex) {
    qNode* temp;
    temp = malloc(sizeof(qNode));
    temp->cityIndex = cityIndex;
    temp->next = NULL;

    if(isEmpty(q) == 0) {
        q->rear->next = temp;
        q->rear = temp;
    } else {
        q->front = temp;
        q->rear = temp;
    }

    q->count++;
}

/* Removes the front element of the queue and frees the memory associated with it */
int pop(fifo_queue* q) {
    qNode* temp;
    int n = q->front->cityIndex;
    temp = q->front;
    q->front = q->front->next;
    q->count--;
    free(temp);

    return n;
}
