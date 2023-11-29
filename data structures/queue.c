#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void init_queue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

void enqueue(Queue* queue, int value){
    if(isFull(queue)) {
        printf("Stack overflow\n");
        return;
    }

    if(isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Stack is empty\n");
        return;
    }
    queue->front = (queue->front + 1) % MAX;
}

int printQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = queue->front; i % MAX != queue->rear; i++) {
        printf(" %d ", queue->data[i]);
    }
    printf("\n");
}



int main()
{

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    init_queue(queue);

    printQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, -1);
    enqueue(queue, 0);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}
