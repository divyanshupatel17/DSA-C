1.
Problem Statement



Akash wants to write a program that populates values in a singly linked list by inserting each element into the front of the list. After insertion, the program should delete a node immediately after a node with a specific value X. 



Assist him with a suitable program.

Input format :
The first line of input consists of an integer N, representing the number of elements.

The second line consists of N space-separated integers, representing the elements of the linked list.

The third line consists of an integer X, representing the value after which the node has to be deleted.

Output format :
The first line of output prints the elements of the original linked list in the format: "Original Linked List: " followed by the linked list elements, separated by " -> " and ending with "NULL".

The second line prints the modified linked list after deleting the node after the value X in the format: "After deleting node after X: " followed by the modified linked list elements, separated by " -> " and ending with "NULL".



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ N ≤ 10

1 ≤ elements of the linked list ≤ 100

X will be a value present in the linked list excluding the first and last elements.

Sample test cases :
Input 1 :
4
15 28 36 43
36
Output 1 :
Original Linked List: 43 -> 36 -> 28 -> 15 -> NULL
After deleting node after 36: 43 -> 36 -> 15 -> NULL
Input 2 :
5
1 2 3 4 5
2
Output 2 :
Original Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
After deleting node after 2: 5 -> 4 -> 3 -> 2 -> NULL

// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void insertFront(struct Node** head_ref,int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteAfter(struct Node* head,int x){
    struct Node* temp = head;
    while(temp!=NULL && temp->data!=x){
        temp = temp->next;
    }
    if(temp!=NULL && temp->next!=NULL){
        struct Node* node_to_dlt = temp->next;
        temp->next = temp->next->next;
        free(node_to_dlt);
    } 
}

