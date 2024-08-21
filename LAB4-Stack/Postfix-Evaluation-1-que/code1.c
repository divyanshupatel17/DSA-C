Problem Statement

Meena is a computer science student who is currently studying data structures and algorithms. As part of her assignment, she has been tasked with implementing a program that evaluates postfix expressions using a Stack data structure.

Write a program to help Meena evaluate a given postfix mathematical expression using Stack.

Example

Input:

1 2 3 + *

Output:

5

Explanation:

exp = 1 2 3 + * 
exp[0]="1" => push() => Stack = 1
exp[1]="2" => push() => Stack = 1 2
exp[2]="3" => push() => Stack = 1 2 3
exp[3]="+" => pop() => Stack = 1 5 (perform addition on first two top-most elements; 3+ 2 = 5)
exp[4]="*" => pop() => Stack = 5 (perform multiplication on first two top-most elements; 1*5 = 5)
Print the last value, 5.

Input format :
The input consists of a postfix mathematical expression.

The expression will contain integers and arithmetic operators (+, -, *, /) separated by space.

Output format :
The output prints the result of evaluating the given postfix expression.



Refer to the sample output for the formatting specifications.

Code constraints :
The expression contains only valid mathematical characters: digits (0 to 9) and arithmetic operators.

Sample test cases :
Input 1 :
1 2 3 + *
Output 1 :
5
Input 2 :
5 2 3 * + 8 4 / - 3 +
Output 2 :
12

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    Stack stack;
    initStack(&stack);
    char* token = strtok(exp, " ");
    while (token != NULL) {
        // If the token is an operand, push it onto the stack
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        }
        // If the token is an operator, pop two operands and apply the operation
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (token[0]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
        token = strtok(NULL, " ");
    }
    // The final result is the only element left in the stack
    return pop(&stack);
}

int main() {
    char exp[MAX_SIZE];
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = 0; // Remove the newline character
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
