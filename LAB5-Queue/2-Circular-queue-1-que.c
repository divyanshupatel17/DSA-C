Single File Programming Question
Problem Statement



You are tasked with implementing a circular queue to manage a list of integers. Your circular queue should support the following operations:



Insert an element: Add a new integer to the queue.
Delete an element: Remove an integer from the front of the queue.
Display the queue: Print all the elements in the queue in their current order.


Note: The queue can hold up to MAX = 10 elements.

Input format :
The input consists of an integer choice which determines the operation to be performed:



1: Insert an element into the queue, If the choice is 1, followed by an integer item which is the element to be inserted, separated by a space.

2: Delete an element from the queue.

3: Display the elements in the queue.

4: Exit the program.

Output format :
The output displays the following format:

For Insert Operation choice 1: If the queue is full, print "Queue Overflow". Otherwise, no output is generated for the insert operation.

For Delete Operation choice 2: If the queue is empty, print "Queue Underflow". Otherwise, print "Element deleted from queue is: X" where X is the integer that was removed from the queue.

For Display Operation choice 3: Print "Queue elements:" followed by the integers in the queue from front to rear.

If the queue is empty, print "Queue is empty".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

The queue has a maximum capacity of 10 elements.

The queue operations should be performed in a circular manner.

The operations will be continuous until the exit choice (4) is selected.

Sample test cases :
Input 1 :
1 11
1 22
1 33
2
1 44
1 55
3
4
Output 1 :
Element deleted from queue is: 11
Queue elements:
22 33 44 55 
Input 2 :
2
4
Output 2 :
Queue Underflow
Input 3 :
-1
4
Output 3 :
Wrong choice
Input 4 :
1 22
1 33
1 44
1 55
1 66
1 77
1 88
1 99
1 100
1 111
1 122
4
Output 4 :
Queue Overflow
Input 5 :
3
4
Output 5 :
Queue is empty

// FUNCTION : 

// initialize
// isEmpty
// isFull
// enqueue
// dequeue
// peek
// display

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;
void initialize(Queue *q){
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q){
    return q->front==-1;
}
int isFull(Queue *q){
    return (q->rear + 1)%MAX_SIZE == q->front;
}
void enqueue(Queue *q,int item){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return ;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear+1)%MAX_SIZE ;
    }
    q->arr[q->rear] = item;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        // exit(1);
        return -1;
    }
    int dequeuedItem = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front+1)%MAX_SIZE;
    }
    return dequeuedItem;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i = q->front;
    while(1){
        printf("%d ",q->arr[i]);
        if(i==q->rear){
            break;
        }
        i=(i+1)%MAX_SIZE;
    }
    printf("\n");
}

int main(){
    Queue q;
    initialize(&q);
    int flag = 1;
    while(flag){
        int n;
        scanf("%d",&n);
        switch(n){
            case 1 : {
            int item;
            scanf("%d",&item);
            enqueue(&q,item);
            break;
            }
            
            case 2:{
            int res = dequeue(&q);
            if(res != -1){
                printf("Element deleted from queue is: %d\n",res);
            }
            break;
            }
            
            case 3:
            display(&q);
            break;
            
            case 4:
            flag = 0;
            break;
            
            default:
            printf("Wrong choice");
        }
    }
    return 0;
}

Result
5/5 Sample testcase passed
Compiler Message
Compilation successful
Sample Testcase
Testcase 1 - Passed
Expected Output
Element deleted from queue is: 11
Queue elements:
22 33 44 55 
Output
Element deleted from queue is: 11
Queue elements:
22 33 44 55 
Testcase 2 - Passed
Expected Output
Queue Underflow
Output
Queue Underflow
Testcase 3 - Passed
Expected Output
Wrong choice
Output
Wrong choice
Testcase 4 - Passed
Expected Output
Queue Overflow
Output
Queue Overflow
Testcase 5 - Passed
Expected Output
Queue is empty
Output
Queue is empty