void printLL(struct Node* node){
    while(node != NULL){
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    int n , x;
    scanf("%d",&n);
    int ele[n];
    
    for(int i=0 ; i<n ; i++){
        scanf("%d",&ele[i]);
    }
    
    scanf("%d",&x);
    
    // inserting in LL
    for(int i=0 ; i<n ; i++){
        insertFront(&head, ele[i]);
    }
    
    printf("Original Linked List: ");
    printLL(head);
    
    deleteAfter(head,x);
    
    printf("After deleting node after %d: ",x);
    printLL(head);
    
    return 0;
}


2.
Problem Statement



In a computer science course project, students are required to write a program to insert values at the end of a singly linked list and remove the last node from the list. The program should traverse the list and delete the last node, adjusting pointers accordingly. 



Assist students in the task.

Input format :
The first line of input consists of an integer N, representing the list size.

The second line consists of N space-separated integers, representing the list elements.

Output format :
The output prints space-separated integers, representing the list after the deletion of the last element.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

2 ≤ N ≤ 25

1 ≤ list elements ≤ 1000

Sample test cases :
Input 1 :
8
54 25 14 38 55 73 95 82
Output 1 :
54 25 14 38 55 73 95 
Input 2 :
5
15 73 89 96 37
Output 2 :
15 73 89 96 

// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// insertEnd
void insertEnd(Node** head_ref,int new_data){
    struct Node* new_node = (Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

// dltEnd
void dltEnd(Node** head_ref){
    if(*head_ref == NULL){
        return ;
    }
    if((*head_ref)->next == NULL){
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    Node* second_last = *head_ref;
    while(second_last->next->next != NULL){
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}
// Print
void print(Node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    // printf("NULL\n");
}


int main(){
    Node* head = NULL;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i=0 ; i<n ; i++){
        insertEnd(&head,arr[i]);
    }
    dltEnd(&head);
    print(head);
}

3.
Problem Statement



Timothy wants to evaluate polynomial expressions for his mathematics homework. He needs a program that allows him to input the coefficients of a polynomial based on its degree and compute the polynomial s value for a given input of x. Implement a function that takes the degree, coefficients, and the value of x, and returns the evaluated result of the polynomial.



Example



Input:

degree of the polynomial = 2

coefficient of x2 = 13

coefficient of x1 = 12

coefficient of x0 = 11

x = 1

Output:

36



Explanation

Calculate the value of 13x2: 13 * 12 = 13.

Calculate the value of 12x1: 12 * 11 = 12.

Calculate the value of 11x0: 11 * 10 = 11.

Add the values of x2, x1, and x0 together: 13 + 12 + 11 = 36.

Input format :
The first line of input consists of the degree of the polynomial.

The second line consists of the coefficient of x2.

The third line consists of the coefficient of x1.

The fourth line consists of the coefficient of x0.

The fifth line consists of the value of x, at which the polynomial should be evaluated.

Output format :
The output is an integer value obtained by evaluating the polynomial at the given value of x.



Refer to the sample output for formatting specifications.

Code constraints :
degree of the polynomial = 2

1 ≤ x ≤ 5

Sample test cases :
Input 1 :
2
13
12
11
1
Output 1 :
36
Input 2 :
2
15
16
18
3
Output 2 :
201


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node 
{
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node** head, int coefficient, int exponent) 
{
    struct Node* newNode = createNode(coefficient, exponent);
    newNode->next = *head;
    *head = newNode;
}

int evaluatePolynomial(struct Node* head, int x) 
{
    int result = 0;
    struct Node* current = head;
    while (current != NULL) 
    {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }
    return result;
}

int main() 
{
    int degree, x;
    struct Node* head = NULL;

    scanf("%d", &degree);

    for (int i = degree; i >= 0; i--) 
    {
        int coefficient;
        scanf("%d", &coefficient);
        addNode(&head, coefficient, i);
    }

    scanf("%d", &x);

    int result = evaluatePolynomial(head, x);
    printf("%d", result);

    return 0;
}


4.
Problem Statement



Hayley loves studying polynomials, and she wants to write a program to compare two polynomials represented as linked lists and display whether they are equal or not. 



The polynomials are expressed as a series of terms, where each term consists of a coefficient and an exponent. The program should read the polynomials from the user, compare them, and then display whether they are equal or not.

Input format :
The first line of input consists of an integer n, representing the number of terms in the first polynomial.

The following n lines of input consist of two integers, each representing the coefficient and the exponent of the term in the first polynomial.

The next line of input consists of an integer m, representing the number of terms in the second polynomial.

The following m lines of input consist of two integers, each representing the coefficient and the exponent of the term in the second polynomial.

Output format :
The first line of output prints "Polynomial 1: " followed by the first polynomial.

The second line prints "Polynomial 2: " followed by the second polynomial.

The polynomials should be displayed in the format ax^b, where a is the coefficient and b is the exponent.

If the two polynomials are equal, the third line prints "Polynomials are Equal."

If the two polynomials are not equal, the third line prints "Polynomials are Not Equal."



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n, m ≤ 5

Sample test cases :
Input 1 :
2
1 2
2 1
2
1 2
2 1
Output 1 :
Polynomial 1: (1x^2) + (2x^1)
Polynomial 2: (1x^2) + (2x^1)
Polynomials are Equal.
Input 2 :
3
1 2
2 1
3 0
3
1 2
2 1
4 0
Output 2 :
Polynomial 1: (1x^2) + (2x^1) + (3x^0)
Polynomial 2: (1x^2) + (2x^1) + (4x^0)
Polynomials are Not Equal.
Input 3 :
3
-2 3
-4 5
1 2
2
2 3
-4 5
Output 3 :
Polynomial 1: (-2x^3) + (-4x^5) + (1x^2)
Polynomial 2: (2x^3) + (-4x^5)
Polynomials are Not Equal.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) {
            printf(" + ");
        }
        printf("(%dx^%d)", temp->coeff, temp->exp);
        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

int arePolynomialsEqual(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->coeff != head2->coeff || head1->exp != head2->exp) {
            return 0; // Not equal
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) {
        return 1; // Polynomials are equal
    }
    return 0; // One polynomial has more terms than the other
}

int main() {
    int n, m, coeff, exp;
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Input first polynomial
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly1, coeff, exp);
    }

    // Input second polynomial
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly2, coeff, exp);
    }

    // Display the first polynomial
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    // Display the second polynomial
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Check if the two polynomials are equal
    if (arePolynomialsEqual(poly1, poly2)) {
        printf("Polynomials are Equal.\n");
    } else {
        printf("Polynomials are Not Equal.\n");
    }

    return 0;
}


5.
Problem Statement



Madhan is tasked with creating a program that manages a singly linked list with the following functionalities:

Insert elements at the end of the list based on user input.
Sort the elements of the list in ascending order.
Display the sorted elements of the list.


Guide him in the task.

Input format :
The first line of input consists of an integer N, which is the number of elements.

The second line consists of N space-separated integers.

Output format :
The output prints the sorted elements of the linked list.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 10

1 ≤ elements ≤ 100

Sample test cases :
Input 1 :
5
78 89 34 51 67
Output 1 :
34 51 67 78 89 
Input 2 :
7
10 5 20 35 30 15 18
Output 2 :
5 10 15 18 20 30 35 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sortList(struct Node* head) {
    struct Node* current = head;
    struct Node* index = NULL;
    int temp;
    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N, value;
    struct Node* head = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    sortList(head);
    displayList(head);

    return 0;
}
