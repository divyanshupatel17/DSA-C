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

#define MAX_SIZE 100 // Define the maximum size of the queue

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Enqueue an item to the queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = item;
}

// Dequeue an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int dequeuedItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedItem;
}

// Peek the first element
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    return q->arr[q->front];
}

// Display all items in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d  ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10); // Adds 10 to the queue
    enqueue(&q, 20); // Adds 20 to the queue
    enqueue(&q, 30); // Adds 30 to the queue

    printf("Display Queue:\n");
    display(&q); // Output: Display Queue:
                 //         10  20  30  

    printf("Dequeued element: %d\n", dequeue(&q)); // Output: Dequeued element: 10
    printf("Dequeued element: %d\n", dequeue(&q)); // Output: Dequeued element: 20
    printf("Peeked(front) element: %d\n", peek(&q)); // Output: Peeked(front) element: 30

    return 0;
}
