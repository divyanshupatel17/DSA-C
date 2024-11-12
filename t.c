1. Stack(array)
2. Linear QUEUE INT
3. Circular Queue INT
4. LINEAR DEQUE INT
5. CIRCULAR DEQUE INT
6. SINGLE LL (LINEAR)
7. SINGLE LL (CIRCULAR)
8. DOUBLY LL (LINEAR)
9. DOUBLE LL (CIRCULAR)
10. LL FUNCTION (sort, reverse, removeDuplicate, rotateClockwise, concatTwoLL, SplitInHalf, SplitInEvenOdd
11. BFS DFS (1. Traversal , 2. isBipartite, 3.longest conc path, 4.connected compontents , 5. shortest cycle , 6. hasCycle, 7. shortest path)
12. DIJKSTRA
13. MST
14. BINARY TREE 

=====================================================================
1. Stack(array)

// FUNCTIONS :

// initialize
// isEmpty
// isFull
// push
// pop
// peek
// display

// INTEGER 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

// Pop an item from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[(s->top)--];
}

// Peek the top item without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[s->top];
}

// Display all elements in the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s)); // Should print 30

    printf("Popped element: %d\n", pop(&s)); // Should print 30
    printf("Popped element: %d\n", pop(&s)); // Should print 20

    display(&s); // Should print: Stack elements: 10

    return 0;
}


// CHAR

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

typedef struct {
    char arr[MAX_SIZE]; // Change the array type from int to char
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(Stack *s, char item) { // Change parameter type from int to char
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

// Pop an item from the stack
char pop(Stack *s) { // Change return type from int to char
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[(s->top)--];
}

// Peek the top item without removing it
char peek(Stack *s) { // Change return type from int to char
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[s->top];
}

// Display all elements in the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 'A'); // Pushing char elements instead of int
    push(&s, 'B');
    push(&s, 'C');

    printf("Top element: %c\n", peek(&s)); // Should print 'C'

    printf("Popped element: %c\n", pop(&s)); // Should print 'C'
    printf("Popped element: %c\n", pop(&s)); // Should print 'B'

    display(&s); // Should print: Stack elements: A 

    return 0;
}


// STRING
/*
Key Differences Between strncpy and strcpy:

strncpy -> limits the number of characters copied and does not necessarily null-terminate the string if the source string is longer than the specified limit. You need to handle null-termination manually, if needed.
char *strncpy(char *destination, const char *source, size_t num);

strcpy -> copies the entire string, including the null-terminator, but it doesn't perform bounds checking, which can lead to buffer overflows if the
char *strcpy(char *destination, const char *source);

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Define the maximum size of the stack
#define STRING_LENGTH 50 // Define the maximum length of strings

typedef struct {
    char arr[MAX_SIZE][STRING_LENGTH]; // Array of strings
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push a string onto the stack
void push(Stack *s, char *item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    strncpy(s->arr[++(s->top)], item, STRING_LENGTH - 1);
    s->arr[s->top][STRING_LENGTH - 1] = '\0'; // Ensure null termination
}

// Pop a string from the stack
char* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[(s->top)--];
}

// Peek the top string without removing it
char* peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->arr[s->top];
}

// Display all elements in the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%s ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, "Hello"); // Pushing string elements
    push(&s, "World");
    push(&s, "Stack");

    printf("Top element: %s\n", peek(&s)); // Should print 'Stack'

    printf("Popped element: %s\n", pop(&s)); // Should print 'Stack'
    printf("Popped element: %s\n", pop(&s)); // Should print 'World'

    display(&s); // Should print: Stack elements: Hello 

    return 0;
}

=====================================================================
2. Linear QUEUE INT

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

=====================================================================
3. CIRCULAR QUEUE INT

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
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Enqueue an item to the queue
void enqueue(CircularQueue *q, int item) {
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
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

// Peek the front element
int peek(CircularQueue *q) {
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
        printf("%d  ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 10); // Adds 10 to the queue
    enqueue(&q, 20); // Adds 20 to the queue
    enqueue(&q, 30); // Adds 30 to the queue

    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 10
    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 20

    enqueue(&q, 40); // Adds 40 to the queue
    enqueue(&q, 50); // Adds 50 to the queue
    enqueue(&q, 60); // Adds 60 to the queue

    printf("Display Queue:\n");
    display(&q);     // Output: Display Queue:
                     //         30  40  50  60  

    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 30
    printf("Dequeued element: %d\n", dequeue(&q));  // Output: Dequeued element: 40

    return 0;
}


=====================================================================
4. LINEAR DEQUE INT

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
    return dq->rear == MAX_SIZE - 1;
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
        dq->rear++;
    }
    dq->arr[dq->rear] = item;
}

// Insert an item at the front end
void insertFront(Deque *dq, int item) {
    if (dq->front == 0 || isFull(dq)) {
        printf("Cannot insert at front. Deque is full or front is at position 0!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front--;
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
        dq->front++;
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
        dq->rear--;
    }
    return item;
}

// Display all items in the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    for (int i = dq->front; i <= dq->rear; i++) {
        printf("%d  ", dq->arr[i]);
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

=====================================================================
5. CIRCULAR DEQUE INT 


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

=====================================================================
6. SINGLE LL (LINEAR)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// 1. Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2. Function to insert at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
    }
    // CASE 3: Otherwise, insert at the beginning
    else {
        newNode->next = *head;
        *head = newNode;
    }
    return *head;
}

// 3. Function to insert at the end
struct Node* insertAtEnd(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return *head;
    }
    
    // CASE 3: Otherwise, traverse to the end and insert
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return *head;
}

// 4. Function to insert at a specific position
struct Node* insertAtPosition(struct Node** head, int data, int pos) {
    // CASE 1: If position is 1, insert at beginning
    if (pos == 1) {
        return insertAtBeginning(head, data);
    }
    
    // CASE 2: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 3: Traverse to the position and insert
    struct Node* current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // CASE 4: If position is out of range
    if (current == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return *head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return *head;
}

// 5. Function to insert after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    // CASE 1: If previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    // CASE 2: Create a new node and insert after prevNode
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// 6. Function to insert new data in place of old data
struct Node* insertInPlace(struct Node** head, int oldData, int newData) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return *head;
    }
    
    // CASE 2: Traverse the list and replace old data with new data
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return *head;
        }
        current = current->next;
    }
    
    // CASE 3: If old data not found
    printf("Old data not found in the list\n");
    return *head;
}

// 7. Function to delete at the beginning
struct Node* deleteAtBeginning(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: Delete the first node
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return *head;
}

// 8. Function to delete at the end
struct Node* deleteAtEnd(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Traverse to the second last node
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Delete the last node
    free(current->next);
    current->next = NULL;
    return *head;
}

// 9. Function to delete at a specific position
struct Node* deleteAtPosition(struct Node** head, int position) {
    // CASE 1: If head is NULL or position is less than 1
    if (*head == NULL || position < 1) {
        return *head;
    }
    
    // CASE 2: If first position
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: If valid position
    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return *head;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return *head;
}

// 10. Function to delete a node with a specific key
struct Node* deleteNode(struct Node** head, int key) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If key is in the first node
    if ((*head)->data == key) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: Traverse the list to find the key
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    // CASE 4: If key not found
    if (current == NULL) {
        printf("Key not found in the list\n");
        return *head;
    }
    
    // Delete the node with the key
    prev->next = current->next;
    free(current);
    return *head;
}

// 11. Function to search for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: Traverse the list to find the key
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    
    // CASE 3: If key not found
    printf("Key not found in the list\n");
    return NULL;
}

// 12. Function to traverse and print the list
void traverseList(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Traverse and print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 13. Function to find the length of the list
int lengthOfList(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 14. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: If head is NULL or only one node
    if (*head == NULL || (*head)->next == NULL) {
        return *head;
    }
    
    // CASE 2: Reverse the list
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
    return *head;
}

// 15. Function to find the middle node
void findMiddleNode(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Use slow and fast pointers to find the middle
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    printf("Middle node: %d\n", slow->data);
}

// 16. Function to detect a loop in the list
int detectLoop(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        return 0;
    }
    
    // CASE 2: Use Floyd's cycle-finding algorithm
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // Loop detected
        }
    }
    
    return 0; // No loop
}

// 17. Function to remove duplicates from the list
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: If head is NULL or only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // CASE 2: Traverse the list and remove duplicates
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    return head;
}

int main() {
    struct Node* head = NULL;
    
    // 2. Insert at beginning
    head = insertAtBeginning(&head, 10);
    head = insertAtBeginning(&head, 20);
    head = insertAtBeginning(&head, 30);
    printf("After inserting at beginning: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 10 -> NULL
    
    // 3. Insert at end
    head = insertAtEnd(&head, 40);
    head = insertAtEnd(&head, 50);
    printf("After inserting at end: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 10 -> 40 -> 50 -> NULL
    
    // 4. Insert at position
    head = insertAtPosition(&head, 25, 3);
    printf("After inserting 25 at position 3: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 25 -> 10 -> 40 -> 50 -> NULL
    
    // 5. Insert after node
    struct Node* node = searchNode(head, 25);
    if (node != NULL) {
        insertAfterNode(node, 35);
    }
    printf("After inserting 35 after 25: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 6. Insert in place
    head = insertInPlace(&head, 20, 22);
    printf("After replacing 20 with 22: ");
    traverseList(head);
    // Expected output: 30 -> 22 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 7. Delete at beginning
    head = deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 8. Delete at end
    head = deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 35 -> 10 -> 40 -> NULL
    
    // 9. Delete at position
    head = deleteAtPosition(&head, 3);
    printf("After deleting at position 3: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 10 -> 40 -> NULL
    
    // 10. Delete node with key
    head = deleteNode(&head, 25);
    printf("After deleting node with key 25: ");
    traverseList(head);
    // Expected output: 22 -> 10 -> 40 -> NULL
    
    // 11. Search for a node
    struct Node* foundNode = searchNode(head, 10);
    if (foundNode != NULL) {
        printf("Node with key 10 found\n");
    }
    
    // 13. Length of list
    printf("Length of list: %d\n", lengthOfList(head));
    // Expected output: Length of list: 3
    
    // 14. Reverse list
    head = reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head);
    // Expected output: 40 -> 10 -> 22 -> NULL
    
    // 15. Find middle node
    findMiddleNode(head);
    // Expected output: Middle node: 10
    
    // 16. Detect loop (no loop in this case)
    if (detectLoop(head)) {
        printf("Loop detected in the list\n");
    } else {
        printf("No loop detected in the list\n");
    }
    // Expected output: No loop detected in the list
    
    // 17. Remove duplicates (add some duplicates first)
    head = insertAtEnd(&head, 10);
    head = insertAtEnd(&head, 40);
    printf("Before removing duplicates: ");
    traverseList(head);
    head = removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head);
    // Expected output: 40 -> 10 -> 22

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// /* 
//    Singly Linked List Operations:

//    1. **createNode(int data)**: 
//       - Creates a new node with given data, next pointer set to NULL.

//    2. **insert**:
//      - **insertAtBeginning(struct Node** head, int data)**: Inserts a node at the beginning.
//      - **insertAtEnd(struct Node** head, int data)**: Inserts a node at the end.
//      - **insertAtPosition(struct Node** head, int data, int pos)**: Inserts a node at a specific position.
//      - **insertAfterNode(struct Node* prevNode, int data)**: Inserts a node after a given node.
//      - **insertInPlace(struct Node** head, int oldData, int newData)**: Inserts new data in place of old data.

//    3. **delete**:
//      - **deleteAtBeginning(struct Node** head)**: Deletes the node at the beginning.
//      - **deleteAtEnd(struct Node** head)**: Deletes the node at the end.
//      - **deleteAtPosition(struct Node** head, int pos)**: Deletes the node at a specific position.
//      - **deleteNode(struct Node** head, int key)**: Deletes a node with the specified key.

//    4. **searchNode(struct Node* head, int key)**: Searches for a node with a specific key.

//    5. **traverseList(struct Node* head)**: Prints all nodes in the list from head to end.

//    6. **lengthOfList(struct Node* head)**: Returns the number of nodes in the list.

//    7. **reverseList(struct Node** head)**: Reverses the list.

//    8. **findMiddleNode(struct Node* head)**: Finds and prints the middle node.

//    9. **detectLoop(struct Node* head)**: Detects if there is a loop in the list.

//    10. **removeDuplicates(struct Node* head)**: Removes duplicate nodes from the list.
// */

// // Definition of a singly linked list node
// struct Node {
//     int data;
//     struct Node* next;
// };

// // 1. **createNode**: Creates a new node with given data
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode != NULL) {
//         newNode->data = data;
//         newNode->next = NULL;
//     } else {
//         printf("Memory allocation failed\n");
//     }
//     return newNode;
// }

// // 2. **insertAtBeginning**: Inserts a node at the beginning
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (newNode != NULL) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         printf("Failed to insert at beginning\n");
//     }
// }

// // 2. **insertAtEnd**: Inserts a node at the end
// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         if (newNode != NULL) {
//             *head = newNode;
//         }
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         if (newNode != NULL) {
//             temp->next = newNode;
//         } else {
//             printf("Failed to insert at end\n");
//         }
//     }
// }

// // 2. **insertAtPosition**: Inserts a node at a specific position
// void insertAtPosition(struct Node** head, int data, int pos) {
//     struct Node* newNode = createNode(data);
//     if (newNode != NULL) {
//         if (pos == 0) {
//             insertAtBeginning(head, data);
//         } else {
//             struct Node* temp = *head;
//             for (int i = 1; i < pos && temp != NULL; i++) {
//                 temp = temp->next;
//             }
//             if (temp != NULL) {
//                 newNode->next = temp->next;
//                 temp->next = newNode;
//             } else {
//                 printf("Position out of bounds\n");
//             }
//         }
//     } else {
//         printf("Failed to insert at position\n");
//     }
// }

// // 2. **insertAfterNode**: Inserts a node after a given node
// void insertAfterNode(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("The given previous node cannot be NULL\n");
//     } else {
//         struct Node* newNode = createNode(data);
//         if (newNode != NULL) {
//             newNode->next = prevNode->next;
//             prevNode->next = newNode;
//         } else {
//             printf("Failed to insert after node\n");
//         }
//     }
// }

// // 2. **insertInPlace**: Inserts new data in place of old data
// void insertInPlace(struct Node** head, int oldData, int newData) {
//     struct Node* temp = *head;
//     while (temp != NULL) {
//         if (temp->data == oldData) {
//             temp->data = newData;
//             return;
//         }
//         temp = temp->next;
//     }
//     printf("Data %d not found in the list\n", oldData);
// }

// // 3. **deleteAtBeginning**: Deletes the node at the beginning
// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else {
//         struct Node* temp = *head;
//         *head = (*head)->next;
//         free(temp);
//     }
// }

// // 3. **deleteAtEnd**: Deletes the node at the end
// void deleteAtEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if ((*head)->next == NULL) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next->next != NULL) {
//             temp = temp->next;
//         }
//         free(temp->next);
//         temp->next = NULL;
//     }
// }

// // 3. **deleteAtPosition**: Deletes the node at a specific position
// void deleteAtPosition(struct Node** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if (pos == 0) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         for (int i = 1; i < pos && temp->next != NULL; i++) {
//             temp = temp->next;
//         }
//         if (temp->next != NULL) {
//             struct Node* delNode = temp->next;
//             temp->next = temp->next->next;
//             free(delNode);
//         } else {
//             printf("Position out of bounds\n");
//         }
//     }
// }

// // 3. **deleteNode**: Deletes a node with the specified key
// void deleteNode(struct Node** head, int key) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if ((*head)->data == key) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != NULL && temp->next->data != key) {
//             temp = temp->next;
//         }
//         if (temp->next != NULL) {
//             struct Node* delNode = temp->next;
//             temp->next = temp->next->next;
//             free(delNode);
//         } else {
//             printf("Key %d not found in the list\n", key);
//         }
//     }
// }

// // 4. **searchNode**: Searches for a node with a specific key
// void searchNode(struct Node* head, int key) {
//     struct Node* temp = head;
//     int found = 0; // Flag to check if the node is found
//     while (temp != NULL) {
//         if (temp->data == key) {
//             found = 1;
//             break;
//         }
//         temp = temp->next;
//     }
//     if (found) {
//         printf("Node with key %d found\n", key);
//     } else {
//         printf("Node with key %d not found\n", key);
//     }
// }

// // 5. **traverseList**: Prints all nodes in the list from head to end
// void traverseList(struct Node* head) {
//     struct Node* temp = head;
//     if (temp == NULL) {
//         printf("List is empty\n");
//     } else {
//         while (temp != NULL) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// // 6. **lengthOfList**: Returns the number of nodes in the list
// void lengthOfList(struct Node* head) {
//     int count = 0;
//     struct Node* temp = head;
//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }
//     printf("Length of the list: %d\n", count);
// }

// // 7. **reverseList**: Reverses the list
// void reverseList(struct Node** head) {
//     struct Node* prev = NULL;
//     struct Node* current = *head;
//     struct Node* next = NULL;
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head = prev;
// }

// // 8. **findMiddleNode**: Finds and prints the middle node
// void findMiddleNode(struct Node* head) {
//     struct Node* slow = head;
//     struct Node* fast = head;
//     if (head == NULL) {
//         printf("List is empty, no middle node\n");
//     } else {
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         printf("Middle node: %d\n", slow->data);
//     }
// }

// // 9. **detectLoop**: Detects if there is a loop in the list
// void detectLoop(struct Node* head) {
//     struct Node* slow = head;
//     struct Node* fast = head;
//     int loopExists = 0; // Flag to check if loop exists
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast) {
//             loopExists = 1;
//             break;
//         }
//     }
//     if (loopExists) {
//         printf("Loop detected in the list\n");
//     } else {
//         printf("No loop detected in the list\n");
//     }
// }

// // 10. **removeDuplicates**: Removes duplicate nodes from the list
// void removeDuplicates(struct Node* head) {
//     struct Node* current = head;
//     struct Node* nextNode;
//     if (current == NULL) {
//         printf("List is empty, cannot remove duplicates\n");
//     } else {
//         while (current->next != NULL) {
//             if (current->data == current->next->data) {
//                 nextNode = current->next->next;
//                 free(current->next);
//                 current->next = nextNode;
//             } else {
//                 current = current->next;
//             }
//         }
//     }
// }

// // Main function to demonstrate the linked list operations
// int main() {
//     struct Node* head = NULL;

//     // Insert nodes at the end
//     insertAtEnd(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 30);
    
//     // Print list
//     printf("Initial List: ");
//     traverseList(head); // Expected: 10 -> 20 -> 20 -> 30 -> NULL

//     // Insert at beginning
//     insertAtBeginning(&head, 5);
//     printf("After inserting at beginning: ");
//     traverseList(head); // Expected: 5 -> 10 -> 20 -> 20 -> 30 -> NULL

//     // Insert at position
//     insertAtPosition(&head, 15, 2);
//     printf("After inserting 15 at position 2: ");
//     traverseList(head); // Expected: 5 -> 10 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Insert after a node
//     insertAfterNode(head->next, 12); // Insert after node with data 10
//     printf("After inserting 12 after 10: ");
//     traverseList(head); // Expected: 5 -> 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Delete at beginning
//     deleteAtBeginning(&head);
//     printf("After deleting at beginning: ");
//     traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Delete at end
//     deleteAtEnd(&head);
//     printf("After deleting at end: ");
//     traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> NULL

//     // Delete at position
//     deleteAtPosition(&head, 1);
//     printf("After deleting at position 1: ");
//     traverseList(head); // Expected: 10 -> 15 -> 20 -> NULL

//     // Delete node
//     deleteNode(&head, 15);
//     printf("After deleting node with key 15: ");
//     traverseList(head); // Expected: 10 -> 20 -> NULL

//     // Search for a node
//     searchNode(head, 10); // Expected: Node with key 10 found
//     searchNode(head, 15); // Expected: Node with key 15 not found

//     // Get length of list
//     lengthOfList(head); // Expected: Length of the list: 2

//     // Reverse the list
//     reverseList(&head);
//     printf("After reversing the list: ");
//     traverseList(head); // Expected: 20 -> 10 -> NULL

//     // Find middle node
//     findMiddleNode(head); // Expected: Middle node: 20

//     // Detect loop
//     detectLoop(head); // Expected: No loop detected in the list

//     // Remove duplicates
//     insertAtEnd(&head, 20); // Adding duplicate for testing
//     insertAtEnd(&head, 20);
//     printf("List before removing duplicates: ");
//     traverseList(head); // Expected: 20 -> 10 -> 20 -> 20 -> NULL
//     removeDuplicates(head);
//     printf("After removing duplicates: ");
//     traverseList(head); // Expected: 20 -> 10 -> NULL

//     return 0;
// }

=====================================================================
7. SINGLE LL (CIRCULAR)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// 1. Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;  // Points to itself in a circular list
    return newNode;
}

// 2. Function to insert at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
    }
    // CASE 3: Otherwise, insert at the beginning
    else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
    return *head;
}

