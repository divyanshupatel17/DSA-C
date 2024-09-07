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

#define MAX_SIZE 100  // Define the maximum size of the queue
#define MAX_NAME_LEN 50  // Define the maximum length for each animal name

typedef struct {
    char arr[MAX_SIZE][MAX_NAME_LEN];
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

// Enqueue an item (animal name) to the queue
void enqueue(CircularQueue *q, const char *item) {
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
    strncpy(q->arr[q->rear], item, MAX_NAME_LEN - 1);
    q->arr[q->rear][MAX_NAME_LEN - 1] = '\0';  // Ensure null-termination
}

// Dequeue an item (animal name) from the queue
void dequeue(CircularQueue *q, char *item) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    strncpy(item, q->arr[q->front], MAX_NAME_LEN - 1);
    item[MAX_NAME_LEN - 1] = '\0';  // Ensure null-termination
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

// Peek the front element
void peek(CircularQueue *q, char *item) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    strncpy(item, q->arr[q->front], MAX_NAME_LEN - 1);
    item[MAX_NAME_LEN - 1] = '\0';  // Ensure null-termination
}

// Display all items in the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%s  ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, "Lion");      // Adds "Lion" to the queue
    enqueue(&q, "Tiger");     // Adds "Tiger" to the queue
    enqueue(&q, "Elephant");  // Adds "Elephant" to the queue

    char item[MAX_NAME_LEN];

    dequeue(&q, item);  // Output: Dequeued element: Lion
    printf("Dequeued element: %s\n", item);

    dequeue(&q, item);  // Output: Dequeued element: Tiger
    printf("Dequeued element: %s\n", item);

    enqueue(&q, "Giraffe");   // Adds "Giraffe" to the queue
    enqueue(&q, "Zebra");     // Adds "Zebra" to the queue
    enqueue(&q, "Monkey");    // Adds "Monkey" to the queue

    printf("Display Queue:\n");
    display(&q);  // Output: Display Queue:
                  //         Elephant  Giraffe  Zebra  Monkey  

    dequeue(&q, item);  // Output: Dequeued element: Elephant
    printf("Dequeued element: %s\n", item);

    dequeue(&q, item);  // Output: Dequeued element: Giraffe
    printf("Dequeued element: %s\n", item);

    return 0;
}
