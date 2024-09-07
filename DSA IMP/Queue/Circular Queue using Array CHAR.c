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
    char arr[MAX_SIZE];
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

// Enqueue an item (character) to the queue
void enqueue(CircularQueue *q, char item) {
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

// Dequeue an item (character) from the queue
char dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    char dequeuedItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

// Peek the front element
char peek(CircularQueue *q) {
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
        printf("%c  ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 'A'); // Adds 'A' to the queue
    enqueue(&q, 'B'); // Adds 'B' to the queue
    enqueue(&q, 'C'); // Adds 'C' to the queue

    printf("Dequeued element: %c\n", dequeue(&q));  // Output: Dequeued element: A
    printf("Dequeued element: %c\n", dequeue(&q));  // Output: Dequeued element: B

    enqueue(&q, 'D'); // Adds 'D' to the queue
    enqueue(&q, 'E'); // Adds 'E' to the queue
    enqueue(&q, 'F'); // Adds 'F' to the queue

    printf("Display Queue:\n");
    display(&q);     // Output: Display Queue:
                     //         C  D  E  F  

    printf("Dequeued element: %c\n", dequeue(&q));  // Output: Dequeued element: C
    printf("Dequeued element: %c\n", dequeue(&q));  // Output: Dequeued element: D

    return 0;
}