// 3. Function to insert at the end
struct Node* insertAtEnd(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return *head;
    }
    
    // CASE 3: Otherwise, traverse to the end and insert
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
    return *head;
}

// 4. Function to insert at a specific position
struct Node* insertAtPosition(struct Node** head, int data, int pos) {
    // CASE 1: If position is 1, insert at beginning
    if (pos == 1) {
        return insertAtBeginning(head, data);
    }
    
    // CASE 2: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 3: Traverse to the position and insert
    struct Node* current = *head;
    for (int i = 1; i < pos - 1 && current->next != *head; i++) {
        current = current->next;
    }
    
    // CASE 4: If position is out of range
    if (current->next == *head && pos > 2) {
        printf("Position out of range\n");
        free(newNode);
        return *head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return *head;
}

// 5. Function to insert after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    // CASE 1: If previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    // CASE 2: Create a new node and insert after prevNode
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// 6. Function to insert new data in place of old data
struct Node* insertInPlace(struct Node** head, int oldData, int newData) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return *head;
    }
    
    // CASE 2: Traverse the list and replace old data with new data
    struct Node* current = *head;
    do {
        if (current->data == oldData) {
            current->data = newData;
            return *head;
        }
        current = current->next;
    } while (current != *head);
    
    // CASE 3: If old data not found
    printf("Old data not found in the list\n");
    return *head;
}

// 7. Function to delete at the beginning
struct Node* deleteAtBeginning(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Delete the first node
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    last->next = *head;
    free(temp);
    return *head;
}

// 8. Function to delete at the end
struct Node* deleteAtEnd(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Traverse to the second last node
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != *head) {
        prev = current;
        current = current->next;
    }
    
    // Delete the last node
    prev->next = *head;
    free(current);
    return *head;
}

// 9. Function to delete at a specific position
struct Node* deleteAtPosition(struct Node** head, int position) {
    // CASE 1: If head is NULL or position is less than 1
    if (*head == NULL || position < 1) {
        return *head;
    }
    
    // CASE 2: If first position
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: If valid position
    struct Node* current = *head;
    struct Node* prev = NULL;
    int i;
    for (i = 1; i < position && current->next != *head; i++) {
        prev = current;
        current = current->next;
    }
    
    if (i != position) {
        printf("Position out of range\n");
        return *head;
    }
    
    prev->next = current->next;
    free(current);
    return *head;
}

// 10. Function to delete a node with a specific key
struct Node* deleteNode(struct Node** head, int key) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If key is in the first node
    if ((*head)->data == key) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: Traverse the list to find the key
    struct Node* current = *head;
    struct Node* prev = NULL;
    do {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            return *head;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    
    // CASE 4: If key not found
    printf("Key not found in the list\n");
    return *head;
}

// 11. Function to search for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: Traverse the list to find the key
    struct Node* current = head;
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
    // CASE 3: If key not found
    printf("Key not found in the list\n");
    return NULL;
}

// 12. Function to traverse and print the list
void traverseList(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Traverse and print the list
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to start)\n");
}

// 13. Function to find the length of the list
int lengthOfList(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct Node* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// 14. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: If head is NULL or only one node
    if (*head == NULL || (*head)->next == *head) {
        return *head;
    }
    
    // CASE 2: Reverse the list
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    
    (*head)->next = prev;
    *head = prev;
    return *head;
}

// 15. Function to find the middle node
void findMiddleNode(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Use slow and fast pointers to find the middle
    struct Node* slow = head;
    struct Node* fast = head;
    
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    
    printf("Middle node: %d\n", slow->data);
}

// 16. Function to detect a loop in the list
// Note: In a circular linked list, there's always a loop
int detectLoop(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1;  // Always returns 1 for a circular linked list
}

// 17. Function to remove duplicates from the list
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: If head is NULL or only one node
    if (head == NULL || head->next == head) {
        return head;
    }
    
    // CASE 2: Traverse the list and remove duplicates
    struct Node* current = head;
    do {
        struct Node* runner = current;
        while (runner->next != head) {
            if (runner->next->data == current->data) {
                struct Node* temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != head);
    
    return head;
}

int main() {
    struct Node* head = NULL;
    
    // 2. Insert at beginning
    head = insertAtBeginning(&head, 10);
    head = insertAtBeginning(&head, 20);
    head = insertAtBeginning(&head, 30);
    printf("After inserting at beginning: ");
    traverseList(head);
    
    // 3. Insert at end
    head = insertAtEnd(&head, 40);
    head = insertAtEnd(&head, 50);
    printf("After inserting at end: ");
    traverseList(head);
    
    // 4. Insert at position
    head = insertAtPosition(&head, 25, 3);
    printf("After inserting 25 at position 3: ");
    traverseList(head);
    
    // 5. Insert after node
    struct Node* node = searchNode(head, 25);
    if (node != NULL) {
        insertAfterNode(node, 35);
    }
    printf("After inserting 35 after 25: ");
    traverseList(head);
    
    // 6. Insert in place
    head = insertInPlace(&head, 20, 22);
    printf("After replacing 20 with 22: ");
    traverseList(head);
    
    // 7. Delete at beginning
    head = deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head);
    
    // 8. Delete at end
    head = deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head);
    
    // 9. Delete at position
    head = deleteAtPosition(&head, 3);
    printf("After deleting at position 3: ");
    traverseList(head);
    
    // 10. Delete node with key
    head = deleteNode(&head, 25);
    printf("After deleting node with key 25: ");
    traverseList(head);
    
    // 11. Search for a node
    struct Node* foundNode = searchNode(head, 10);
    if (foundNode != NULL) {
        printf("Node with key 10 found\n");
    }
    
    // 13. Length of list
    printf("Length of list: %d\n", lengthOfList(head));
    
    // 14. Reverse list
    head = reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head);
    
    // 15. Find middle node
    findMiddleNode(head);
    
    // 16. Detect loop (always true for circular linked list)
    if (detectLoop(head)) {
        printf("Loop detected in the list (as expected for circular list)\n");
    } else {
        printf("No loop detected in the list (unexpected for circular list)\n");
    }
    
    // 17. Remove duplicates (add some duplicates first)
    head = insertAtEnd(&head, 10);
    head = insertAtEnd(&head, 40);
    printf("Before removing duplicates: ");
    traverseList(head);
    head = removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// /* 
//    Singly Circular Linked List Operations:

//    1. **createNode(int data)**: 
//       - Creates a new node with given data, next pointer set to NULL.

//    2. **insert**:
//      - **insertAtBeginning(struct Node** head, int data)**: Inserts a node at the beginning.
//      - **insertAtEnd(struct Node** head, int data)**: Inserts a node at the end.
//      - **insertAtPosition(struct Node** head, int data, int pos)**: Inserts a node at a specific position.
//      - **insertAfterNode(struct Node* prevNode, int data)**: Inserts a node after a given node.
//      - **insertInPlace(struct Node** head, int oldData, int newData)**: Inserts new data in place of old data.

//    3. **delete**:
//      - **deleteAtBeginning(struct Node** head)**: Deletes the node at the beginning.
//      - **deleteAtEnd(struct Node** head)**: Deletes the node at the end.
//      - **deleteAtPosition(struct Node** head, int pos)**: Deletes the node at a specific position.
//      - **deleteNode(struct Node** head, int key)**: Deletes a node with the specified key.

//    4. **searchNode(struct Node* head, int key)**: Searches for a node with a specific key.

//    5. **traverseList(struct Node* head)**: Prints all nodes in the list from head to end.

//    6. **lengthOfList(struct Node* head)**: Returns the number of nodes in the list.

//    7. **reverseList(struct Node** head)**: Reverses the list.

//    8. **findMiddleNode(struct Node* head)**: Finds and prints the middle node.

//    9. **detectLoop(struct Node* head)**: Detects if there is a loop in the list.

//    10. **removeDuplicates(struct Node* head)**: Removes duplicate nodes from the list.
// */

// // Definition of a singly circular linked list node
// struct Node {
//     int data;
//     struct Node* next; // Pointer to the next node
// };

// // 1. **createNode(int data)**: Creates a new node with given data.
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // 2. Insert Operations
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         newNode->next = *head;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->next = *head;
//         *head = newNode;
//     }
// }

// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         newNode->next = *head;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->next = *head;
//     }
// }

// void insertAtPosition(struct Node** head, int data, int pos) {
//     if (pos == 0) {
//         insertAtBeginning(head, data);
//     } else {
//         struct Node* newNode = createNode(data);
//         struct Node* temp = *head;
//         int i = 0;
//         while (i < pos - 1 && temp->next != *head) {
//             temp = temp->next;
//             i++;
//         }
//         if (i == pos - 1) {
//             newNode->next = temp->next;
//             temp->next = newNode;
//         } else {
//             printf("Position out of bounds.\n");
//             free(newNode);
//         }
//     }
// }

// void insertAfterNode(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("Previous node cannot be NULL.\n");
//         return;
//     }
//     struct Node* newNode = createNode(data);
//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
// }

