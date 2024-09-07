// FUNCTION : 

// initialize
// isEmpty
// isFull
// enqueue
// dequeue
// peek
// display

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the queue

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Initialize the circular queue
void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Enqueue an item to the queue
void enqueue(CircularQueue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = item;
}

// Dequeue an item from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int dequeuedItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

// Peek the front element
int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    return q->arr[q->front];
}

// Display all items in the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d  ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 10); // Adds 10 to the queue
    enqueue(&q, 20); // Adds 20 to the queue
    enqueue(&q, 30); // Adds 30 to the queue

    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 10
    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 20

    enqueue(&q, 40); // Adds 40 to the queue
    enqueue(&q, 50); // Adds 50 to the queue
    enqueue(&q, 60); // Adds 60 to the queue

    printf("Display Queue:\n");
    display(&q);     // Output: Display Queue:
                     //         30  40  50  60  

    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 30
    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 40

    return 0;
}
