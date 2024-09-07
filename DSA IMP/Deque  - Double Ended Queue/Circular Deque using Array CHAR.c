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
    char arr[MAX_SIZE];
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
void insertRear(Deque *dq, char item) {
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
void insertFront(Deque *dq, char item) {
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
char deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    char item = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return item;
}

// Delete an item from the rear end
char deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    char item = dq->arr[dq->rear];
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
        printf("%c  ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);

    insertRear(&dq, 'A'); // Adds 'A' to the rear
    insertRear(&dq, 'B'); // Adds 'B' to the rear
    insertFront(&dq, 'Z'); // Adds 'Z' to the front
    insertRear(&dq, 'C'); // Adds 'C' to the rear
    insertFront(&dq, 'Y'); // Adds 'Y' to the front

    printf("Display Deque:\n");
    display(&dq); // Output: Y  Z  A  B  C  

    printf("Deleted from front: %c\n", deleteFront(&dq)); // Output: Y
    printf("Deleted from rear: %c\n", deleteRear(&dq)); // Output: C

    printf("Display Deque:\n");
    display(&dq); // Output: Z  A  B  

    return 0;
}