// void insertInPlace(struct Node** head, int oldData, int newData) {
//     struct Node* temp = *head;
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     do {
//         if (temp->data == oldData) {
//             temp->data = newData;
//             return;
//         }
//         temp = temp->next;
//     } while (temp != *head);
//     printf("Data %d not found.\n", oldData);
// }

// // 3. Delete Operations
// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         struct Node* last = *head;
//         while (last->next != *head) {
//             last = last->next;
//         }
//         last->next = (*head)->next;
//         *head = (*head)->next;
//         free(temp);
//     }
// }

// void deleteAtEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         struct Node* prev = NULL;
//         while (temp->next != *head) {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = *head;
//         free(temp);
//     }
// }

// void deleteAtPosition(struct Node** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if (pos == 0) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         struct Node* prev = NULL;
//         int i = 0;
//         while (i < pos && temp->next != *head) {
//             prev = temp;
//             temp = temp->next;
//             i++;
//         }
//         if (i == pos) {
//             prev->next = temp->next;
//             free(temp);
//         } else {
//             printf("Position out of bounds.\n");
//         }
//     }
// }

// void deleteNode(struct Node** head, int key) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = *head;
//     struct Node* prev = NULL;
//     if (temp->data == key && temp->next == *head) {
//         free(temp);
//         *head = NULL;
//         return;
//     }
//     if (temp->data == key) {
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = (*head)->next;
//         free(*head);
//         *head = temp->next;
//         return;
//     }
//     while (temp->next != *head && temp->data != key) {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp->data == key) {
//         prev->next = temp->next;
//         free(temp);
//     } else {
//         printf("Key not found.\n");
//     }
// }

// // 4. Search Node
// int searchNode(struct Node* head, int key) {
//     if (head == NULL) {
//         return 0;
//     }
//     struct Node* temp = head;
//     do {
//         if (temp->data == key) {
//             return 1;
//         }
//         temp = temp->next;
//     } while (temp != head);
//     return 0;
// }

// // 5. Traverse List
// void traverseList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = head;
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(back to head)\n");
// }

// // 6. Length of List
// int lengthOfList(struct Node* head) {
//     if (head == NULL) {
//         return 0;
//     }
//     int length = 0;
//     struct Node* temp = head;
//     do {
//         length++;
//         temp = temp->next;
//     } while (temp != head);
//     return length;
// }

// // 7. Reverse List
// void reverseList(struct Node** head) {
//     if (*head == NULL) {
//         return;
//     }
//     struct Node *prev = NULL, *curr = *head, *next = NULL;
//     struct Node* last = *head;
//     while (last->next != *head) {
//         last = last->next;
//     }
//     do {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     } while (curr != *head);
//     (*head)->next = prev;
//     last->next = prev;
//     *head = prev;
// }

// // 8. Find Middle Node
// void findMiddleNode(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* slow = head;
//     struct Node* fast = head;
//     while (fast->next != head && fast->next->next != head) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     printf("Middle node: %d\n", slow->data);
// }

// // 9. Detect Loop (Always present in a circular list, hence returns true)
// int detectLoop(struct Node* head) {
//     return 1; // Loop is inherent in circular linked lists
// }

// // 10. Remove Duplicates
// void removeDuplicates(struct Node* head) {
//     if (head == NULL) {
//         return;
//     }
//     struct Node* curr = head;
//     do {
//         struct Node* temp = curr;
//         while (temp->next != head) {
//             if (temp->next->data == curr->data) {
//                 struct Node* dup = temp->next;
//                 temp->next = temp->next->next;
//                 free(dup);
//             } else {
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     } while (curr->next != head);
// }

// // Main function to test the linked list operations
// int main() {
//     struct Node* head = NULL;

//     insertAtBeginning(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 30);
//     insertAtEnd(&head, 40);
//     insertAtBeginning(&head, 50);
    
//     printf("List: ");
//     traverseList(head);

//     findMiddleNode(head);
    
//     deleteAtPosition(&head, 2);
//     printf("After deletion at position 2: ");
//     traverseList(head);

//     return 0;
// }

=====================================================================
8. DOUBLY LL (LINEAR)

#include <stdio.h>
#include <stdlib.h>

/* 
   Doubly Linked List Operations:

   1. **createNode(int data)**: 
      - Creates a new node with given data, next and prev pointers set to NULL.

   2. **insert**:
     - **insertAtBeginning(struct Node** head, int data)**: Inserts a node at the beginning.
     - **insertAtEnd(struct Node** head, int data)**: Inserts a node at the end.
     - **insertAtPosition(struct Node** head, int data, int pos)**: Inserts a node at a specific position.
     - **insertAfterNode(struct Node* prevNode, int data)**: Inserts a node after a given node.

   3. **delete**:
     - **deleteAtBeginning(struct Node** head)**: Deletes the node at the beginning.
     - **deleteAtEnd(struct Node** head)**: Deletes the node at the end.
     - **deleteAtPosition(struct Node** head, int pos)**: Deletes the node at a specific position.
     - **deleteNode(struct Node** head, int key)**: Deletes a node with the specified key.

   4. **searchNode(struct Node* head, int key)**: Searches for a node with a specific key.

   5. **traverseList(struct Node* head)**: Prints all nodes in the list from head to end.

   6. **lengthOfList(struct Node* head)**: Returns the number of nodes in the list.

   7. **reverseList(struct Node** head)**: Reverses the list.

   8. **findMiddleNode(struct Node* head)**: Finds and prints the middle node.

   9. **detectLoop(struct Node* head)**: Detects if there is a loop in the list.

   10. **removeDuplicates(struct Node* head)**: Removes duplicate nodes from the list.
*/

// Definition of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// 1. **createNode**: Creates a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else {
        printf("Memory allocation failed\n");
    }
    return newNode;
}

// 2. **insertAtBeginning**: Inserts a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        printf("Failed to insert at beginning\n");
    }
}

// 2. **insertAtEnd**: Inserts a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (*head == NULL) {
            newNode->prev = NULL;
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    } else {
        printf("Failed to insert at end\n");
    }
}

// 2. **insertAtPosition**: Inserts a node at a specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (pos == 0) {
            insertAtBeginning(head, data);
        } else {
            struct Node* temp = *head;
            for (int i = 1; i < pos && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp != NULL) {
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev != NULL) {
                    temp->prev->next = newNode;
                }
                temp->prev = newNode;
            } else {
                printf("Position out of bounds\n");
            }
        }
    } else {
        printf("Failed to insert at position\n");
    }
}

// 2. **insertAfterNode**: Inserts a node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
    } else {
        struct Node* newNode = createNode(data);
        if (newNode != NULL) {
            newNode->next = prevNode->next;
            newNode->prev = prevNode;
            prevNode->next = newNode;
            if (newNode->next != NULL) {
                newNode->next->prev = newNode;
            }
        } else {
            printf("Failed to insert after node\n");
        }
    }
}

// 3. **deleteAtBeginning**: Deletes the node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

// 3. **deleteAtEnd**: Deletes the node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// 3. **deleteAtPosition**: Deletes the node at a specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if (pos == 0) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        } else {
            printf("Position out of bounds\n");
        }
    }
}

// 3. **deleteNode**: Deletes a node with the specified key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if ((*head)->data == key) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp != NULL) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        } else {
            printf("Key %d not found in the list\n", key);
        }
    }
}

// 4. **searchNode**: Searches for a node with a specific key
void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    int found = 0; // Flag to check if the node is found
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        printf("Node with key %d found\n", key);
    } else {
        printf("Node with key %d not found\n", key);
    }
}

// 5. **traverseList**: Prints all nodes in the list from head to end
void traverseList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 6. **lengthOfList**: Returns the number of nodes in the list
void lengthOfList(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Length of the list: %d\n", count);
}

// 7. **reverseList**: Reverses the list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    if (current == NULL) {
        printf("List is empty, cannot reverse\n");
    } else {
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // Move to the next node
        }
        if (temp != NULL) {
            *head = temp->prev; // Update head
        }
    }
}

// 8. **findMiddleNode**: Finds and prints the middle node
void findMiddleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    if (head == NULL) {
        printf("List is empty, no middle node\n");
    } else {
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("Middle node: %d\n", slow->data);
    }
}

// 9. **detectLoop**: Detects if there is a loop in the list
void detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    int loopExists = 0; // Flag to check if loop exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = 1;
            break;
        }
    }
    if (loopExists) {
        printf("Loop detected in the list\n");
    } else {
        printf("No loop detected in the list\n");
    }
}

// 10. **removeDuplicates**: Removes duplicate nodes from the list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty, cannot remove duplicates\n");
    } else {
        while (current->next != NULL) {
            if (current->data == current->next->data) {
                struct Node* nextNode = current->next->next;
                free(current->next);
                current->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->prev = current;
                }
            } else {
                current = current->next;
            }
        }
    }
}

// Main function to demonstrate the doubly linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    // Print list
    printf("Initial List: ");
    traverseList(head); // Expected: 10 <-> 20 <-> 20 <-> 30 <-> NULL

    // Insert at beginning
    insertAtBeginning(&head, 5);
    printf("After inserting at beginning: ");
    traverseList(head); // Expected: 5 <-> 10 <-> 20 <-> 20 <-> 30 <-> NULL

    // Insert at position
    insertAtPosition(&head, 15, 3);
    printf("After inserting 15 at position 2: ");
    traverseList(head); // Expected: 5 <-> 10 <-> 15 <-> 20 <-> 20 <-> 30 <-> NULL

    // Insert after a node
    insertAfterNode(head->next, 12); // Insert after node with data 10
    printf("After inserting 12 after 10: ");
    traverseList(head); // Expected: 5 <-> 10 <-> 12 <-> 15 <-> 20 <-> 20 <-> 30 <-> NULL

    // Delete at beginning
    deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head); // Expected: 10 <-> 12 <-> 15 <-> 20 <-> 20 <-> 30 <-> NULL

    // Delete at end
    deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head); // Expected: 10 <-> 12 <-> 15 <-> 20 <-> NULL

    // Delete at position
    deleteAtPosition(&head, 1);
    printf("After deleting at position 1: ");
    traverseList(head); // Expected: 10 <-> 15 <-> 20 <-> NULL

    // Delete node
    deleteNode(&head, 15);
    printf("After deleting node with key 15: ");
    traverseList(head); // Expected: 10 <-> 20 <-> NULL

    // Search for a node
    searchNode(head, 10); // Expected: Node with key 10 found
    searchNode(head, 15); // Expected: Node with key 15 not found

    // Get length of list
    lengthOfList(head); // Expected: Length of the list: 2

    // Reverse the list
    reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head); // Expected: 20 <-> 10 <-> NULL

    // Find middle node
    findMiddleNode(head); // Expected: Middle node: 20

    // Detect loop
    detectLoop(head); // Expected: No loop detected in the list

    // Remove duplicates
    insertAtEnd(&head, 20); // Adding duplicate for testing
    insertAtEnd(&head, 20);
    printf("List before removing duplicates: ");
    traverseList(head); // Expected: 20 <-> 10 <-> 20 <-> 20 <-> NULL
    removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head); // Expected: 20 <-> 10 <-> NULL

    return 0;
}

=====================================================================
9. DOUBLE LL (CIRCULAR)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 1. Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// 2.a Function to insert at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
    // CASE 1: Empty list
    if (*head == NULL) {
        *head = createNode(data);
    }
    // CASE 2: Non-empty list
    else {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
    return *head;
}

// 2.b Function to insert at the end
struct Node* insertAtEnd(struct Node** head, int data) {
    // CASE 1: Empty list
    if (*head == NULL) {
        *head = createNode(data);
    }
    // CASE 2: Non-empty list
    else {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    return *head;
}

// 2.c Function to insert at a specific position
struct Node* insertAtPosition(struct Node** head, int data, int position) {
    // CASE 1: Invalid position
    if (position < 1) {
        printf("Invalid position\n");
        return *head;
    }
    // CASE 2: Insert at beginning
    else if (position == 1) {
        return insertAtBeginning(head, data);
    }
    // CASE 3: Insert at specific position
    else {
        struct Node* newNode = createNode(data);
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return *head;
}

// 2.d Function to insert after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    // CASE 1: Invalid previous node
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    // CASE 2: Insert after the given node
    else {
        struct Node* newNode = createNode(data);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }
}

// 3.a Function to delete at the beginning
struct Node* deleteAtBeginning(struct Node** head) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Only one node
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    // CASE 3: More than one node
    else {
        struct Node* temp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        free(temp);
    }
    return *head;
}

// 3.b Function to delete at the end
struct Node* deleteAtEnd(struct Node** head) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Only one node
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    // CASE 3: More than one node
    else {
        struct Node* lastNode = (*head)->prev;
        lastNode->prev->next = *head;
        (*head)->prev = lastNode->prev;
        free(lastNode);
    }
    return *head;
}

