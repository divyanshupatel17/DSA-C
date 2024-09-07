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

