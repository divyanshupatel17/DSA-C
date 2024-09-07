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

#define MAX 100

typedef struct {
    char arr[MAX];
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
    return q->rear == MAX - 1;
}

// Enqueue a character to the queue
void enqueue(Queue *q, char item) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = item;
}

// Dequeue a character from the queue
char dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    char dequeueItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeueItem;
}

// Peek (get the front item) in the queue
char peek(Queue *q) {
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
        printf("%c  ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q); // Queue initialized

    enqueue(&q, 'a'); // Enqueue 'a'
    enqueue(&q, 'b'); // Enqueue 'b'
    enqueue(&q, 'c'); // Enqueue 'c'
    enqueue(&q, 'd'); // Enqueue 'd'

    printf("Display Queue:\n");
    display(&q); // Output: Display Queue:
                 //         a  b  c  d

    printf("Dequeued item is: %c\n", dequeue(&q)); // Output: Dequeued item is: a
    printf("Dequeued item is: %c\n", dequeue(&q)); // Output: Dequeued item is: b

    printf("Peeked(front) item is: %c\n", peek(&q)); // Output: Peeked(front) item is: c
    printf("Dequeued item is: %c\n", dequeue(&q)); // Output: Dequeued item is: c

    printf("Display Queue after dequeue operations:\n");
    display(&q); // Output: Display Queue after dequeue operations:
                 //         d

    return 0;
}