// 3.c Function to delete at a specific position
struct Node* deleteAtPosition(struct Node** head, int position) {
    // CASE 1: Invalid position or empty list
    if (*head == NULL || position < 1) {
        printf("Invalid operation\n");
        return *head;
    }
    // CASE 2: Delete first node
    else if (position == 1) {
        return deleteAtBeginning(head);
    }
    // CASE 3: Delete at specific position
    else {
        struct Node* temp = *head;
        for (int i = 1; i < position && temp->next != *head; i++) {
            temp = temp->next;
        }
        if (temp == *head) {
            printf("Position out of range\n");
            return *head;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return *head;
}

// 3.d Function to delete a node with a specific key
struct Node* deleteNode(struct Node** head, int key) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Key is in the first node
    else if ((*head)->data == key) {
        return deleteAtBeginning(head);
    }
    // CASE 3: Key is in other nodes
    else {
        struct Node* temp = (*head)->next;
        while (temp != *head && temp->data != key) {
            temp = temp->next;
        }
        if (temp == *head) {
            printf("Key not found\n");
            return *head;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return *head;
}

// 4. Function to search for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Search for the key
    else {
        struct Node* temp = head;
        do {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Key not found\n");
        return NULL;
    }
}

// 5.a Function to traverse and print the list forward
void traversalList_forward(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Print the list
    else {
        struct Node* temp = head;
        printf("Forward Traversal: ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to start)\n");
    }
}

// 5.b Function to traverse and print the list backward
void traversalList_backward(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Print the list
    else {
        struct Node* temp = head->prev;
        printf("Backward Traversal: ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        } while (temp != head->prev);
        printf("(back to start)\n");
    }
}

// 6. Function to find the length of the list
int lengthOfList(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        return 0;
    }
    // CASE 2: Count the nodes
    else {
        int count = 0;
        struct Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
}

// 7. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: Empty list or only one node
    if (*head == NULL || (*head)->next == *head) {
        return *head;
    }
    // CASE 2: Reverse the list
    else {
        struct Node* current = *head;
        struct Node* temp;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != *head);
        *head = (*head)->next;
        return *head;
    }
}

// 8. Function to find the middle node
void findMiddleNode(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Find the middle node
    else {
        struct Node* slow = head;
        struct Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("Middle node: %d\n", slow->data);
    }
}

// 9. Function to detect a loop
int detectLoop(struct Node* head) {
    // Note: In a circular doubly linked list, there's always a loop
    return (head != NULL);
}

// 10. Function to remove duplicates
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: Empty list or only one node
    if (head == NULL || head->next == head) {
        return head;
    }
    // CASE 2: Remove duplicates
    else {
        struct Node* current = head;
        do {
            struct Node* runner = current->next;
            while (runner != head) {
                if (runner->data == current->data) {
                    struct Node* temp = runner;
                    runner->prev->next = runner->next;
                    runner->next->prev = runner->prev;
                    runner = runner->next;
                    free(temp);
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        } while (current != head);
        return head;
    }
}

// 11. Function to swap two nodes
void swapNodes(struct Node** head, int x, int y) {
    // CASE 1: x and y are same
    if (x == y) return;

    // CASE 2: Search for x and y
    struct Node *prevX = NULL, *currX = *head;
    while (currX->data != x) {
        prevX = currX;
        currX = currX->next;
        if (currX == *head) {
            printf("x not found in the list\n");
            return;
        }
    }

    struct Node *prevY = NULL, *currY = *head;
    while (currY->data != y) {
        prevY = currY;
        currY = currY->next;
        if (currY == *head) {
            printf("y not found in the list\n");
            return;
        }
    }

    // CASE 3: If either x or y is head
    if (currX == *head) *head = currY;
    else if (currY == *head) *head = currX;

    // CASE 4: Swap the nodes
    struct Node* temp;
    temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    temp = currX->prev;
    currX->prev = currY->prev;
    currY->prev = temp;

    if (currX->next != currY) currX->next->prev = currX;
    if (currX->prev != currY) currX->prev->next = currX;
    if (currY->next != currX) currY->next->prev = currY;
    if (currY->prev != currX) currY->prev->next = currY;

    if (prevX != NULL && prevX != currY) prevX->next = currY;
    if (prevY != NULL && prevY != currX) prevY->next = currX;
}

int main() {
    struct Node* head = NULL;

    // Test insertions
    head = insertAtBeginning(&head, 1);
    head = insertAtEnd(&head, 3);
    head = insertAtPosition(&head, 2, 2);
    insertAfterNode(head->next, 4);

    printf("After insertions:\n");
    traversalList_forward(head);
    traversalList_backward(head);

    // Test deletions
    head = deleteAtBeginning(&head);
    head = deleteAtEnd(&head);
    head = deleteAtPosition(&head, 2);
    head = deleteNode(&head, 2);

    printf("After deletions:\n");
    traversalList_forward(head);

    // Test search
    struct Node* found = searchNode(head, 4);
    if (found) printf("Node with data 4 found\n");

    // Test length
    printf("Length of list: %d\n", lengthOfList(head));

    // Test reverse
    head = reverseList(&head);
    printf("After reversal:\n");
    traversalList_forward(head);

    // Test middle node
    findMiddleNode(head);

    // Test loop detection
    printf("Loop detected: %s\n", detectLoop(head) ? "Yes" : "No");

    // Test remove duplicates
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 4);
    printf("Before removing duplicates:\n");
    traversalList_forward(head);
    head = removeDuplicates(head);
    printf("After removing duplicates:\n");
    traversalList_forward(head);

    // Test swap nodes
    head = insertAtEnd(&head, 5);
    head = insertAtEnd(&head, 6);
    printf("Before swapping nodes:\n");
    traversalList_forward(head);
    swapNodes(&head, 4, 6);
    printf("After swapping nodes 4 and 6:\n");
    traversalList_forward(head);

    return 0;
}
=====================================================================
10. LL FUNCTION (sort, reverse, removeDuplicate, rotateClockwise, concatTwoLL, SplitInHalf, SplitInEvenOdd)

1>>>>>>>>>
// 1. Singly Linked List (Non-Circular)
void bubbleSortSingly(struct Node* head) {
    if (!head || !head->next) return;
    for (struct Node* i = head; i->next; i = i->next)
        for (struct Node* j = head; j->next; j = j->next)
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
}

// 2. Singly Linked List (Circular)
void bubbleSortSinglyCircular(struct Node* head) {
    if (!head || head->next == head) return;
    struct Node* end = head;
    do {
        for (struct Node* i = head; i->next != head && i->next != end; i = i->next)
            if (i->data > i->next->data) {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        end = end->next;
    } while (end != head);
}

// 3. Doubly Linked List (Non-Circular)
void bubbleSortDoubly(struct DNode* head) {
    if (!head || !head->next) return;
    for (struct DNode* i = head; i->next; i = i->next)
        for (struct DNode* j = head; j->next; j = j->next)
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
}

// 4. Doubly Linked List (Circular)
void bubbleSortDoublyCircular(struct DNode* head) {
    if (!head || head->next == head) return;
    struct DNode* end = head->prev;
    do {
        for (struct DNode* i = head; i != end; i = i->next)
            if (i->data > i->next->data) {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        end = end->prev;
    } while (end != head->prev);
}

2>>>>>>>>>>>>
// 1. Singly Linked List (Non-Circular)
struct Node* reverseSingly(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. Singly Linked List (Circular)
struct Node* reverseSinglyCircular(struct Node* head) {
    if (!head) return NULL;
    struct Node *prev = NULL, *curr = head, *next;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);
    head->next = prev;
    return prev;
}

// 3. Doubly Linked List (Non-Circular)
struct DNode* reverseDoubly(struct DNode* head) {
    struct DNode *temp, *curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        head = curr;
        curr = curr->prev;
    }
    return head;
}

// 4. Doubly Linked List (Circular)
struct DNode* reverseDoublyCircular(struct DNode* head) {
    if (!head) return NULL;
    struct DNode *curr = head, *temp;
    do {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    } while (curr != head);
    return head->prev;
}

3>>>>>>>>>
// 1. Singly Linked List (Non-Circular)
void removeDuplicatesSingly(struct Node* head) {
    struct Node *curr, *runner, *temp;
    for (curr = head; curr && curr->next; curr = curr->next) {
        for (runner = curr; runner->next;) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
    }
}

// 2. Singly Linked List (Circular)
void removeDuplicatesSinglyCircular(struct Node** head) {
    if (!*head) return;
    struct Node *curr = *head, *runner, *temp;
    do {
        runner = curr;
        while (runner->next != *head) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                if (temp == *head) *head = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    } while (curr != *head);
}

// 3. Doubly Linked List (Non-Circular)
void removeDuplicatesDoubly(struct DNode* head) {
    struct DNode *curr, *runner, *temp;
    for (curr = head; curr && curr->next; curr = curr->next) {
        for (runner = curr; runner->next;) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                if (temp->next) temp->next->prev = runner;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
    }
}

// 4. Doubly Linked List (Circular)
void removeDuplicatesDoublyCircular(struct DNode** head) {
    if (!*head) return;
    struct DNode *curr = *head, *runner, *temp;
    do {
        runner = curr;
        while (runner->next != *head) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                temp->next->prev = runner;
                if (temp == *head) *head = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    } while (curr != *head);
}

4>>>>>>>>>
Rotate clockwise by k

// 1. Singly Linked List (Non-Circular)
struct Node* rotateSingly(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct Node *curr = head, *new_head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    curr->next = head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    new_head = curr->next;
    curr->next = NULL;
    return new_head;
}

// 2. Singly Linked List (Circular)
struct Node* rotateSinglyCircular(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct Node *curr = head;
    int len = 1;
    while (curr->next != head) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    head = curr->next;
    return head;
}

// 3. Doubly Linked List (Non-Circular)
struct DNode* rotateDoubly(struct DNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct DNode *curr = head, *new_head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    new_head = head;
    for (int i = 0; i < len - k; i++) {
        new_head = new_head->next;
    }
    curr->next = head;
    head->prev = curr;
    head = new_head;
    head->prev->next = NULL;
    head->prev = NULL;
    return head;
}

// 4. Doubly Linked List (Circular)
struct DNode* rotateDoublyCircular(struct DNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct DNode *curr = head;
    int len = 1;
    while (curr->next != head) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    head = curr->next;
    return head;
}

5>>>>>>>
Concat

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked lists
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

// Node structure for doubly linked lists
typedef struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

// 1. Singly Linked List (non-circular)
void concat_singly_linked_lists(SinglyNode** list1, SinglyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else {
        SinglyNode* current = *list1;
        while (current->next) {
            current = current->next;
        }
        current->next = *list2;
    }
    *list2 = NULL;  // The second list is now empty
}

// 2. Singly Linked List (circular)
void concat_circular_singly_linked_lists(SinglyNode** list1, SinglyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        SinglyNode* last1 = *list1;
        while (last1->next != *list1) {
            last1 = last1->next;
        }
        SinglyNode* last2 = *list2;
        while (last2->next != *list2) {
            last2 = last2->next;
        }
        last1->next = *list2;
        last2->next = *list1;
    }
    *list2 = NULL;  // The second list is now empty
}

// 3. Doubly Linked List (non-circular)
void concat_doubly_linked_lists(DoublyNode** list1, DoublyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        DoublyNode* last1 = *list1;
        while (last1->next) {
            last1 = last1->next;
        }
        last1->next = *list2;
        (*list2)->prev = last1;
    }
    *list2 = NULL;  // The second list is now empty
}

// 4. Doubly Linked List (circular)
void concat_circular_doubly_linked_lists(DoublyNode** list1, DoublyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        DoublyNode* last1 = (*list1)->prev;
        DoublyNode* last2 = (*list2)->prev;

        last1->next = *list2;
        (*list2)->prev = last1;
        last2->next = *list1;
        (*list1)->prev = last2;
    }
    *list2 = NULL;  // The second list is now empty
}

