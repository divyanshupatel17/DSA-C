
Problem Statement

Jake is working on a program that converts infix expressions to prefix expressions. Help Jake by writing a function that reads an infix expression from the input and outputs its corresponding prefix expression.

Input format :
The input consists of a string, an infix expression that includes only digits(0-9), operators(+, -, *, /), and parenthesis.

Output format :
The output displays the equivalent prefix expression of the given infix expression.

Refer to the sample output for the formatting specifications.

Code constraints :
The expression may contain only valid mathematical characters: digits, arithmetic operators, and parentheses.

The output will not exceed 100 characters.

Sample test cases :
Input 1 :
(2+1)*4
Output 1 :
*+214
Input 2 :
(5/1)*4+2
Output 2 :
+*/5142


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isdigit(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
}

void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void replaceParentheses(char* exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX];
    char postfix[MAX];

    strcpy(reversedInfix, infix);
    reverse(reversedInfix);
    replaceParentheses(reversedInfix);
    infixToPostfix(reversedInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("%s", prefix);

    return 0;
}

