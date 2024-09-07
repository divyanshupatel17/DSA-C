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

// peek first element 
int peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        exit(1);
    }
    return q->arr[q->front];
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued element: %d\n", dequeue(&q)); // Should print 10
    printf("Dequeued element: %d\n", dequeue(&q)); // Should print 20
    printf("Peeked(front) element: %d\n", peek(&q)); // Should print 20

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

typedef struct {
    char arr[MAX_SIZE];  // Change to char array
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
void enqueue(Queue *q, char item) {  // Change parameter to char
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
char dequeue(Queue *q) {  // Change return type to char
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    char dequeuedItem = q->arr[q->front];  // Store dequeued char element
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedItem;
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    printf("Dequeued element: %c\n", dequeue(&q)); // Should print 'A'
    printf("Dequeued element: %c\n", dequeue(&q)); // Should print 'B'

    return 0;
}

*/