// Helper function to create a new singly linked node
SinglyNode* create_singly_node(int data) {
    SinglyNode* new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to create a new doubly linked node
DoublyNode* create_doubly_node(int data) {
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Main function to demonstrate usage
int main() {
    // Example usage would go here
    // For brevity, actual list creation and concatenation calls are omitted
    printf("Linked list concatenation functions with double pointers implemented.\n");
    return 0;
}

6>.>>>
Split in Half

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked lists
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

// Node structure for doubly linked lists
typedef struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

// 1. Split in half for Singly Linked List (non-circular)
void split_singly(SinglyNode** head, SinglyNode** second) {
    if (!*head || !(*head)->next) {
        *second = NULL;
        return;
    }
    SinglyNode *slow = *head, *fast = (*head)->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = NULL;
}

// 2. Split in half for Singly Linked List (circular)
void split_singly_circular(SinglyNode** head, SinglyNode** second) {
    if (!*head) return;
    SinglyNode *slow = *head, *fast = *head;
    while (fast->next != *head && fast->next->next != *head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = *head;
    SinglyNode* temp = *second;
    while (temp->next != *head) temp = temp->next;
    temp->next = *second;
}

// 3. Split in half for Doubly Linked List (non-circular)
void split_doubly(DoublyNode** head, DoublyNode** second) {
    if (!*head || !(*head)->next) {
        *second = NULL;
        return;
    }
    DoublyNode *slow = *head, *fast = (*head)->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = NULL;
    if (*second) (*second)->prev = NULL;
}

// 4. Split in half for Doubly Linked List (circular)
void split_doubly_circular(DoublyNode** head, DoublyNode** second) {
    if (!*head) return;
    DoublyNode *slow = *head, *fast = *head;
    while (fast->next != *head && fast->next->next != *head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = *head;
    (*head)->prev = slow;
    (*second)->prev = fast->next == *head ? fast : fast->next;
    (*second)->prev->next = *second;
}

// Helper function to create a singly linked node
SinglyNode* create_singly_node(int data) {
    SinglyNode* node = (SinglyNode*)malloc(sizeof(SinglyNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Helper function to create a doubly linked node
DoublyNode* create_doubly_node(int data) {
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

// Main function (for demonstration)
int main() {
    // Example usage would go here
    printf("Split-in-half functions for all four types of linked lists implemented.\n");
    return 0;
}


7>>>>>>>>>
Split in Even Odd

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked lists
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

// Node structure for doubly linked lists
typedef struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

// 1. Split even-odd for Singly Linked List (non-circular)
void split_even_odd_singly(SinglyNode* head, SinglyNode** even, SinglyNode** odd) {
    *even = *odd = NULL;
    SinglyNode *e_tail = NULL, *o_tail = NULL;
    int index = 0;
    while (head) {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = head;
            else e_tail = e_tail->next = head;
        } else {
            if (!*odd) *odd = o_tail = head;
            else o_tail = o_tail->next = head;
        }
        head = head->next;
        index++;
    }
    if (e_tail) e_tail->next = NULL;
    if (o_tail) o_tail->next = NULL;
}

// 2. Split even-odd for Singly Linked List (circular)
void split_even_odd_singly_circular(SinglyNode* head, SinglyNode** even, SinglyNode** odd) {
    if (!head) {
        *even = *odd = NULL;
        return;
    }
    *even = *odd = NULL;
    SinglyNode *e_tail = NULL, *o_tail = NULL;
    SinglyNode* curr = head;
    int index = 0;
    do {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = curr;
            else e_tail = e_tail->next = curr;
        } else {
            if (!*odd) *odd = o_tail = curr;
            else o_tail = o_tail->next = curr;
        }
        curr = curr->next;
        index++;
    } while (curr != head);
    if (e_tail) e_tail->next = *even;
    if (o_tail) o_tail->next = *odd;
}

// 3. Split even-odd for Doubly Linked List (non-circular)
void split_even_odd_doubly(DoublyNode* head, DoublyNode** even, DoublyNode** odd) {
    *even = *odd = NULL;
    DoublyNode *e_tail = NULL, *o_tail = NULL;
    int index = 0;
    while (head) {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = head;
            else {
                e_tail->next = head;
                head->prev = e_tail;
                e_tail = head;
            }
        } else {
            if (!*odd) *odd = o_tail = head;
            else {
                o_tail->next = head;
                head->prev = o_tail;
                o_tail = head;
            }
        }
        head = head->next;
        index++;
    }
    if (e_tail) e_tail->next = NULL;
    if (o_tail) o_tail->next = NULL;
    if (*even) (*even)->prev = NULL;
    if (*odd) (*odd)->prev = NULL;
}

// 4. Split even-odd for Doubly Linked List (circular)
void split_even_odd_doubly_circular(DoublyNode* head, DoublyNode** even, DoublyNode** odd) {
    if (!head) {
        *even = *odd = NULL;
        return;
    }
    *even = *odd = NULL;
    DoublyNode *e_tail = NULL, *o_tail = NULL;
    DoublyNode* curr = head;
    int index = 0;
    do {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = curr;
            else {
                e_tail->next = curr;
                curr->prev = e_tail;
                e_tail = curr;
            }
        } else {
            if (!*odd) *odd = o_tail = curr;
            else {
                o_tail->next = curr;
                curr->prev = o_tail;
                o_tail = curr;
            }
        }
        curr = curr->next;
        index++;
    } while (curr != head);
    if (*even) {
        e_tail->next = *even;
        (*even)->prev = e_tail;
    }
    if (*odd) {
        o_tail->next = *odd;
        (*odd)->prev = o_tail;
    }
}

// Helper function to create a singly linked node
SinglyNode* create_singly_node(int data) {
    SinglyNode* node = (SinglyNode*)malloc(sizeof(SinglyNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Helper function to create a doubly linked node
DoublyNode* create_doubly_node(int data) {
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

// Main function (for demonstration)
int main() {
    // Example usage would go here
    printf("Split even-odd functions for all four types of linked lists implemented.\n");
    return 0;
}

=====================================================================
11. BFS DFS (1. Traversal , 2. isBipartite, 3.longest conc path, 4.connected compontents , 5. shortest cycle , 6. hasCycle, 7. shortest path)

1>>>>
#include <stdio.h>

#define MAX 100

// BFS function for a single component
void bfs(int graph[MAX][MAX], int visited[], int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// DFS function for a single component
void dfs(int graph[MAX][MAX], int visited[], int start, int v) {
    visited[start] = 1;
    printf("%d ", start);

    for(int j = 0; j < v; j++) {
        if(graph[start][j] == 1 && !visited[j]) {
            dfs(graph, visited, j, v);
        }
    }
}

int main() {
    int vertices, edges;
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int visited[MAX] = {0};     // Visited array for both BFS and DFS

    // Input number of vertices and edges
    scanf("%d %d", &vertices, &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;  // For undirected graph
    }

    // DFS traversal for all components
    printf("DFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, vertices);
            printf("\n");
        }
    }

    // Reset visited for BFS
    for (int i = 0; i < vertices; i++) visited[i] = 0;


    // BFS traversal for all components
    /* if you start from any particular vertex
    int start;
    scanf("%d",&start);
    bfs(graph,visited,start,v);
    */

    // disconnected graph
    printf("BFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            bfs(graph, visited, i, vertices);
            printf("\n");
        }
    }

    return 0;
}

/*
input : 

6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0

*/

2>>>>>>>
#include <stdio.h>

#define MAX 6

// Function to check if the graph is bipartite using BFS
int isBipartiteBFS(int graph[MAX][MAX], int v, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, which means "uncolored"
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;

    // Process nodes in the queue
    while (front < rear) {
        int u = queue[front++];

        // Check for a self-loop
        if (graph[u][u] == 1) return 0;

        // Explore all adjacent vertices
        for (int adj = 0; adj < v; adj++) {
            if (graph[u][adj] == 1) {  // There is an edge
                if (color[adj] == -1) {  // If the adjacent vertex is not colored
                    color[adj] = 1 - color[u];  // Assign opposite color
                    queue[rear++] = adj;
                } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
                    return 0;  // Graph is not bipartite
                }
            }
        }
    }
    return 1;  // Graph is bipartite
}

// Helper function for DFS
int dfsCheck(int graph[MAX][MAX], int color[], int u, int v) {
    // Explore all adjacent vertices
    for (int adj = 0; adj < v; adj++) {
        if (graph[u][adj] == 1) {  // There is an edge
            if (color[adj] == -1) {  // If the adjacent vertex is not colored
                color[adj] = 1 - color[u];  // Assign opposite color
                if (!dfsCheck(graph, color, adj, v)) {
                    return 0;  // Graph is not bipartite
                }
            } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
                return 0;  // Graph is not bipartite
            }
        }
    }
    return 1;  // Continue checking
}

// Function to check if the graph is bipartite using DFS
int isBipartiteDFS(int graph[MAX][MAX], int v, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, meaning "uncolored"
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    return dfsCheck(graph, color, start, v);
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    // Check if the graph is bipartite using BFS
    if (isBipartiteBFS(graph, v, start)) {
        printf("Yes, the given graph is Bipartite (BFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (BFS check)\n");
    }

    // Check if the graph is bipartite using DFS
    if (isBipartiteDFS(graph, v, start)) {
        printf("Yes, the given graph is Bipartite (DFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (DFS check)\n");
    }

    return 0;
}

3>>>>>>>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the matrix
#define QUEUE_SIZE (MAX * MAX)  // Maximum size for the BFS queue

// Directions arrays for the 8 possible moves (up, down, left, right, and diagonals)
int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// (-1, -1): Up-Left diagonal
// (-1,  0): Up
// (-1,  1): Up-Right diagonal
// ( 0, -1): Left
// ( 0,  1): Right
// ( 1, -1): Down-Left diagonal
// ( 1,  0): Down
// ( 1,  1): Down-Right diagonal


// Utility function to check if the given coordinates are within matrix bounds
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Depth-First Search function to find the longest consecutive path from a given character
int findLongestPathDFS(char mat[MAX][MAX], int x, int y, char start, int n, int m) {
    int maxLen = 1;  // At least the start character itself

    // Explore all 8 possible directions
    for (int i = 0; i < 8; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];

        // Check if we can move to this new cell and it's the next consecutive character
        if (isValid(newX, newY, n, m) && mat[newX][newY] == start + 1) {
            int pathLen = 1 + findLongestPathDFS(mat, newX, newY, start + 1, n, m);
            if (pathLen > maxLen) {
                maxLen = pathLen;  // Update maximum length found
            }
        }
    }

    return maxLen;  // Return the longest path length found from this position
}

// Function to find the longest path using DFS starting from a given character
int longestPathDFS(char mat[MAX][MAX], int n, int m, char start) {
    int longest = 0;  // Initialize the longest path length

    // Traverse the matrix to find occurrences of the starting character
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == start) {
                // Start DFS from this cell
                int pathLen = findLongestPathDFS(mat, i, j, start, n, m);
                if (pathLen > longest) {
                    longest = pathLen;  // Update the longest path found
                }
            }
        }
    }

    return longest;  // Return the longest path found
}

// Function to find the longest path using BFS starting from a given character
int longestPathBFS(char mat[MAX][MAX], int n, int m, char start) {
    int longest = 0;  // Initialize the longest path length

    // Arrays for BFS
    int queueX[QUEUE_SIZE];  // Queue for x-coordinates
    int queueY[QUEUE_SIZE];  // Queue for y-coordinates
    int queueLength[QUEUE_SIZE];  // Queue for path lengths
    int front, rear;  // Queue pointers

    // Perform BFS for each occurrence of the starting character
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == start) {
                // Initialize the queue
                front = 0;
                rear = 0;

                // Enqueue the starting position
                queueX[rear] = i;  // Row index
                queueY[rear] = j;  // Column index
                queueLength[rear++] = 1;  // Starting length is 1

                // Perform BFS
                while (front < rear) {
                    int currentX = queueX[front];  // Dequeue the front x-coordinate
                    int currentY = queueY[front];  // Dequeue the front y-coordinate
                    int currentLength = queueLength[front++];  // Dequeue the path length

                    // Explore all 8 possible directions
                    for (int d = 0; d < 8; d++) {
                        int newX = currentX + rowDir[d];
                        int newY = currentY + colDir[d];

                        // Check if we can move to this new cell and it's the next consecutive character
                        if (isValid(newX, newY, n, m) && mat[newX][newY] == start + currentLength) {
                            queueX[rear] = newX;  // Enqueue new position x-coordinate
                            queueY[rear] = newY;  // Enqueue new position y-coordinate
                            queueLength[rear++] = currentLength + 1;  // Enqueue new path length

                            // Update the longest length found
                            if (currentLength + 1 > longest) {
                                longest = currentLength + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return longest;  // Return the longest path found
}

int main() {
    int n, m;
    printf("Enter the dimensions of the matrix (rows and columns): ");
    scanf("%d %d", &n, &m);

    // Ensure that the matrix size does not exceed MAX
    if (n > MAX || m > MAX) {
        printf("Matrix dimensions exceed the maximum allowed size of %d x %d.\n", MAX, MAX);
        return 1;  // Exit if dimensions are invalid
    }

    char mat[MAX][MAX];  // Declare the character matrix
    printf("Enter the character matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);  // Read characters into the matrix
        }
    }

    char startChar;
    printf("Enter the starting character: ");
    scanf(" %c", &startChar);

    // Finding the longest path using DFS
    int resultDFS = longestPathDFS(mat, n, m, startChar);
    printf("DFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultDFS);

    // Finding the longest path using BFS
    int resultBFS = longestPathBFS(mat, n, m, startChar);
    printf("BFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultBFS);

    return 0;  // Exit the program successfully
}

/*
Sample test cases :
Input 1 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
c
Output 1 :
The length of the longest path with consecutive characters starting from character c is 6
Input 2 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
b
Output 2 :
The length of the longest path with consecutive characters starting from character b is 7
*/

4>>>>>
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10 // Maximum number of vertices

// Function to perform DFS and find connected components
void dfs(int graph[MAX_V][MAX_V], int visited[], int v, int start) {
    visited[start] = 1;           // Mark the current node as visited
    printf("%d ", start);         // Print the current node

    // Explore all vertices connected to the current node
    for (int i = 0; i < v; i++) {
        if (graph[start][i] == 1 && !visited[i]) { // Check for an edge and if not visited
            dfs(graph, visited, v, i);           // Recursive DFS call
        }
    }
}

// Function to perform BFS and find connected components
void bfs(int graph[MAX_V][MAX_V], int visited[], int v, int startNode) {
    int queue[MAX_V], front = 0, rear = 0;
    visited[startNode] = 1;      // Mark the start node as visited
    queue[rear++] = startNode;   // Enqueue the start node

    while (front < rear) {       // Continue until queue is empty
        int node = queue[front++]; // Dequeue a node
        printf("%d ", node);     // Print the node

        // Explore all vertices connected to the current node
        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = 1;                      // Mark as visited
                queue[rear++] = i;                   // Enqueue the connected node
            }
        }
    }
}

// Function to find and print all connected components using DFS and BFS
void findConnectedComponents(int graph[MAX_V][MAX_V], int v) {
    int visited[MAX_V] = {0}; // Array to keep track of visited vertices

    printf("Connected components using DFS:\n");
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {      // If the vertex is not visited
            dfs(graph, visited, v, i); // Start DFS from this vertex
            printf("\n");       // New line after each component
        }
    }

    // Reset visited array for BFS
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    printf("Connected components using BFS:\n");
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {      // If the vertex is not visited
            bfs(graph, visited, v, i); // Start BFS from this vertex
            printf("\n");       // New line after each component
        }
    }
}

int main() {
    int v; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int graph[MAX_V][MAX_V] = {0}; // Adjacency matrix initialized to 0

    // Input edges until -1 -1 is encountered
    printf("Enter edges (u v), -1 -1 to end:\n");
    while (1) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u == -1 && w == -1) {
            break; // Terminate input on -1 -1
        }
        graph[u][w] = 1; // Add edge to the graph
        graph[w][u] = 1; // Since it's undirected, add both directions
    }

    findConnectedComponents(graph, v); // Find and print connected components

    return 0;
}

/*
Sample test cases :
Input 1 :
5
1 0
2 1
3 4
-1 -1
Output 1 :
Following are connected components:
0 1 2 
3 4 
Input 2 :
7
0 1
1 2
2 0
3 4
4 5
5 6
-1 -1
Output 2 :
Following are connected components:
0 1 2 
3 4 5 6 
 */




5>>>>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 5       // Maximum number of vertices
#define INF INT_MAX // Infinite value to represent no connection

// Helper function for Dijkstra's approach: Finds the vertex with minimum distance
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to find the shortest cycle using the Bellman-Ford approach
int findShortestCycleBellmanFord(int graph[MAX][MAX], int V) {
    int shortestCycle = INF;

    // Attempt each vertex as a starting point
    for (int start = 0; start < V; start++) {
        int dist[MAX];

        // Initialize distances to INF
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }

        // Check for cycles returning to the start vertex
        for (int u = 0; u < V; u++) {
            if (graph[u][start] != INF && dist[u] != INF) {
                int cycleLength = dist[u] + graph[u][start];
                if (cycleLength < shortestCycle) {
                    shortestCycle = cycleLength;
                }
            }
        }
    }

    return shortestCycle == INF ? -1 : shortestCycle;
}

// Function to find the shortest cycle using Dijkstra's approach
int findShortestCycleDijkstra(int graph[MAX][MAX], int V) {
    int shortestCycle = INF;

    // Run Dijkstra’s algorithm from each vertex as the starting point
    for (int start = 0; start < V; start++) {
        int dist[MAX];
        bool visited[MAX] = { false };

        // Initialize distances to INF
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;

        // Dijkstra’s algorithm for shortest path
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited, V);
            visited[u] = true;

            // Update distances to adjacent vertices
            for (int v = 0; v < V; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        // Check for cycles returning to the start vertex
        for (int v = 0; v < V; v++) {
            if (graph[v][start] != INF && dist[v] != INF) {
                int cycleLength = dist[v] + graph[v][start];
                if (cycleLength < shortestCycle) {
                    shortestCycle = cycleLength;
                }
            }
        }
    }

    return shortestCycle == INF ? -1 : shortestCycle;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int graph[MAX][MAX];

    // Initialize the graph with INF to represent no edge
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }

    // Input edges and their weights
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }

    // Find and print the shortest cycle using both approaches
    int resultBellmanFord = findShortestCycleBellmanFord(graph, V);
    int resultDijkstra = findShortestCycleDijkstra(graph, V);

    // Print results
    printf("Shortest cycle length using Bellman-Ford: %d\n", resultBellmanFord == -1 ? -1 : resultBellmanFord);
    printf("Shortest cycle length using Dijkstra: %d\n", resultDijkstra == -1 ? -1 : resultDijkstra);

    return 0;
}



6>>>>>.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// Function to check for cycle using DFS
bool hasCycleDFS(int graph[MAX][MAX], bool visited[], int V, int curr, int parent) {
    visited[curr] = true;
    
    for (int i = 0; i < V; i++) {
        if (graph[curr][i]) { // If there is an edge
            if (!visited[i]) { // If not visited, recursively visit it
                if (hasCycleDFS(graph, visited, V, i, curr))
                    return true;
            } else if (i != parent) { // If visited and not parent, cycle exists
                return true;
            }
        }
    }
    return false;
}

// Function to check for cycle using BFS
bool hasCycleBFS(int graph[MAX][MAX], int V) {
    bool visited[MAX] = {false};
    int parent[MAX] = {-1};

    for (int start = 0; start < V; start++) {
        if (!visited[start]) { // Start BFS from each unvisited vertex
            visited[start] = true;
            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;

            while (front != rear) {
                int curr = queue[front++];
                
                for (int i = 0; i < V; i++) {
                    if (graph[curr][i]) { // If there is an edge
                        if (!visited[i]) { // If not visited, enqueue it
                            visited[i] = true;
                            parent[i] = curr;
                            queue[rear++] = i;
                        } else if (i != parent[curr]) { // If visited and not parent, cycle exists
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    int graph[MAX][MAX] = {0};

    // Input edges
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        // Add edge to adjacency matrix (undirected)
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    // Initialize visited array for DFS
    bool visited[MAX] = {false};
    bool cycleFoundDFS = false;

    // Check for cycle using DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(graph, visited, V, i, -1)) {
                cycleFoundDFS = true;
                break;
            }
        }
    }

    // Check for cycle using BFS
    bool cycleFoundBFS = hasCycleBFS(graph, V);

    // Print results
    printf("Cycle Detected using DFS: %d\n", cycleFoundDFS ? 1 : 0);
    printf("Cycle Detected using BFS: %d\n", cycleFoundBFS ? 1 : 0);

    return 0;
}

/*
Sample test cases :
Input 1 :
5
5
1 0
0 2
2 1
0 3
3 4
Output 1 :
1
Input 2 :
3
2
0 1
1 2
Output 2 :
0
 */

7>>>>>.
#include <stdio.h>
#include <stdbool.h>
#define MAX_V 7  // Maximum number of vertices

// Function to find the shortest path using BFS
void findPathBFS(int graph[MAX_V][MAX_V], int n, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V], queue[MAX_V];
    int front = 0, rear = 0;
    
    // Initialize BFS starting point
    visited[start] = true;
    parent[start] = -1;
    queue[rear++] = start;
    
    // BFS traversal
    while (front < rear) {
        int curr = queue[front++];
        
        if (curr == end) {  // Path found
            // Trace back the path from end to start using parent array
            int path[MAX_V], len = 0;
            for (int v = end; v != -1; v = parent[v]) path[len++] = v;
            
            // Print the path length and path vertices
            printf("Shortest path length (BFS): %d\n", len - 1);
            printf("Path (BFS): ");
            while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
            return;
        }
        
        // Explore adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                queue[rear++] = i;
            }
        }
    }
    printf("Not found\n");  // Path not found
}

// Recursive DFS helper function to find the shortest path
bool findPathDFSUtil(int graph[MAX_V][MAX_V], bool visited[], int parent[], int n, int curr, int end) {
    if (curr == end) return true;  // If destination is reached

    visited[curr] = true;  // Mark current as visited
    
    // Explore adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[curr][i] && !visited[i]) {
            parent[i] = curr;  // Set parent for path tracking
            if (findPathDFSUtil(graph, visited, parent, n, i, end))
                return true;  // Path found
        }
    }
    return false;  // No path found
}

