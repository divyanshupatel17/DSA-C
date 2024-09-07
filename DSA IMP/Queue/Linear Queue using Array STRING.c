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
#include <string.h>

#define MAX 100
#define NAME_LENGTH 50 // Maximum length of an animal name

typedef struct {
    char arr[MAX][NAME_LENGTH];
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

// Enqueue an item (animal name) to the queue
void enqueue(Queue *q, const char *item) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    strcpy(q->arr[++(q->rear)], item);
}

// Dequeue an item (animal name) from the queue
char* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    char *dequeueItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeueItem;
}

// Peek (get the front item) in the queue
char* peek(Queue *q) {
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
        printf("%s  ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q); // Queue initialized

    enqueue(&q, "Lion");    // Enqueue "Lion"
    enqueue(&q, "Tiger");   // Enqueue "Tiger"
    enqueue(&q, "Bear");    // Enqueue "Bear"
    enqueue(&q, "Elephant"); // Enqueue "Elephant"

    printf("Display Queue:\n");
    display(&q); // Output: Display Queue:
                 //         Lion  Tiger  Bear  Elephant

    printf("Dequeued item is: %s\n", dequeue(&q)); // Output: Dequeued item is: Lion
    printf("Dequeued item is: %s\n", dequeue(&q)); // Output: Dequeued item is: Tiger

    printf("Peeked(front) item is: %s\n", peek(&q)); // Output: Peeked(front) item is: Bear
    printf("Dequeued item is: %s\n", dequeue(&q)); // Output: Dequeued item is: Bear

    printf("Display Queue after dequeue operations:\n");
    display(&q); // Output: Display Queue after dequeue operations:
                 //         Elephant

    return 0;
}
