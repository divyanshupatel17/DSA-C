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