// Function to find the shortest path using DFS
void findPathDFS(int graph[MAX_V][MAX_V], int n, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V];
    parent[start] = -1;  // Start has no parent

    // Check if a path exists using DFS
    if (findPathDFSUtil(graph, visited, parent, n, start, end)) {
        int path[MAX_V], len = 0;
        for (int v = end; v != -1; v = parent[v]) path[len++] = v;

        printf("Path length (DFS): %d\n", len - 1);
        printf("Path (DFS): ");
        while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
    } else {
        printf("Not found\n");  // Path not found
    }
}

int main() {
    int n, src, goal;
    scanf("%d", &n);  // Number of vertices
    
    if (n < 2 || n > MAX_V) { 
        printf("Not found\n"); 
        return 0; 
    }
    
    int graph[MAX_V][MAX_V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);  // Read adjacency matrix

    scanf("%d %d", &src, &goal);  // Read source and goal vertices
    if (src < 0 || src >= n || goal < 0 || goal >= n) { 
        printf("Not found\n"); 
        return 0; 
    }
    
    // Find path using BFS
    printf("Using BFS:\n");
    findPathBFS(graph, n, src, goal);

    // Find path using DFS
    printf("Using DFS:\n");
    findPathDFS(graph, n, src, goal);

    return 0;
}


=====================================================================
12. DIJKSTRA

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// Function to find the unvisited vertex with the minimum distance
int findMin(int dist[], bool visited[], int v) {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < v; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

// Dijkstra's algorithm to find shortest path from source to destination
void dijkstra(int graph[MAX][MAX], int v, int src, int dest) {
    int dist[MAX], prev[MAX];
    bool visited[MAX] = { false };
    
    // Initialize distances and previous vertices
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;
    
    // Dijkstra's algorithm main loop
    for (int count = 0; count < v - 1; count++) {
        int x = findMin(dist, visited, v);
        visited[x] = true;
        
        for (int y = 0; y < v; y++) {
            if (graph[x][y] && !visited[y] && dist[x] != INT_MAX && dist[x] + graph[x][y] < dist[y]) {
                dist[y] = dist[x] + graph[x][y];
                prev[y] = x;
            }
        }
    }
    
    // Check if destination is reachable
    if (dist[dest] == INT_MAX) {
        printf("No path found\n");
    } else {
        // Backtrack to find path from destination to source
        int path[MAX], pathLen = 0;
        for (int idx = dest; idx != -1; idx = prev[idx]) {
            path[pathLen++] = idx;
        }
        
        // Print shortest path
        printf("Shortest path: %d", src);
        for (int i = pathLen - 2; i >= 0; i--) {
            printf(" -> %d", path[i]);
        }
        printf("\nShortest distance: %d\n", dist[dest]);
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e); // Number of vertices and edges
    
    int graph[MAX][MAX] = {0}; // Initialize graph with 0s
    
    // Input edges
    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a][b] = w;
        graph[b][a] = w;
    }
    
    int src, dest;
    scanf("%d %d", &src, &dest); // Input source and destination
    dijkstra(graph, v, src, dest);
    
    return 0;
}

/*
Input 1 :
4
5
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
0
3
Output 1 :
Shortest path: 0 -> 1 -> 2 -> 3
Shortest distance: 6
*/


=====================================================================
13. MST
1>>>> KRUSKAL
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices in the graph
#define INF 999999 // Representation of no edge between vertices

// Structure to represent an edge with a source, destination, and weight
struct Edge {
    int src, dest, weight;
};

// Structure to represent subsets for union-find
// Each subset has a parent (for find operation) and rank (for union by rank)
struct Subset {
    int parent, rank;
};

// Function to find the root of a subset (with path compression to optimize performance)
int find(struct Subset subsets[], int i) {
    // If i is not the root, find its parent recursively
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Function to union two subsets by rank
// Attach the tree with the smaller rank to the tree with the larger rank
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x); // Find root of subset x
    int yroot = find(subsets, y); // Find root of subset y
    
    // Attach smaller rank tree under root of the higher rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        // If ranks are equal, make one root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function for qsort to sort edges by their weights in ascending order
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm for finding the MST
void kruskal(int graph[MAX][MAX], int V) {
    struct Edge edges[MAX * MAX]; // Array to hold all edges of the graph
    int edgeCount = 0; // Counter to keep track of the number of edges
    
    // Convert adjacency matrix into an edge list
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) { // Check if edge exists
                edges[edgeCount++] = (struct Edge){i, j, graph[i][j]}; // Store edge in list
            }
        }
    }

    // Sort edges by their weights in ascending order
    qsort(edges, edgeCount, sizeof(edges[0]), compareEdges);

    // Create subsets for each vertex (for union-find)
    struct Subset subsets[MAX];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i; // Initially, each vertex is its own parent
        subsets[i].rank = 0; // Initial rank is 0
    }

    // Array to store edges included in the MST
    struct Edge result[MAX];
    int e = 0; // Counter for number of edges in the MST

    // Process each edge in sorted order
    for (int i = 0; i < edgeCount && e < V - 1; i++) {
        struct Edge nextEdge = edges[i]; // Get the next edge with minimum weight

        // Find the root of the subsets of both vertices of the edge
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, add it to the MST
        if (x != y) {
            result[e++] = nextEdge; // Include edge in MST
            Union(subsets, x, y); // Union the subsets
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix
    // Use INF (999999) to represent no edge between vertices
    printf("Enter the adjacency matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Execute Kruskal's algorithm to find the MST
    kruskal(graph, V);

    return 0;
}

/*
input 

Enter the number of vertices and edges: 4 5
Enter each edge (source, destination, weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4


output

Edge     Weight
2 - 3    4
0 - 3    5
0 - 1    10

*/

2>>> PRIMS
#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices
#define INF 999999  // Representation of no edge between vertices

// Function to find the vertex with the minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V) {
    int min = INF, minIndex;

    // Iterate over all vertices to find the minimum key value
    for (int v = 0; v < V; v++) {
        // Update min if key[v] is smaller and v is not in the MST yet
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;  // Return index of vertex with minimum key value
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        // Print each edge and its weight
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];  // Array to store the MST (parent array)
    int key[MAX];     // Key values used to pick the minimum weight edge
    bool mstSet[MAX]; // Boolean array to represent set of vertices included in MST

    // Initialize key values as INF and mstSet as false for all vertices
    for (int i = 0; i < V; i++) {
        key[i] = INF;  // Set initial key value to infinity
        mstSet[i] = false;  // Mark all vertices as not included in MST
    }

    key[0] = 0;      // Make key of the first vertex as 0 so that it is picked first
    parent[0] = -1;  // First vertex is always the root of the MST

    // The MST will have exactly V-1 edges, so we iterate V-1 times
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick vertex u with the smallest key value not in MST
        mstSet[u] = true; // Include vertex u in MST

        // Update the key and parent for the adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update key[v] only if graph[u][v] is non-zero (edge exists),
            // v is not yet included in MST, and the new key is smaller
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;  // Set u as parent of v in MST
                key[v] = graph[u][v];  // Update key with weight of the edge u-v
            }
        }
    }

    // Print the MST using the parent array
    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[MAX][MAX];

    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix, using INF (999999) to indicate no edge
    printf("Enter the adjacency matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Prim's algorithm to find the MST
    primMST(graph, V);

    return 0;
}

/**
input

Enter the number of vertices: 4
Enter the adjacency matrix (enter 999999 for no edge):
0 4 0 999999
4 0 8 11
0 8 0 7
999999 11 7 0

output

Edge     Weight
0 - 1    4 
0 - 2    0 
2 - 3    7 



 */
=====================================================================
14. BINARY TREE

/*
List of functions implemented:
1. [BT & BST] createNode
2. [BST] insert
3. [BST] search
4. [BT & BST] inorderTraversal
5. [BT & BST] preorderTraversal
6. [BT & BST] postorderTraversal
7. [BST] findMin
8. [BST] findMax
9. [BST] deleteNode
10. [BT & BST] height


Additional possible operations for binary trees:

### Basic Operations:

11. [BT & BST] levelOrderTraversal        - Traverse the tree level by level (breadth-first)
12. [BT & BST] countNodes                 - Count the total number of nodes in the tree
13. [BT & BST] countLeaves                - Count the number of leaf nodes (nodes without children)
14. [BT & BST] countInternalNodes         - Count the number of internal nodes (nodes with at least one child)
15. [BST] isBST                           - Check if the tree is a valid Binary Search Tree
16. [BST] findPredecessor                 - Find the in-order predecessor of a node
17. [BST] findSuccessor                   - Find the in-order successor of a node
18. [BT & BST] findDepth                  - Find the depth (distance from the root) of a specific node
19. [BT & BST] printPaths                 - Print all root-to-leaf paths
20. [BT & BST] mirrorTree                 - Create a mirror image of the binary tree
21. [BT & BST] checkIdenticalTrees        - Check if two binary trees are identical
22. [BT & BST] printBoundaryNodes         - Print boundary nodes of the tree in a counterclockwise direction

### Intermediate Operations:

23. [BT & BST] findAncestors              - Find and print all ancestors of a given node
24. [BT & BST] lowestCommonAncestor (LCA) - Find the lowest common ancestor of two nodes
25. [BST] findKthSmallest                 - Find the kth smallest element in a BST (inorder traversal)
26. [BST] findKthLargest                  - Find the kth largest element in a BST (reverse inorder traversal)
27. [BT & BST] checkBalancedTree          - Check if the tree is balanced (height difference between left and right is <= 1)
28. [BT & BST] isSymmetric                - Check if the tree is symmetric (mirror image of itself)
29. [BT & BST] findDiameter               - Find the diameter (longest path between any two nodes) of the tree
30. [BT & BST] pruneTree                  - Remove subtrees with a sum less than a given value
31. [BT & BST] checkCompleteTree          - Check if the tree is a complete binary tree
32. [BT & BST] flattenTree                - Flatten the tree to a linked list (inorder traversal)
33. [BT & BST] zigzagTraversal            - Traverse the tree in a zigzag (spiral) order
34. [BT & BST] verticalOrderTraversal     - Traverse the tree vertically (column by column)

### Advanced Operations:

35. [BT & BST] convertToDoublyLinkedList  - Convert the binary tree to a doubly linked list
36. [BT & BST] serializeTree              - Serialize the binary tree to a string
37. [BT & BST] deserializeTree            - Deserialize the string back into a binary tree
38. [BT & BST] checkFullBinaryTree        - Check if the tree is a full binary tree (each node has 0 or 2 children)
39. [BT & BST] checkPerfectBinaryTree     - Check if the tree is a perfect binary tree (all internal nodes have 2 children, leaves at the same level)
40. [BT & BST] convertToSumTree           - Convert the tree into a sum tree (each node contains the sum of its children)
41. [BT & BST] buildTreeFromTraversals    - Reconstruct a tree from given inorder and preorder/postorder traversals
42. [BT & BST] checkSubtree               - Check if a tree is a subtree of another binary tree
43. [BT & BST] findAllPathsRootToLeaf     - Find and print all paths from the root to the leaf nodes
*/

/*
Topics list:
1. Node creation
2. Insertion
3. Searching
4. Tree traversals (Inorder, Preorder, Postorder)
5. Finding minimum and maximum values
6. Node deletion
7. Tree height calculation
*/



#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insert(struct Node* root, int value);
struct Node* search(struct Node* root, int value);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* findMin(struct Node* root);
struct Node* findMax(struct Node* root);
struct Node* deleteNode(struct Node* root, int value);
int height(struct Node* root);

// 1. createNode: Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. insert: Insert a new node into the binary search tree
struct Node* insert(struct Node* root, int value) {
    // Case 1: If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }
    
    // Case 2: If the value is less than the root, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Case 3: If the value is greater than or equal to the root, insert in the right subtree
    else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 3. search: Search for a value in the binary search tree
struct Node* search(struct Node* root, int value) {
    // Case 1: Root is NULL or the value is found at the root
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Case 2: Value is less than the root, search in the left subtree
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // Case 3: Value is greater than the root, search in the right subtree
    return search(root->right, value);
}

// 4. inorderTraversal: Perform inorder traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 5. preorderTraversal: Perform preorder traversal of the binary tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 6. postorderTraversal: Perform postorder traversal of the binary tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// 7. findMin: Find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return NULL;
    }
    
    // Case 2: Leftmost node (minimum)
    if (root->left == NULL) {
        return root;
    }
    
    // Case 3: Recurse to the left
    return findMin(root->left);
}

// 8. findMax: Find the maximum value in the binary search tree
struct Node* findMax(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return NULL;
    }
    
    // Case 2: Rightmost node (maximum)
    if (root->right == NULL) {
        return root;
    }
    
    // Case 3: Recurse to the right
    return findMax(root->right);
}

