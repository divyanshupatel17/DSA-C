1.
Problem Statement



Given a singly linked list with n values, the linked list needs to be modified such that the even numbers are displayed at the beginning, followed by the odd numbers in a reversed manner.



Example



Input:

5

12 15 13 14 16



Output: 

16 14 12 13 15



Explanation

The even numbers are 12, 14, 16. 

The odd numbers are 15, 13. 

Reverse the even numbers, we get 16, 14, 12. 

By reversing the odd numbers, we get 13, 15. 

Display the even numbers followed by the odd numbers, so the modified list is 16, 14, 12, 13, 15.

Input format :
The first line of input contains an integer n, representing the number of elements in the linked list.

The second line contains n space-separated integers, representing the elements of the linked list.

Output format :
The output displays a list containing the even numbers followed by the odd numbers in a reversed manner.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 20

1 ≤ elements ≤ 150

Sample test cases :
Input 1 :
4
1 2 3 4
Output 1 :
4 2 3 1 
Input 2 :
5
12 15 13 14 16
Output 2 :
16 14 12 13 15 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    }
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* reverseList(Node* head) 
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void partitionAndReverse(Node* head, Node** evenHead, Node** oddHead) 
{
    Node* current = head;
    while (current != NULL) 
    {
        if (current->data % 2 == 0) 
        {
            insertEnd(evenHead, current->data);
        }
        else 
        {
            insertEnd(oddHead, current->data);
        }
        current = current->next;
    }
    *evenHead = reverseList(*evenHead);
    *oddHead = reverseList(*oddHead);
}

void printList(Node* head) 
{
    if (head == NULL) 
    {
        printf("\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        
        printf("%d ", temp->data);
        if (temp->next != NULL) 
        {
        }
        temp = temp->next;
    }
}

void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) 
    {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    Node* evenHead = NULL;
    Node* oddHead = NULL;

    partitionAndReverse(head, &evenHead, &oddHead);

    printList(evenHead);
    printList(oddHead);

    freeList(head);
    freeList(evenHead);
    freeList(oddHead);

    return 0;
}




2.
Problem Statement



Anderson needs a program to manage a linked list. He wants to input a series of integer values to populate the linked list and later remove a specified node from the end of the list. Implement a function that allows Anderson to add values, remove a node based on its position from the end, and display the current elements of the linked list.

Input format :
The first line of input consists of an integer n, representing the number of nodes in the linked list.

The second line consists of n space-separated integers, denoting the values of the nodes in the linked list.

The third line consists of an integer N, representing the position of the node to be removed from the end.

Output format :
The output prints the space-separated integers representing the values of the nodes in the linked list after removing the Nth node from the end.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 30

0 ≤ elements of the linked list ≤ 100

N ≤ n

Sample test cases :
Input 1 :
5
1 2 3 4 5
2
Output 1 :
1 2 3 5 
Input 2 :
2
1 2 
1
Output 2 :
1 


#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeNthFromEnd(Node** head, int n) 
{
    Node* first = *head;
    Node* second = *head;
    Node* prev = NULL;
    
    for (int i = 0; i < n; i++) 
    {
        if (second == NULL)  return;  
        second = second->next;
    }
    
    while (second != NULL) 
    {
        prev = first;
        first = first->next;
        second = second->next;
    }
    
    if (prev != NULL) 
    {
        prev->next = first->next;
    } 
    else 
    {
        *head = first->next;
    }
    
    free(first);
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL) 
        {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    Node* head = NULL;
    for (int i = 0; i < n; i++) 
    {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }
    
    int N;
    scanf("%d", &N);
    
    removeNthFromEnd(&head, N);
    printList(head);
    freeList(head);
    
    return 0;
}

