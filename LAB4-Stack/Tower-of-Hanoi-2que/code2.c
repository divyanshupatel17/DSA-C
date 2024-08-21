Problem Statement

You are delving into the classical Towers of Hanoi problem, a puzzle that involves transferring a set of numbered disks from one peg to another while adhering to specific rules. To simplify the problem, each disk is represented by integers from 1 to n, where n is the total number of disks. The pegs are labeled A, B, and C.

The goal is to devise an iterative solution, utilizing a stack data structure, to efficiently move all disks from peg A to peg C. The Towers of Hanoi rules must be strictly followed:

Only one disk can be moved at a time.
Each move involves taking the top disk from one peg and placing it on top of another peg.
A larger disk cannot be placed on top of a smaller disk.

Write a program that takes the number of disks (n) as input and prints the sequence of moves required to achieve the desired configuration. Implement stack operations for initialization, push, and pop within the program. The iterative function, towerOfHanoiMovesWithStack, should employ the stack to facilitate disk movements, ensuring compliance with the Towers of Hanoi rules.

For example, if the number of disks is 3, the disks can be transferred as follows: The total number of moves made is 7.

Lightbox

Input format :
The input consists of a single integer, representing the number of disks to be moved.

Output format :
The output consists of a series of lines, each representing a move of a disk from one peg to another. Each line follows the format: "Move disk D from Source to Destination", where D is the disk number and Source and Destination are the pegs (A, B, or C).

After all moves are printed, the output includes a line stating the total number of moves made during the Tower of Hanoi operation, formatted as "Total number of moves: N", where N is the total number of moves.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 8

Sample test cases :
Input 1 :
3
Output 1 :
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total number of moves: 7
Input 2 :
2
Output 2 :
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Total number of moves: 3

#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

// Function to initialize the stack
Stack* initStack() {
    return NULL;
}

// Function to push an element onto the stack
void push(Stack** top, int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(Stack** top) {
    if (*top == NULL) return -1;
    int data = (*top)->data;
    Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(Stack* top) {
    return top == NULL;
}

// Function to print the moves
void printMove(int disk, char from, char to) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

// Iterative function to solve the Tower of Hanoi problem
void towerOfHanoiMovesWithStack(int n) {
    Stack* source = initStack();
    Stack* auxiliary = initStack();
    Stack* destination = initStack();

    // Initialize the source stack with disks
    for (int i = n; i >= 1; i--) {
        push(&source, i);
    }

    int totalMoves = 0;
    while (!isEmpty(source) || !isEmpty(auxiliary)) {
        // Move disk from source to destination
        if (!isEmpty(source) && (isEmpty(destination) || pop(&source) < pop(&destination))) {
            int disk = pop(&source);
            push(&destination, disk);
            printMove(disk, 'A', 'C');
            totalMoves++;
        }
        // Move disk from source to auxiliary
        else if (!isEmpty(source) && (isEmpty(auxiliary) || pop(&source) < pop(&auxiliary))) {
            int disk = pop(&source);
            push(&auxiliary, disk);
            printMove(disk, 'A', 'B');
            totalMoves++;
        }
        // Move disk from auxiliary to destination
        else if (!isEmpty(auxiliary) && (isEmpty(destination) || pop(&auxiliary) < pop(&destination))) {
            int disk = pop(&auxiliary);
            push(&destination, disk);
            printMove(disk, 'B', 'C');
            totalMoves++;
        }
        // Move disk from auxiliary to source
        else if (!isEmpty(auxiliary) && (isEmpty(source) || pop(&auxiliary) < pop(&source))) {
            int disk = pop(&auxiliary);
            push(&source, disk);
            printMove(disk, 'B', 'A');
            totalMoves++;
        }
        // Move disk from destination to auxiliary
        else if (!isEmpty(destination) && (isEmpty(auxiliary) || pop(&destination) < pop(&auxiliary))) {
            int disk = pop(&destination);
            push(&auxiliary, disk);
            printMove(disk, 'C', 'B');
            totalMoves++;
        }
        // Move disk from destination to source
        else if (!isEmpty(destination) && (isEmpty(source) || pop(&destination) < pop(&source))) {
            int disk = pop(&destination);
            push(&source, disk);
            printMove(disk, 'C', 'A');
            totalMoves++;
        }
    }

    printf("Total number of moves: %d\n", totalMoves);
}

int main() {
    int n;
    scanf("%d", &n);
    towerOfHanoiMovesWithStack(n);
    return 0;
}