// 9. deleteNode: Delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    // Case 1: Empty tree
    if (root == NULL) {
        return root;
    }
    
    // Case 2: Value to be deleted is in the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // Case 3: Value to be deleted is in the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // Case 4: Value to be deleted is found
    else {
        // Case 4a: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 4b: Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 10. height: Calculate the height of the binary tree
int height(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return -1;
    }
    
    // Case 2: Leaf node
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    
    // Case 3: Internal node
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


int main() {
    struct Node* root = NULL;
    
    // 2. Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    /* Expected tree after insertions:
           50
         /    \
        30    70
       / \    / \
      20 40  60 80
    */

    // 4. Inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    /* Expected output: 20 30 40 50 60 70 80 */

    // 5. Preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    /* Expected output: 50 30 20 40 70 60 80 */

    // 6. Postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    /* Expected output: 20 40 30 60 80 70 50 */

    // 3. Search
    struct Node* searchResult = search(root, 40);
    printf("Search for 40: %s\n", searchResult ? "Found" : "Not found");
    /* Expected output: Search for 40: Found */

    // 7. Find minimum
    struct Node* minNode = findMin(root);
    printf("Minimum value: %d\n", minNode->data);
    /* Expected output: Minimum value: 20 */

    // 8. Find maximum
    struct Node* maxNode = findMax(root);
    printf("Maximum value: %d\n", maxNode->data);
    /* Expected output: Maximum value: 80 */

    // 10. Height of the tree
    printf("Height of the tree: %d\n", height(root));
    /* Expected output: Height of the tree: 2 */

    // 9. Delete node
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");
    /* Expected output: 20 40 50 60 70 80 */

    /* Expected tree after deletion of 30:
           50
         /    \
        40    70
       /     / \
      20    60 80
    */


    // Free the allocated memory
    freeTree(root);
    return 0;
}

/*
Complete Topics List:
1. Binary Tree Node Structure
2. Basic Operations:
   11. Level Order Traversal - Traverse tree level by level showing each level
   12. Count Total Nodes - Get total number of nodes
   13. Count Leaf Nodes - Count nodes without children
   14. Count Internal Nodes - Count nodes with at least one child
   15. Check if BST - Validate Binary Search Tree
   16. Find Predecessor - Get in-order predecessor
   17. Find Successor - Get in-order successor
   18. Find Depth - Get distance from root to specific node
   19. Print All Paths - Show all root-to-leaf paths
   20. Mirror Tree - Create mirror image of tree
   21. Check Identical Trees - Compare two trees
   22. Print Boundary Nodes - Print boundary in counterclockwise
3. Helper Functions for various operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// All function declarations
void levelOrderTraversal(struct Node* root);
int countNodes(struct Node* root);
int countLeaves(struct Node* root);
int countInternalNodes(struct Node* root);
bool isBST(struct Node* root);
struct Node* findPredecessor(struct Node* root, struct Node* node);
struct Node* findSuccessor(struct Node* root, struct Node* node);
int findDepth(struct Node* root, int target);
void printPaths(struct Node* root);
void mirrorTree(struct Node* root);
bool checkIdenticalTrees(struct Node* root1, struct Node* root2);
void printBoundaryNodes(struct Node* root);

// Helper function declarations
int height(struct Node* node);
void printCurrentLevel(struct Node* root, int level);
void printPathsRecursive(struct Node* root, int path[], int pathLen);
bool isBSTUtil(struct Node* root, int min, int max);
void printLeftBoundary(struct Node* root);
void printLeaves(struct Node* root);
void printRightBoundary(struct Node* root);
struct Node* findMin(struct Node* node);
struct Node* findMax(struct Node* node);

// Helper function for 11. levelOrderTraversal
int height(struct Node* node) {
    // Case 1: Empty tree
    if (node == NULL) {
        return 0;
    }
    // Case 2: Compute height
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

// Helper function for 11. levelOrderTraversal
void printCurrentLevel(struct Node* root, int level) {
    // Case 1: Empty tree
    if (root == NULL) {
        return;
    }
    // Case 2: Current level
    else if (level == 1) {
        printf("%d ", root->data);
    }
    // Case 3: Other levels
    else {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// 11. Level Order Traversal - Traverse the tree level by level
void levelOrderTraversal(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return;
    }
    // Case 2: Non-empty tree
    else {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printf("Level %d: ", i);
            printCurrentLevel(root, i);
            printf("\n");
        }
    }
}

// 12. Count Total Nodes
int countNodes(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return 0;
    
    // Case 2: Count current node and recursively count children
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 13. Count Leaf Nodes
int countLeaves(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return 0;
    
    // Case 2: Leaf node
    if (root->left == NULL && root->right == NULL) return 1;
    
    // Case 3: Internal node
    return countLeaves(root->left) + countLeaves(root->right);
}

// 14. Count Internal Nodes
int countInternalNodes(struct Node* root) {
    // Case 1: Empty tree or leaf node
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    // Case 2: Internal node
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// 15. Check if BST
bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper for 15: isBST
bool isBSTUtil(struct Node* root, int min, int max) {
    // Case 1: Empty tree is BST
    if (root == NULL) return true;
    
    // Case 2: Node value out of valid range
    if (root->data < min || root->data > max) return false;
    
    // Case 3: Check recursively for left and right subtrees
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

// 16. Find Predecessor
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    // Case 1: Empty tree or node
    if (root == NULL || node == NULL) return NULL;
    
    // Case 2: Left subtree exists, find max in left subtree
    if (node->left != NULL) {
        return findMax(node->left);
    }
    
    // Case 3: No left subtree, find ancestor where node is in right subtree
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (node->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return predecessor;
}

// 17. Find Successor
struct Node* findSuccessor(struct Node* root, struct Node* node) {
    // Case 1: Empty tree or node
    if (root == NULL || node == NULL) return NULL;
    
    // Case 2: Right subtree exists, find min in right subtree
    if (node->right != NULL) {
        return findMin(node->right);
    }
    
    // Case 3: No right subtree, find ancestor where node is in left subtree
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data) {
            root = root->right;
        }
        else break;
    }
    return successor;
}

// 18. Find Depth
int findDepth(struct Node* root, int target) {
    // Case 1: Empty tree
    if (root == NULL) return -1;
    
    // Case 2: Node found
    if (root->data == target) return 0;
    
    // Case 3: Search in left and right subtrees
    int leftDepth = findDepth(root->left, target);
    if (leftDepth >= 0) return leftDepth + 1;
    
    int rightDepth = findDepth(root->right, target);
    if (rightDepth >= 0) return rightDepth + 1;
    
    return -1;
}

// 19. Print All Paths
void printPaths(struct Node* root) {
    int path[1000];
    printPathsRecursive(root, path, 0);
}

// Helper for 19: Print Paths Recursive
void printPathsRecursive(struct Node* root, int path[], int pathLen) {
    // Case 1: Empty node
    if (root == NULL) return;
    
    // Case 2: Add current node to path
    path[pathLen] = root->data;
    pathLen++;
    
    // Case 3: Leaf node - print path
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    
    // Case 4: Recurse for left and right subtrees
    printPathsRecursive(root->left, path, pathLen);
    printPathsRecursive(root->right, path, pathLen);
}

// 20. Mirror Tree
void mirrorTree(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return;
    
    // Case 2: Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Case 3: Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// 21. Check Identical Trees
bool checkIdenticalTrees(struct Node* root1, struct Node* root2) {
    // Case 1: Both empty
    if (root1 == NULL && root2 == NULL) return true;
    
    // Case 2: One empty, one not
    if (root1 == NULL || root2 == NULL) return false;
    
    // Case 3: Compare current nodes and recursively compare subtrees
    return (root1->data == root2->data &&
            checkIdenticalTrees(root1->left, root2->left) &&
            checkIdenticalTrees(root1->right, root2->right));
}

// 22. Print Boundary Nodes
void printBoundaryNodes(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    
    // Case 1: Print left boundary
    printLeftBoundary(root->left);
    
    // Case 2: Print leaves
    printLeaves(root->left);
    printLeaves(root->right);
    
    // Case 3: Print right boundary
    printRightBoundary(root->right);
}

// Helper functions for 22: Print Boundary Nodes
void printLeftBoundary(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    printf("%d ", root->data);
    if (root->left != NULL)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

void printLeaves(struct Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printRightBoundary(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    if (root->right != NULL)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);
    printf("%d ", root->data);
}

// Helper functions for finding predecessor/successor
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}


int main() {
    /* Creating a sample binary tree:
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // 11. Testing Level Order Traversal
    printf("\n11. Level Order Traversal:\n");
    levelOrderTraversal(root);
    /* Expected output:
    Level 1: 1
    Level 2: 2 3
    Level 3: 4 5 6 7
    */
    
    // 12. Testing Count Nodes
    printf("\n12. Total nodes: %d", countNodes(root));
    /* Expected output: 7 */
    
    // 13. Testing Count Leaves
    printf("\n13. Leaf nodes: %d", countLeaves(root));
    /* Expected output: 4 */
    
    // 14. Testing Count Internal Nodes
    printf("\n14. Internal nodes: %d", countInternalNodes(root));
    /* Expected output: 3 */
    
    // 15. Testing isBST
    printf("\n15. Is BST: %s", isBST(root) ? "Yes" : "No");
    /* Expected output: No */
    
    // 18. Testing Find Depth
    printf("\n18. Depth of node 5: %d", findDepth(root, 5));
    /* Expected output: 2 */
    
    // 19. Testing Print Paths
    printf("\n19. All root-to-leaf paths:\n");
    printPaths(root);
    /* Expected output:
    1 2 4
    1 2 5
    1 3 6
    1 3 7
    */
    
    // 20. Testing Mirror Tree
    printf("\n20. Mirror Tree - Level Order before mirroring: ");
    levelOrderTraversal(root);
    mirrorTree(root);
    printf("Level Order after mirroring: ");
    levelOrderTraversal(root);
    /* Expected output before: 1 2 3 4 5 6 7
       Expected output after:  1 3 2 7 6 5 4 */
    
    // 21. Testing Identical Trees
    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    printf("\n21. Trees identical: %s", 
           checkIdenticalTrees(root, root2) ? "Yes" : "No");
    /* Expected output: No */
    
    // 22. Testing Print Boundary Nodes
    printf("\n22. Boundary nodes: ");
    printBoundaryNodes(root);
    /* Expected output depends on current tree state after mirroring */
    
    return 0;
}

/* intermediate_binary_tree_operations.c */

/*
Intermediate Binary Tree Operations Topics List:
1. Binary Tree Node Structure































2. Intermediate Operations:
   23. Find Ancestors - Print all ancestors of a given node
   24. Lowest Common Ancestor - Find LCA of two nodes
   25. Kth Smallest Element - Find using inorder traversal
   26. Kth Largest Element - Find using reverse inorder
   27. Check Balanced Tree - Verify height balance
   28. Check Symmetry - Verify mirror image property
   29. Find Diameter - Longest path between any nodes
   30. Prune Tree - Remove subtrees below sum threshold
   31. Check Complete Tree - Verify complete binary tree
   32. Flatten Tree - Convert to linked list
   33. Zigzag Traversal - Spiral order traversal
   34. Vertical Order Traversal - Column-wise traversal
3. Helper Functions for above operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function declarations
bool findAncestors(struct Node* root, int target);
struct Node* lowestCommonAncestor(struct Node* root, int n1, int n2);
int findKthSmallest(struct Node* root, int k);
int findKthLargest(struct Node* root, int k);
bool isBalanced(struct Node* root);
bool isSymmetric(struct Node* root);
int diameterOfBinaryTree(struct Node* root);
struct Node* pruneTree(struct Node* root, int limit);
bool isCompleteTree(struct Node* root);
void flatten(struct Node* root);
void zigzagLevelOrder(struct Node* root);
void verticalOrder(struct Node* root);

// Helper function declarations
int height(struct Node* node);
bool isSymmetricHelper(struct Node* left, struct Node* right);
int diameterHelper(struct Node* root, int* height);
int pruneTreeHelper(struct Node* root, int limit);
void flattenHelper(struct Node* root, struct Node** prev);
void printCurrentLevel(struct Node* root, int level, bool leftToRight);

// Helper function: max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 23. Find Ancestors - Find and print all ancestors of a given node
bool findAncestors(struct Node* root, int target) {
    if (root == NULL) {
        // Case 1: Empty tree
        return false;
    }
    
    if (root->data == target) {
        // Case 2: Target found
        return true;
    }
    
    if (findAncestors(root->left, target) || findAncestors(root->right, target)) {
        // Case 3: Target found in subtree
        printf("%d ", root->data);
        return true;
    }
    
    // Case 4: Target not found in this path
    return false;
}

// 24. Lowest Common Ancestor - Find the lowest common ancestor of two nodes
struct Node* lowestCommonAncestor(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        // Case 1: Empty tree
        return NULL;
    }
    
    if (root->data == n1 || root->data == n2) {
        // Case 2: Current node is one of the targets
        return root;
    }
    
    struct Node* left = lowestCommonAncestor(root->left, n1, n2);
    struct Node* right = lowestCommonAncestor(root->right, n1, n2);
    
    if (left && right) {
        // Case 3: Targets are in different subtrees
        return root;
    }
    
    // Case 4: Return non-null subtree result
    return (left != NULL) ? left : right;
}

// Helper function for 25: findKthSmallest
void kthSmallestHelper(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;
    
    kthSmallestHelper(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthSmallestHelper(root->right, k, count, result);
}

// 25. Find Kth Smallest - Find the kth smallest element in BST
int findKthSmallest(struct Node* root, int k) {
    int count = 0;
    int result = -1;
    kthSmallestHelper(root, k, &count, &result);
    return result;
}

// Helper function for 26: findKthLargest
void kthLargestHelper(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;
    
    kthLargestHelper(root->right, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthLargestHelper(root->left, k, count, result);
}

// 26. Find Kth Largest - Find the kth largest element in BST
int findKthLargest(struct Node* root, int k) {
    int count = 0;
    int result = -1;
    kthLargestHelper(root, k, &count, &result);
    return result;
}

// Helper function for 27: isBalanced
int height(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

// 27. Check Balanced Tree - Check if height difference <= 1
bool isBalanced(struct Node* root) {
    if (root == NULL) {
        // Case 1: Empty tree
        return true;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        // Case 2: Balanced
        return true;
    }
    
    // Case 3: Unbalanced
    return false;
}

// Helper function for 28: isSymmetric
bool isSymmetricHelper(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) {
        // Case 1: Both subtrees empty
        return true;
    }
    if (left == NULL || right == NULL) {
        // Case 2: One subtree empty, other non-empty
        return false;
    }
    return (left->data == right->data) &&
           isSymmetricHelper(left->left, right->right) &&
           isSymmetricHelper(left->right, right->left);
}

// 28. Check Symmetry - Verify mirror image property
bool isSymmetric(struct Node* root) {
    if (root == NULL) {
        // Case 1: Empty tree
        return true;
    }
    // Case 2: Check symmetry of left and right subtrees
    return isSymmetricHelper(root->left, root->right);
}

// Helper function for 29: diameterOfBinaryTree
int diameterHelper(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    
    int lh = 0, rh = 0;
    int ldiameter = diameterHelper(root->left, &lh);
    int rdiameter = diameterHelper(root->right, &rh);
    
    *height = max(lh, rh) + 1;
    return max(lh + rh, max(ldiameter, rdiameter));
}

// 29. Find Diameter - Longest path between any nodes
int diameterOfBinaryTree(struct Node* root) {
    int height = 0;
    return diameterHelper(root, &height);
}

// Helper function for 30: pruneTree
int pruneTreeHelper(struct Node* root, int limit) {
    if (root == NULL) return 0;
    
    int leftSum = pruneTreeHelper(root->left, limit);
    int rightSum = pruneTreeHelper(root->right, limit);
    
    if (leftSum < limit) root->left = NULL;
    if (rightSum < limit) root->right = NULL;
    
    return root->data + leftSum + rightSum;
}

// 30. Prune Tree - Remove subtrees below sum threshold
struct Node* pruneTree(struct Node* root, int limit) {
    if (root == NULL) {
        // Case 1: Empty tree
        return NULL;
    }
    
    // Case 2: Prune subtrees
    int totalSum = pruneTreeHelper(root, limit);
    
    if (totalSum < limit) {
        // Case 3: Entire tree sum is below limit
        free(root);
        return NULL;
    }
    
    return root;
}

// 31. Check Complete Tree - Verify complete binary tree
bool isCompleteTree(struct Node* root) {
    if (root == NULL) {
        // Case 1: Empty tree
        return true;
    }
    
    // Case 2: BFS to check completeness
    struct Node* queue[1000];
    int front = 0, rear = 0;
    bool flag = false;
    
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node* temp = queue[front++];
        
        if (temp->left) {
            if (flag) return false;
            queue[rear++] = temp->left;
        } else {
            flag = true;
        }
        
        if (temp->right) {
            if (flag) return false;
            queue[rear++] = temp->right;
        } else {
            flag = true;
        }
    }
    
    return true;
}

// Helper function for 32: flatten
void flattenHelper(struct Node* root, struct Node** prev) {
    if (root == NULL) return;
    
    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);
    
    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

// 32. Flatten Tree - Convert to linked list (in-place)
void flatten(struct Node* root) {
    struct Node* prev = NULL;
    flattenHelper(root, &prev);
}

// Helper function for 33: zigzagLevelOrder
void printCurrentLevel(struct Node* root, int level, bool leftToRight) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        if (leftToRight) {
            printCurrentLevel(root->left, level-1, leftToRight);
            printCurrentLevel(root->right, level-1, leftToRight);
        } else {
            printCurrentLevel(root->right, level-1, leftToRight);
            printCurrentLevel(root->left, level-1, leftToRight);
        }
    }
}

// 33. Zigzag Traversal - Spiral order traversal
void zigzagLevelOrder(struct Node* root) {
    if (root == NULL) {
        // Case 1: Empty tree
        return;
    }
    
    int h = height(root);
    bool leftToRight = true;
    
    for (int i = 1; i <= h; i++) {
        // Case 2: Print each level
        printCurrentLevel(root, i, leftToRight);
        printf("\n");
        leftToRight = !leftToRight;
    }
}

// 34. Vertical Order Traversal - Column-wise traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) {
        // Case 1: Empty tree
        return;
    }
    
    // Note: This is a simplified version. A complete implementation would require 
    // a hash map to store nodes at each horizontal distance.
    printf("Note: Full implementation requires additional data structures.\n");
    printf("Simplified vertical order traversal:\n");
    printf("%d ", root->data);
    if (root->left) printf("%d ", root->left->data);
    if (root->right) printf("%d ", root->right->data);
    // ... and so on for other levels
}

int main() {
    /* Creating a sample binary tree:
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // 23. Testing Find Ancestors
    printf("\n23. Ancestors of node 5: ");
    findAncestors(root, 5);
    /* Expected output: 2 1 */
    
    // 24. Testing Lowest Common Ancestor
    struct Node* lca = lowestCommonAncestor(root, 4, 5);
    printf("\n24. LCA of 4 and 5: %d", lca->data);
    /* Expected output: 2 */
    
    // 25. Testing Kth Smallest (Note: This assumes BST property)
    printf("\n25. 3rd smallest element: %d", findKthSmallest(root, 3));
    /* Expected output: 3 (assuming BST property) */
    
    // 26. Testing Kth Largest (Note: This assumes BST property)
    printf("\n26. 2nd largest element: %d", findKthLargest(root, 2));
    /* Expected output: 6 (assuming BST property) */
    
    // 27. Testing Balanced Tree
    printf("\n27. Is balanced? %s", isBalanced(root) ? "Yes" : "No");
    /* Expected output: Yes */
    
    // 28. Testing Symmetric Tree
    printf("\n28. Is symmetric? %s", isSymmetric(root) ? "Yes" : "No");
    /* Expected output: No */
    
    // 29. Testing Diameter
    printf("\n29. Diameter of tree: %d", diameterOfBinaryTree(root));
    /* Expected output: 4 */
    
    // 30. Testing Prune Tree
    printf("\n30. Pruning tree with sum threshold 10...");
    root = pruneTree(root, 10);
    printf("\nPruned tree (preorder traversal): ");
    // Helper function to print preorder traversal
    void preorder(struct Node* node) {
        if (node == NULL) return;
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
    preorder(root);
    /* Expected output: 1 2 4 5 3 6 7 (no change as all subtrees sum > 10) */

    // 31. Testing Complete Tree
    printf("\n31. Is complete tree? %s", isCompleteTree(root) ? "Yes" : "No");
    /* Expected output: Yes */

    // 32. Testing Flatten Tree
    printf("\n32. Flattening tree...");
    flatten(root);
    printf("\nFlattened tree (printing right pointers): ");
    struct Node* current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->right;
    }
    /* Expected output: 1 2 4 5 3 6 7 */

    // Recreating the tree for remaining operations
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 33. Testing Zigzag Traversal
    printf("\n\n33. Zigzag traversal:");
    zigzagLevelOrder(root);
    /* Expected output:
       1
       3 2
       4 5 6 7
    */

    // 34. Testing Vertical Order Traversal
    printf("\n34. Vertical order traversal:\n");
    verticalOrder(root);
    /* Expected output:
       Note: Full implementation requires additional data structures.
       Simplified vertical order traversal:
       1 2 3
    */

    // Free the allocated memory
    // Note: In a real implementation, you should have a function to free the entire tree

    return 0;
}


