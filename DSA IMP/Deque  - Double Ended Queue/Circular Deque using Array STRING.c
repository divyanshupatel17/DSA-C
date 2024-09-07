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
#include <string.h>

#define MAX_SIZE 5 // Define the maximum size of the deque
#define STRING_LENGTH 20 // Maximum string length

typedef struct {
    char arr[MAX_SIZE][STRING_LENGTH];
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
void insertRear(Deque *dq, const char *item) {
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
    strncpy(dq->arr[dq->rear], item, STRING_LENGTH - 1);
    dq->arr[dq->rear][STRING_LENGTH - 1] = '\0'; // Ensure null termination
}

// Insert an item at the front end
void insertFront(Deque *dq, const char *item) {
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
    strncpy(dq->arr[dq->front], item, STRING_LENGTH - 1);
    dq->arr[dq->front][STRING_LENGTH - 1] = '\0'; // Ensure null termination
}

// Delete an item from the front end
char* deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    char* item = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return item;
}

// Delete an item from the rear end
char* deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    char* item = dq->arr[dq->rear];
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
        printf("%s  ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);

    insertRear(&dq, "Hello"); // Adds "Hello" to the rear
    insertRear(&dq, "World"); // Adds "World" to the rear
    insertFront(&dq, "Start"); // Adds "Start" to the front
    insertRear(&dq, "Deque"); // Adds "Deque" to the rear
    insertFront(&dq, "Beginning"); // Adds "Beginning" to the front

    printf("Display Deque:\n");
    display(&dq); // Output: Beginning  Start  Hello  World  Deque  

    printf("Deleted from front: %s\n", deleteFront(&dq)); // Output: Beginning
    printf("Deleted from rear: %s\n", deleteRear(&dq)); // Output: Deque

    printf("Display Deque:\n");
    display(&dq); // Output: Start  Hello  World  

    return 0;
}
