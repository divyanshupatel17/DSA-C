Single File Programming Question
Problem Statement



Krishna needs to create a doubly linked list to store and display a sequence of integers. Your task is to help write a program to read a list of integers from input, store them in a doubly linked list, and then display the list.

Input format :
The first line of input consists of an integer n, representing the number of integers in the list.

The second line of input consists of n space-separated integers.

Output format :
The output prints a single line displaying the integers in the order they were added to the doubly linked list, separated by spaces.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, given test cases will fall under the following constraints:

0 ≤ n ≤ 10

1 ≤ elements ≤ 150

Sample test cases :
Input 1 :
5
1 2 3 4 5
Output 1 :
1 2 3 4 5 
Input 2 :
8
90 80 70 60 50 40 30 20
Output 2 :
90 80 70 60 50 40 30 20 
Input 3 :
0
Output 3 :
List is empty

// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void insertAtEnd(struct Node** head,int data){
    struct Node* nn = createNode(data);
    if(*head == NULL){
        *head = nn;
    } else {
        struct Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
}

void printList(struct Node** head){
    if(*head == NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp = *head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = NULL;
    
    int n;
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++){
        int data;
        scanf("%d",&data);
        insertAtEnd(&head,data);
    }
    printList(&head);
}

2.

Problem Statement



Tej wants to write a program to find the maximum marks from a doubly linked list that represents his assignment scores. Help him by providing a code that populates the doubly linked list with user inputs and finds the maximum marks in the list.

Input format :
The first line consists of an integer N, representing the number of elements to be initially inserted into the doubly linked list.

The second line consists of N space-separated integers, denoting the marks to be inserted.

Output format :
The output prints an integer, representing the maximum marks present in the list.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, given test cases will fall under the following constraints:

1 ≤ N ≤ 20

1 ≤ marks ≤ 100

Sample test cases :
Input 1 :
4
89 71 2 70
Output 1 :
89
Input 2 :
7
7 32 10 74 68 44 9
Output 2 :
74

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void insertAtBeg(struct Node** head,int data){
    struct Node* nn = createNode(data);
    if(*head == NULL){
        *head = nn;
    } else {
        nn->next = *head;
        (*head)->prev = nn;
        *head = nn;
    }
}

int findMax(struct Node** head){
    int max = 0;
    struct Node* temp = *head;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int main(){
    struct Node* head = NULL;
    
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        int data;
        scanf("%d",&data);
        insertAtBeg(&head,data);
    }
    
    int max = findMax(&head);
    printf("%d",max);
    return 0;
}


3.
Problem Statement



Pranav wants to clockwise rotate a doubly linked list by a specified number of positions. He needs your help to implement a program to achieve this. Given a doubly linked list and an integer representing the number of positions to rotate, write a program to clockwise rotate the list accordingly.

Input format :
The first line of input consists of an integer n, representing the number of elements in the linked list.

The second line of input consists of n space-separated linked list elements.

The third line of input consists of an integer k, representing the element that represents the number of places to rotate the list.

Output format :
The output displays the elements of the doubly linked list after rotating it by k positions.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, given test cases will fall under the following constraints:

1 ≤ n ≤ 30

1 ≤ elements ≤ 1000

1 ≤ k ≤ n

Sample test cases :
Input 1 :
5
1 2 3 4 5
1
Output 1 :
5 1 2 3 4 
Input 2 :
5
10 20 30 40 50
3
Output 2 :
30 40 50 10 20 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void rotateClockwise(struct Node** head_ref, int k) {
    if (k == 0)
        return;

    struct Node* current = *head_ref;
    int count = 1;

    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    struct Node* kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    (*head_ref)->prev = current;

    *head_ref = kthNode->next;
    (*head_ref)->prev = NULL;
    kthNode->next = NULL;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, k, value;

    // Input number of elements
    scanf("%d", &n);

    // Input elements of the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Input the number of positions to rotate
    scanf("%d", &k);

    // Rotate the list by k positions clockwise
    rotateClockwise(&head, n - k);

    // Print the rotated list
    printList(head);

    return 0;
}

4.
Problem Statement



Sam is learning about two-way linked lists. He came across a problem where he had to populate a two-way linked list and print the original as well as the reverse order of the list. Assist him with a suitable program.

Input format :
The first line of input consists of an integer n, representing the number of elements in the list.

The second line consists of n space-separated integers, representing the elements.

Output format :
The first line displays the message: "List in original order:"

The second line displays the elements of the doubly linked list in the original order.

The third line displays the message: "List in reverse order:"

The fourth line displays the elements of the doubly linked list in reverse order.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 30

Sample test cases :
Input 1 :
5
1 2 3 4 5
Output 1 :
List in original order:
1 2 3 4 5 
List in reverse order:
5 4 3 2 1 
Input 2 :
8
45 63 95 74 14 25 36 96
Output 2 :
List in original order:
45 63 95 74 14 25 36 96 
List in reverse order:
96 36 25 14 74 95 63 45 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void printOriginalList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printReverseList(Node* head) {
    while (head->next) {
        head = head->next;
    }

    while (head) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("List in original order:\n");
    printOriginalList(head);

    printf("List in reverse order:\n");
    printReverseList(head);

    return 0;
}


5.
Single File Programming Question
Problem Statement



Ashiq is developing a basic ticketing system for a small amusement park. The park issues tickets to visitors in the order they arrive. Each ticket has a unique number associated with it. The system needs to manage the queue of visitors waiting to enter the park.



To manage the ticket queue, Ashiq decided to use a doubly linked list where each node represents a ticket with a unique number. The system needs to support the following operations:



Adding a new ticket to the end of the queue.
Removing the ticket of the first visitor (at the front of the queue).
Printing the remaining tickets in the queue.
Input format :
The first line consists of an integer n, representing the number of tickets to be issued.

The second line consists of n space-separated integers, each representing the ticket number of a visitor in the order they arrive.

Output format :
The output prints space-separated integers, representing the remaining ticket numbers in the queue after the removal.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 50

1 ≤ node values ≤ 105

Sample test cases :
Input 1 :
7
24 96 41 85 97 91 13
Output 1 :
96 41 85 97 91 13 
Input 2 :
4
98 57 35 61
Output 2 :
57 35 61 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addTicket(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void removeTicket(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void printTickets(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int ticketNumbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ticketNumbers[i]);
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        addTicket(&head, &tail, ticketNumbers[i]);
    }

    removeTicket(&head);

    printTickets(head);

    return 0;
}