/*
Advanced Binary Tree Operations:
35. Convert Binary Tree to Doubly Linked List
36. Serialize Binary Tree
37. Deserialize Binary Tree
38. Check Full Binary Tree
39. Check Perfect Binary Tree
40. Convert to Sum Tree
41. Build Tree from Traversals
42. Check Subtree
43. Find All Paths from Root to Leaf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for doubly linked list node
struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function declarations
void convertToDoublyLinkedList(struct Node* root, struct DLLNode** head);
char* serializeTree(struct Node* root);
struct Node* deserializeTree(char* str);
bool checkFullBinaryTree(struct Node* root);
bool checkPerfectBinaryTree(struct Node* root);
void convertToSumTree(struct Node* root);
struct Node* buildTreeFromTraversals(int* inorder, int* preorder, int size);
bool checkSubtree(struct Node* T, struct Node* S);
void findAllPathsRootToLeaf(struct Node* root);

// Helper function declarations
void convertToDLLHelper(struct Node* root, struct DLLNode** head);
void serializeTreeHelper(struct Node* root, char* str, int* index);
struct Node* deserializeTreeHelper(char* str, int* index);
int getHeight(struct Node* root);
int convertToSumTreeHelper(struct Node* root);
struct Node* buildTreeHelper(int* inorder, int* preorder, int inStart, int inEnd, int* preIndex, int size);
int search(int* arr, int start, int end, int value);
void printArray(int path[], int pathLen);
void findPathsHelper(struct Node* root, int path[], int pathLen);
bool identicalTrees(struct Node* a, struct Node* b);
bool isPerfectBinaryTreeHelper(struct Node* root, int level, int* leafLevel);
void printDLL(struct DLLNode* head);
void inorderTraversal(struct Node* root);

// 35. Convert Binary Tree to Doubly Linked List
void convertToDoublyLinkedList(struct Node* root, struct DLLNode** head) {
    /* Case 1: Empty tree */
    if (root == NULL) return;
    
    static struct DLLNode* prev = NULL;
    
    /* Case 2: Process left subtree */
    convertToDoublyLinkedList(root->left, head);
    
    /* Case 3: Process current node */
    struct DLLNode* curr = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    curr->data = root->data;
    curr->next = NULL;
    
    if (prev == NULL) {
        *head = curr;  // First node
        curr->prev = NULL;
    } else {
        curr->prev = prev;
        prev->next = curr;
    }
    prev = curr;
    
    /* Case 4: Process right subtree */
    convertToDoublyLinkedList(root->right, head);
}

// Helper function to print Doubly Linked List
void printDLL(struct DLLNode* head) {
    struct DLLNode* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 36. Serialize Binary Tree
char* serializeTree(struct Node* root) {
    char* str = (char*)malloc(1000 * sizeof(char));
    int index = 0;
    
    /* Case 1: Empty tree */
    if (root == NULL) {
        str[index] = '\0';
        return str;
    }
    
    /* Case 2: Non-empty tree */
    serializeTreeHelper(root, str, &index);
    str[index-1] = '\0';  // Remove last space
    return str;
}

// Helper function for serializeTree
void serializeTreeHelper(struct Node* root, char* str, int* index) {
    /* Case 1: Null node */
    if (root == NULL) {
        *index += sprintf(&str[*index], "N ");
        return;
    }
    
    /* Case 2: Valid node */
    *index += sprintf(&str[*index], "%d ", root->data);
    serializeTreeHelper(root->left, str, index);
    serializeTreeHelper(root->right, str, index);
}

// 37. Deserialize Binary Tree
struct Node* deserializeTree(char* str) {
    int index = 0;
    
    /* Case 1: Empty string */
    if (strlen(str) == 0) return NULL;
    
    /* Case 2: Non-empty string */
    return deserializeTreeHelper(str, &index);
}

// Helper function for deserializeTree
struct Node* deserializeTreeHelper(char* str, int* index) {
    /* Case 1: Null node */
    if (str[*index] == 'N') {
        *index += 2;  // Skip 'N' and space
        return NULL;
    }
    
    /* Case 2: Valid node */
    int num = 0;
    while (str[*index] != ' ' && str[*index] != '\0') {
        num = num * 10 + (str[*index] - '0');
        (*index)++;
    }
    (*index)++;  // Skip space
    
    struct Node* root = createNode(num);
    root->left = deserializeTreeHelper(str, index);
    root->right = deserializeTreeHelper(str, index);
    
    return root;
}

// Helper function for inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 38. Check Full Binary Tree
bool checkFullBinaryTree(struct Node* root) {
    /* Case 1: Empty tree */
    if (root == NULL) return true;
    
    /* Case 2: Leaf node */
    if (root->left == NULL && root->right == NULL) return true;
    
    /* Case 3: Internal node with both children */
    if (root->left && root->right)
        return checkFullBinaryTree(root->left) && checkFullBinaryTree(root->right);
    
    /* Case 4: Node with only one child */
    return false;
}

// 39. Check Perfect Binary Tree
bool checkPerfectBinaryTree(struct Node* root) {
    int leafLevel = -1;
    return isPerfectBinaryTreeHelper(root, 0, &leafLevel);
}

// Helper function for checkPerfectBinaryTree
bool isPerfectBinaryTreeHelper(struct Node* root, int level, int* leafLevel) {
    /* Case 1: Empty tree */
    if (root == NULL) return true;
    
    /* Case 2: Leaf node */
    if (root->left == NULL && root->right == NULL) {
        if (*leafLevel == -1)
            *leafLevel = level;
        return level == *leafLevel;
    }
    
    /* Case 3: Internal node with one child */
    if (root->left == NULL || root->right == NULL)
        return false;
    
    /* Case 4: Internal node with both children */
    return isPerfectBinaryTreeHelper(root->left, level + 1, leafLevel) &&
           isPerfectBinaryTreeHelper(root->right, level + 1, leafLevel);
}

// 40. Convert to Sum Tree
void convertToSumTree(struct Node* root) {
    convertToSumTreeHelper(root);
}

// Helper function for convertToSumTree
int convertToSumTreeHelper(struct Node* root) {
    /* Case 1: Empty node */
    if (root == NULL) return 0;
    
    /* Case 2: Leaf node */
    int oldValue = root->data;
    int leftSum = convertToSumTreeHelper(root->left);
    int rightSum = convertToSumTreeHelper(root->right);
    
    /* Case 3: Update node value */
    root->data = leftSum + rightSum;
    
    return root->data + oldValue;
}

// 41. Build Tree from Traversals
struct Node* buildTreeFromTraversals(int* inorder, int* preorder, int size) {
    int preIndex = 0;
    return buildTreeHelper(inorder, preorder, 0, size - 1, &preIndex, size);
}

// Helper function for buildTreeFromTraversals
struct Node* buildTreeHelper(int* inorder, int* preorder, int inStart, int inEnd, int* preIndex, int size) {
    /* Case 1: Invalid indices */
    if (inStart > inEnd) return NULL;
    
    /* Case 2: Create node */
    struct Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;
    
    /* Case 3: Leaf node */
    if (inStart == inEnd) return node;
    
    /* Case 4: Find partition index and build subtrees */
    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex, size);
    node->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex, size);
    
    return node;
}

// Helper function for buildTreeFromTraversals
int search(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// 42. Check Subtree
bool checkSubtree(struct Node* T, struct Node* S) {
    /* Case 1: Subtree is NULL */
    if (S == NULL) return true;
    
    /* Case 2: Main tree is NULL */
    if (T == NULL) return false;
    
    /* Case 3: Check if trees are identical */
    if (identicalTrees(T, S)) return true;
    
    /* Case 4: Recursively check left and right subtrees */
    return checkSubtree(T->left, S) || checkSubtree(T->right, S);
}

// Helper function for checkSubtree
bool identicalTrees(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    
    return (a->data == b->data) &&
           identicalTrees(a->left, b->left) &&
           identicalTrees(a->right, b->right);
}

// 43. Find All Paths Root to Leaf
void findAllPathsRootToLeaf(struct Node* root) {
    int path[1000];
    findPathsHelper(root, path, 0);
}

// Helper function for findAllPathsRootToLeaf
void findPathsHelper(struct Node* root, int path[], int pathLen) {
    /* Case 1: Empty node */
    if (root == NULL) return;
    
    /* Case 2: Add current node to path */
    path[pathLen] = root->data;
    pathLen++;
    
    /* Case 3: Leaf node - print path */
    if (root->left == NULL && root->right == NULL) {
        printArray(path, pathLen);
    } else {
        /* Case 4: Internal node - recurse */
        findPathsHelper(root->left, path, pathLen);
        findPathsHelper(root->right, path, pathLen);
    }
}

// Helper function for findAllPathsRootToLeaf
void printArray(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Original Tree structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    / \\\n");
    printf("   4   5\n\n");
    
    /* Test 35: Convert to Doubly Linked List
     * Expected Output: 4 2 5 1 3
     * Original Tree:
     *       1
     *      / \
     *     2   3
     *    / \
     *   4   5
     */
    struct DLLNode* head = NULL;
    convertToDoublyLinkedList(root, &head);
    printDLL(head);
    
    /* Test 36: Serialize Tree
     * Expected Output: 1 2 4 N N 5 N N 3 N N
     */
    char* serialized = serializeTree(root);
    printf("Serialized tree: %s\n", serialized);
    
    /* Test 37: Deserialize Tree
     * Expected Output: Inorder traversal: 4 2 5 1 3
     */
    struct Node* deserializedRoot = deserializeTree(serialized);
    printf("Deserialized tree inorder traversal: ");
    inorderTraversal(deserializedRoot);
    printf("\n");
    
    /* Test 38: Check Full Binary Tree
     * Expected Output: false
     */
    bool isFull = checkFullBinaryTree(root);
    printf("Is full binary tree: %s\n", isFull ? "true" : "false");
    
    /* Test 39: Check Perfect Binary Tree
     * Expected Output: false
     */
    bool isPerfect = checkPerfectBinaryTree(root);
    printf("Is perfect binary tree: %s\n", isPerfect ? "true" : "false");
    
    /* Test 40: Convert to Sum Tree
     * Expected Output:
     *       15
     *      /  \
     *     9    0
     *    / \
     *   0   0
     */
    struct Node* sumTreeRoot = createNode(1);
    sumTreeRoot->left = createNode(2);
    sumTreeRoot->right = createNode(3);
    sumTreeRoot->left->left = createNode(4);
    sumTreeRoot->left->right = createNode(5);
    
    convertToSumTree(sumTreeRoot);
    printf("Sum tree inorder traversal: ");
    inorderTraversal(sumTreeRoot);
    printf("\n");
    
    /* Test 41: Build Tree from Traversals
     * Expected Output: Same structure as original tree
     */
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    struct Node* builtTree = buildTreeFromTraversals(inorder, preorder, 5);
    printf("Built tree inorder traversal: ");
    inorderTraversal(builtTree);
    printf("\n");
    
    /* Test 42: Check Subtree
     * Expected Output: true
     * Subtree structure:
     *     2
     *    / \
     *   4   5
     */
    struct Node* subtree = createNode(2);
    subtree->left = createNode(4);
    subtree->right = createNode(5);
    bool isSubtree = checkSubtree(root, subtree);
    printf("Is subtree: %s\n", isSubtree ? "true" : "false");
    
    /* Test 43: Find All Paths Root to Leaf
     * Expected Output:
     * 1 2 4
     * 1 2 5
     * 1 3
     * Tree structure:
     *       1
     *      / \
     *     2   3
     *    / \
     *   4   5
     */
    printf("All paths from root to leaf:\n");
    findAllPathsRootToLeaf(root);
    
    // Free allocated memory
    free(serialized);
    
    // Note: In a real application, you should also free all nodes
    // in the binary trees and the doubly linked list
    
    return 0;
}




=====================================================================