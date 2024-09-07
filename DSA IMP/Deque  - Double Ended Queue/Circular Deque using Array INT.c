// FUNCTION : 

// initialize
// isEmpty
// isFull
// insertRear
// insertFront
// deleteFront
// deleteRear
// display

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the deque

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Deque;

// Initialize the deque
void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if the deque is empty
int isEmpty(Deque *dq) {
    return dq->front == -1;
}

// Check if the deque is full
int isFull(Deque *dq) {
    return (dq->front == (dq->rear + 1) % MAX_SIZE);
}

// Insert an item at the rear end
void insertRear(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->arr[dq->rear] = item;
}

// Insert an item at the front end
void insertFront(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->arr[dq->front] = item;
}

// Delete an item from the front end
int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    int item = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return item;
}

// Delete an item from the rear end
int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    int item = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return item;
}

// Display all items in the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%d  ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);

    insertRear(&dq, 10); // Adds 10 to the rear
    insertRear(&dq, 20); // Adds 20 to the rear
    insertFront(&dq, 5); // Adds 5 to the front
    insertRear(&dq, 30); // Adds 30 to the rear
    insertFront(&dq, 1); // Adds 1 to the front

    printf("Display Deque:\n");
    display(&dq); // Output: 1  5  10  20  30  

    printf("Deleted from front: %d\n", deleteFront(&dq)); // Output: 1
    printf("Deleted from rear: %d\n", deleteRear(&dq)); // Output: 30

    printf("Display Deque:\n");
    display(&dq); // Output: 5  10  20  

    return 0;
}
