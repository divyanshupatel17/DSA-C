Problem Statement



Jack is working on a project involving a doubly linked list of integers. He needs to find all pairs of nodes in the list that sum up to a given value, x. Jack wants to implement a function that efficiently identifies and prints these pairs or indicates if no such pairs exist. Help him by giving a suitable program.

Input format :
The first line of input contains an integer n, representing the number of elements in the linked list.

The second line consists of n space-separated positive distinct integers, representing the elements in the sorted doubly-linked list.

The third line contains an integer x, indicating the target sum value.

Output format :
The output should display pairs in the linked list whose sum equals x.

If there are no such pairs in the list, print "No pair found".



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, given test cases will fall under the following constraints:

2 ≤ n ≤ 10

0 ≤ element, x ≤ 100

Sample test cases :
Input 1 :
7
1 2 4 5 6 8 9
7
Output 1 :
(6, 1)
(5, 2)
Input 2 :
7
1 2 4 5 6 8 9
3
Output 2 :
(2, 1)
Input 3 :
7
1 2 4 5 6 8 9
30
Output 3 :
No pair found
Input 4 :
5
0 1 2 3 5
5
Output 4 :
(5, 0)
(3, 2)

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

void insertAtEnd(struct Node** head, int data) {
    struct Node* nn = createNode(data);
    if (*head == NULL) {
        *head = nn;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
}


void findPair(struct Node* head,int sum){
    if(head == NULL){
        return;
    } else {
        struct Node* left = head;
        struct Node* right = head;
        
        while(right->next != NULL){
            right = right->next;
        }
        
        int found = 0;
        
        while(left != right && left->prev != right && left!=NULL && right!=NULL){
            int pairSum = left->data + right->data;
            
            if(pairSum == sum){
                found = 1;
                printf("(%d, %d)\n",right->data,left->data);
                left = left->next;
                right = right->prev;
            } else if(pairSum < sum){
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        
        if(!found){
            printf("No pair found");
        }
    }
}

int main(){
    struct Node* head = NULL;
    
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ; i<n ; i++){
        int data;
        scanf("%d",&data);
        insertAtEnd(&head,data);
    }
    int sum;
    scanf("%d",&sum);
    
    findPair(head,sum);
    return 0;
}

2.

Problem Statement



Katherine is implementing a program to maintain a sorted doubly linked list of integers. She wants to read a set of integers from the user, insert them into the list in a sorted manner, and then insert an additional integer while preserving the sorted order. Finally, Katherine aims to print the entire list to verify the correct order. Help her with a program.



Example



Input:

5 // number of elements

3 5 8 10 12 // elements

9 // element to be inserted



Output:

3 5 8 9 10 12 // final list after inserting 9 in the right position

Input format :
The first line of input consists of an integer n, representing the number of elements in the initial linked list.

The second line consists of n space-separated integers, representing the sorted elements.

The third line consists of an integer, representing the element to be inserted in the linked list in a sorted way.

Output format :
The output prints the updated linked list after inserting the given element in a sorted way.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ n ≤ 20

1 ≤ sorted elements ≤ 100

Sample test cases :
Input 1 :
5
3 5 8 10 12
9
Output 1 :
3 5 8 9 10 12 
Input 2 :
8
14 19 24 26 36 39 47 51
30
Output 2 :
14 19 24 26 30 36 39 47 51

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

// Function to insert a node in a sorted manner
void insertSorted(struct Node** head, int data) {
    struct Node* nn = createNode(data);
    
    // If the list is empty
    if (*head == NULL) {
        *head = nn;
        return;
    }

    struct Node* curr = *head;

    // If the new data is smaller than the head, insert at the beginning
    if (data <= (*head)->data) {
        nn->next = *head;
        (*head)->prev = nn;
        *head = nn;
        return;
    }

    // Traverse the list to find the correct position to insert
    while (curr->next != NULL && curr->next->data < data) {
        curr = curr->next;
    }

    // Insert the node in the correct position
    nn->next = curr->next;
    nn->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = nn;
    }
    curr->next = nn;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    // Read the number of elements in the list
    scanf("%d", &n);

    // Insert the initial sorted elements into the list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertSorted(&head, data);
    }

    // Read the element to be inserted
    int newElement;
    scanf("%d", &newElement);

    // Insert the new element while maintaining the sorted order
    insertSorted(&head, newElement);

    // Print the final sorted list
    printList(head);

    return 0;
}
