/*
Problem Statement

Tisha wants to learn mathematical expressions and she wants to create a program to accept multiple infix expressions from the user and convert them into postfix expressions using a Stack-based algorithm. 

The program should prompt the user to enter the number of expressions they wish to convert, and then accept each expression one by one. After converting each infix expression to a postfix, the program should print the corresponding postfix expression to the console. 

Input format :
The first line of input consists of an integer N, denoting the number of infix expressions to be converted.

The following N lines of input consist of the infix expressions to be converted.

Output format :
The N lines of output print "Postfix expression T: " where T is the expression number followed by the corresponding postfix expression for N inputs, in separate lines.

Refer to the sample output for the formatting specifications.

Code constraints :
The maximum length of an infix expression is 100 characters.

The program should support multiple infix expressions.

The program should use a stack-based algorithm to convert infix expressions to postfix expressions.

Sample test cases :
Input 1 :
1
A+B*C-D/E^F
Output 1 :
Postfix expression 1: ABC*+DEF^/-
Input 2 :
2
A+B-C
D+E/F-G
Output 2 :
Postfix expression 1: AB+C-
Postfix expression 2: DEF/+G-
Input 3 :
1
a*(b+c)/d-e
Output 3 :
Postfix expression 1: abc+*d/e-
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void push(Stack* s, char c) {
    s->items[++(s->top)] = c;
}

char pop(Stack* s) {
    return s->items[(s->top)--];
}

char peek(Stack* s) {
    return s->items[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1;
    int k = 0;
    
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(c)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }
    
    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }
    
    postfix[k] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char infix[MAX], postfix[MAX];
        scanf("%s", infix);
        infixToPostfix(infix, postfix);
        printf("Postfix expression %d: %s\n", i + 1, postfix);
    }
    
    return 0;
}
