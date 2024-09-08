STAR : Q2

1.
Problem Statement



Rathi, a budding programmer, is fascinated by palindromes. She has recently learned about deques (double-ended queues) and is eager to use them to check if a given string is a palindrome or not.



A palindrome is a sequence of characters that reads the same forwards and backward, ignoring spaces, punctuation, and capitalization.



Your task is to help Rathi develop a program that takes a string as input, checks if it is a palindrome using a deque data structure, and outputs whether the string is a palindrome or not.

Input format :
The input consists of a single line containing a string that represents the length of the string.

The string may contain alphanumeric characters.

Output format :
The output prints whether the given string is a palindrome or not.

If the string is a palindrome, the output prints "The string is a palindrome." 

If the string is not a palindrome, the output prints "The string is not a palindrome." 



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ length of the input string ≤ 100

Sample test cases :
Input 1 :
detartrated
Output 1 :
The string is a palindrome.
Input 2 :
Hello123olleh
Output 2 :
The string is not a palindrome.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX 100
#define LEN 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

void initialize(Deque *dq){
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq){
    return dq->front == -1;
}

int isFull(Deque *dq){
    return dq->rear == MAX-1;
}

void insertFront(Deque *dq,char item){
    if(isFull(dq) || dq->front==0){
        return ;
    }
    if(isEmpty(dq)){
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = item;
}

void insertRear(Deque *dq,char item){
    if(isFull(dq)){
        return ;
    }
    if(isEmpty(dq)){
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = item;
}

char deleteFront(Deque *dq){
    if(isEmpty(dq)){
        return -1;
    }
    char item = dq->arr[dq->front];
    if(dq->front == dq->rear){
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front++;
    }
    return item;
}

char deleteRear(Deque *dq){
    if(isEmpty(dq)){
        return -1;
    }
    char item = dq->arr[dq->rear];
    if(dq->front == dq->rear){
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear--;
    }
    return item;
}

bool isPal(char str[]){
    Deque dq;
    initialize(&dq);
    for(int i=0 ; str[i]!='\0' ; i++){
        if(isalnum(str[i])){
            insertRear(&dq,tolower(str[i]));
        }
    }
    while(dq.front < dq.rear){
        if(deleteFront(&dq)!=deleteRear(&dq)){
            return false;
        }
    }
    return true;
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    
    if(isPal(str)){
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.");
    }
    return 0;
}

2.

Problem Statement



Iniya needs to implement a deque data structure using an array. The deque should support the following operations:



Insertion of an element at the front of the deque.
Insertion of an element at the rear of the deque.
Deletion of an element from the front of the deque.
Deletion of an element from the rear of the deque.


Write a program that implements the deque data structure using an array and provides the above-mentioned operations.



Example



Input

5

1 5

2 7

1 10

2 15

1 3

78

95



Output

Orginal Deque: 3 10 5 7 15

Deque after removing front and rear elements: 10 5 7

Deque after adding new front and rear elements: 78 10 5 7 95



Explanation:

Original Deque: After the initial insertions, the deque contains [3, 10, 5, 7, 15].

Deque after removing the front and rear elements: 3 is removed from the front, and 15 is removed from the rear, resulting in [10, 5, 7].

Deque after adding new front and rear elements: 78 is inserted at the front, and 95 is inserted at the rear, resulting in [78, 10, 5, 7, 95].

Input format :
The first line contains an integer size, indicating the size of the deque.

The next size lines contain operations to perform on the deque.

Each operation is represented by an integer choice followed by an integer value if applicable.

For choice = 1: Insert value at the front of the deque.

For choice = 2: Insert value at the rear of the deque.

Output format :
The output displays the following format:

Original Deque: <elements>

Deque after removing front and rear elements: <updated elements>

Deque after adding new front and rear elements: <updated elements>



Refer to the sample input and output for the formatting specifications.

Code constraints :
1 ≤ size ≤ 50

The input choice is either 1 or 2.

Sample test cases :
Input 1 :
5
1 5
2 7
1 10
2 15
1 3
78
95
Output 1 :
Original Deque: 3 10 5 7 15
Deque after removing front and rear elements: 10 5 7
Deque after adding new front and rear elements: 78 10 5 7 95

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} deque;

void initialize(deque *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(deque *q){
    return q->rear == MAX-1;
}

int isEmpty(deque *q){
    return q->front == -1;
}

void insertFront(deque *q, int item){
    if(isFull(q)){
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else if(q->front>0){
        q->front--;
    } else {
        for(int i=q->rear ; i>=q->front ; i--){
            q->arr[i+1] = q->arr[i];
        }
        q->rear++;
    }
    q->arr[q->front] = item;
}

void insertRear(deque *q, int item){
    if(isFull(q)){
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = item;
}

int deleteFront(deque *q){
    if(isEmpty(q)){
        return -1;
    }
    int item = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int deleteRear(deque *q){
    if(isEmpty(q)){
        return -1;
    }
    int item = q->arr[q->rear];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->rear--;
    }
    return item;
}

void display(deque *q){
    if(isEmpty(q)){
        return;
    }
    for(int i = q->front; i < q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("%d", q->arr[q->rear]);
    printf("\n");
}

int main(){
    deque q;
    initialize(&q);
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int choice, item;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                scanf("%d", &item);
                insertFront(&q, item);
                break;
            case 2:
                scanf("%d", &item);
                insertRear(&q, item);
                break;
        }
    }
    
    printf("Original Deque: ");
    display(&q);
    
    deleteFront(&q);
    deleteRear(&q);
    printf("Deque after removing front and rear elements: ");
    display(&q);
    
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    insertFront(&q, num1);
    insertRear(&q, num2);
    printf("Deque after adding new front and rear elements: ");
    display(&q);
    
    return 0;
}














