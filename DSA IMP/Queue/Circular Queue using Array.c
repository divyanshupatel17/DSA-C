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
    return (q->rear + 1) % MAX_SIZE == q->front;         // different line than Linear queue
}

// Enqueue an item to the queue
void enqueue(CircularQueue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;                                        // different line than Linear queue
    } else {                                                // different line than Linear queue
        q->rear = (q->rear + 1) % MAX_SIZE;                 // different line than Linear queue
    }                                                       // different line than Linear queue
    q->arr[q->rear] = item;                                 // different line than Linear queue
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
        q->front = (q->front + 1) % MAX_SIZE;                // different line than Linear queue
    }
    return dequeuedItem;
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 10
    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 20

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 30
    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 40

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the queue

typedef struct {
    char arr[MAX_SIZE];  // Change the array type from int to char
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
void enqueue(CircularQueue *q, char item) {  // Change parameter type from int to char
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
char dequeue(CircularQueue *q) {  // Change return type from int to char
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    char dequeuedItem = q->arr[q->front];  // Change the variable type to char
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 'A');  // Enqueue char elements instead of int
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    printf("Dequeued element: %c\n", dequeue(&q));  // Should print 'A'
    printf("Dequeued element: %c\n", dequeue(&q));  // Should print 'B'

    enqueue(&q, 'D');
    enqueue(&q, 'E');
    enqueue(&q, 'F');

    printf("Dequeued element: %c\n", dequeue(&q));  // Should print 'C'
    printf("Dequeued element: %c\n", dequeue(&q));  // Should print 'D'

    return 0;
}

 */