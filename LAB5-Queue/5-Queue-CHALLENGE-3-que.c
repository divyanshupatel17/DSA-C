1.
Problem Statement



Given an integer K and a queue of integers, reverse the order of the first K elements of the queue, leaving the other elements in the same relative order. 



Note: Use an array for implementation.

Input format :
The first line of input consists of an integer N, representing the number of elements in the queue.

The second line consists of the value of K.

The third line consists of N space-separated queue elements.

Output format :
The output displays "Reversed queue: " followed by the queue elements after the reversal is done, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
The maximum size of the array is 50.

K ≤ N

Sample test cases :
Input 1 :
5
4
1 2 3 4 5
Output 1 :
Reversed queue: 4 3 2 1 5 
Input 2 :
9
5
1 2 3 4 5 6 7 8 9
Output 2 :
Reversed queue: 5 4 3 2 1 6 7 8 9 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char arr[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q){
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(Queue *q){
    return q->front == -1;
}

void enqueue(Queue *q, char item){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = item;
    printf("Character %c is enqueued.\n", item);
}

char dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return '\0';
    }
    char item = q->arr[q->front];
    if(q->front == q->rear){
        initialize(q);
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Characters in the queue are: ");
    for(int i = q->front; i != q->rear; i = (i + 1) % MAX){
        printf("%c ", q->arr[i]);
    }
    printf("%c\n", q->arr[q->rear]);
}

int main(){
    Queue q;
    initialize(&q);
    
    while(1){
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                char c;
                scanf(" %c", &c);
                enqueue(&q, c);
            } break;
            
            case 2: {
                char c = dequeue(&q);
                if(c != '\0'){
                    printf("Dequeued Character: %c\n", c);
                }
            } break;
            
            case 3: 
                display(&q);
                break;
            
            case 4: 
                printf("Exiting program\n");
                exit(0);
            
            default:
                printf("Invalid option.\n");
        }
    }
}

2.

Problem Statement



Sharon, an enthusiastic computer science student, is eager to learn about queues and their implementation using arrays to efficiently handle character data. Your task is to create a user-friendly character queue program to support her learning journey. 



Implement a circular queue that can perform enqueue, dequeue, and display operations on character data. The program should provide clear feedback on the status of the queue after each operation. 

Input format :
The input consists of integers corresponding to the operation that needs to be performed:

Choice 1: Enqueue the character into the queue. If the choice is 1, the following input is a space-separated character, representing the character to be enqueued into the queue.

Choice 2: Dequeue a character from the queue.

Choice 3: Display the characters in the queue.

Choice 4: Exit the program.

Output format :
The output displays messages according to the choice and the status of the queue:



If the choice is 1:

Insert the given character into the queue and display "Character [char] is enqueued." where [char] is the character that is inserted.
If the queue is full, print "Queue is full. Cannot enqueue."
If the choice is 2:

Dequeue a character from the queue and display "Dequeued Character: " followed by the corresponding character that is dequeued.
If the queue is empty without any elements, print "Queue is empty."
If the choice is 3:

The output prints "Characters in the queue are: " followed by the space-separated characters present in the queue.
If there are no elements in the queue, print "Queue is empty."
If the choice is 4:

Exit the program and print "Exiting program"
If any other choice is entered, the output prints "Invalid option."



Refer to the sample output for the exact text and format.

Code constraints :
Maximum size of the queue = 5

Choice: 1, 2, 3, or 4.

Sample test cases :
Input 1 :
1 A
1 B
1 C
1 D
1 E
1 H
3
2
3
4
Output 1 :
Character A is enqueued.
Character B is enqueued.
Character C is enqueued.
Character D is enqueued.
Character E is enqueued.
Queue is full. Cannot enqueue.
Characters in the queue are: A B C D E
Dequeued Character: A
Characters in the queue are: B C D E
Exiting program
Input 2 :
2
1 K
5
4
Output 2 :
Queue is empty.
Character K is enqueued.
Invalid option.
Exiting program
Input 3 :
1 X
1 Y
3
2
3
2
3
2
4
Output 3 :
Character X is enqueued.
Character Y is enqueued.
Characters in the queue are: X Y
Dequeued Character: X
Characters in the queue are: Y
Dequeued Character: Y
Queue is empty.
Queue is empty.
Exiting program

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char arr[MAX];
    int front;
    int rear;
    int size;  // Added size to keep track of number of elements
} Queue;

void initialize(Queue *q){
    q->front = -1;
    q->rear = -1;
    q->size = 0;  // Initialize size to 0
}

int isFull(Queue *q){
    return q->size == MAX;  // Check if size is equal to MAX
}

int isEmpty(Queue *q){
    return q->size == 0;  // Check if size is 0
}

void enqueue(Queue *q, char item){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = item;
    q->size++;
    printf("Character %c is enqueued.\n", item);
}

char dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return '\0';  // Return null character instead of -1
    }
    char item = q->arr[q->front];
    q->size--;
    if(q->size == 0){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Characters in the queue are: ");
    int count = 0;
    int i = q->front;
    while(count < q->size){
        printf("%c ", q->arr[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf("\n");
}

int main(){
    Queue q;
    initialize(&q);
    
    while(1){
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                char c;
                scanf(" %c", &c);  // Added space before %c to consume any whitespace
                enqueue(&q, c);
            } break;
            
            case 2: {
                char c = dequeue(&q);
                if(c != '\0'){
                    printf("Dequeued Character: %c\n", c);
                }
            } break;
            
            case 3: 
                display(&q);
                break;
            
            case 4: 
                printf("Exiting program\n");
                exit(0);
            
            default:
                printf("Invalid option.\n");
        }
    }
}


3.

Problem Statement



Imagine a bustling coffee shop, where customers are placing their orders for their favorite coffee drinks. The cafe owner Sheeren wants to efficiently manage the queue of coffee orders using a digital system. She needs a program to handle this queue of orders.



You are tasked with creating a program that implements a queue for coffee orders. Each character in the queue represents a customer's coffee order, with 'L' indicating a latte, 'E' indicating an espresso, 'M' indicating a macchiato, 'O' indicating an iced coffee, and 'N' indicating a nabob. 



Customers can place orders and enjoy their delicious coffee drinks.

Input format :
The input consists of integers corresponding to the operation that needs to be performed:

Choice 1: Enqueue the coffee order into the queue. If the choice is 1, the following input is a space-separated character ('L', 'E', 'M', 'O', 'N').

Choice 2: Dequeue a coffee order from the queue.

Choice 3: Display the orders in the queue.

Choice 4: Exit the program.

Output format :
The output displays messages according to the choice and the status of the queue:



If the choice is 1:

Insert the given order into the queue and display "Order for [order] is enqueued." where [order] is the coffee order that is inserted.
If the queue is full, print "Queue is full. Cannot enqueue more orders."
If the choice is 2:

Dequeue a character from the queue and display "Dequeued Order: " followed by the corresponding order that is dequeued.
If the queue is empty without any orders, print "No orders in the queue."
If the choice is 3:

The output prints "Orders in the queue are: " followed by the space-separated orders present in the queue.
If there are no orders in the queue, print "Queue is empty. No orders available."
If the choice is 4:

Exit the program and print "Exiting program"
If any other choice is entered, the output prints "Invalid option."



Refer to the sample output for the exact text and format.

Code constraints :
The maximum size of the coffee order queue = 5

Customers can place the following orders: 'L', 'E', 'M', 'O', 'N'

Choice: 1, 2, 3, or 4.

Sample test cases :
Input 1 :
1 L
1 E
1 M
1 O
1 N
1 O
3
2
3
4
Output 1 :
Order for L is enqueued.
Order for E is enqueued.
Order for M is enqueued.
Order for O is enqueued.
Order for N is enqueued.
Queue is full. Cannot enqueue more orders.
Orders in the queue are: L E M O N
Dequeued Order: L
Orders in the queue are: E M O N
Exiting program
Input 2 :
1 L
1 E
1 M
3
2
5
4
Output 2 :
Order for L is enqueued.
Order for E is enqueued.
Order for M is enqueued.
Orders in the queue are: L E M
Dequeued Order: L
Invalid option.
Exiting program
Input 3 :
2
3
4
Output 3 :
No orders in the queue.
Queue is empty. No orders available.
Exiting program
Input 4 :
1 L
1 M
3
2
2
3
2
4
Output 4 :
Order for L is enqueued.
Order for M is enqueued.
Orders in the queue are: L M
Dequeued Order: L
Dequeued Order: M
Queue is empty. No orders available.
No orders in the queue.
Exiting program

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct {
    char arr[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q){
    return q->rear == MAX-1;
}

int isEmpty(Queue *q){
    return q->front == -1;
}

void enqueue(Queue *q,char item){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue more orders.\n");
        return ;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = item;
    printf("Order for %c is enqueued.\n",item);
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("No orders in the queue.\n");
        return;
    } 
    char item = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Dequeued Order: %c\n",item);
    // return item;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty. No orders available.\n");
        return;
    } 
    printf("Orders in the queue are:");
    for(int i=q->front ; i<=q->rear ; i++){
        printf(" %c",q->arr[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    initialize(&q);
    while(1){
        int ch;
        scanf("%d",&ch);
        
        switch(ch){
            case 1:{
                char item;
                scanf(" %c",&item);
                enqueue(&q,item);
                break;
            }
            
            case 2:{
                dequeue(&q);
                break;
            }
            
            case 3:{
                display(&q);
                break;
            }
            
            case 4:{
                printf("Exiting program\n");
                exit(0);
                break;
            }
            
            default:{
                printf("Invalid option.\n");
                break;
            }
        }
    }
    return 0;
}

















