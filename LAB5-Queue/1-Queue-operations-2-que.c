1. 
Problem Statement



Sharon, an enthusiastic computer science student, is eager to learn about queues and their implementation using arrays to efficiently handle character data. 



Your task is to create a user-friendly character queue program to support her learning journey. 



The program should encompass the following functionalities:

Initialize the Queue: The program should start with an empty character queue, capable of holding up to five characters.
Enqueue Characters: The program should add characters to the queue. When the queue is full, the program should inform that additional characters cannot be enqueued.
Dequeue Characters: The program should enable the removal of characters from the front of the queue. When a character is dequeued, the program should notify about which character was removed. If the queue is empty, an appropriate message should be displayed.
Display the Queue: The characters should be presented in the order they were added.
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

#define MAX_SIZE 5

typedef struct {
    char arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q){
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q){
    return q->front > q->rear;
}
int isFull(Queue *q){
    return q->rear == MAX_SIZE-1;
}



void enqueue(Queue *q, char item){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue.\n");
        return ;
    }
    q->arr[++(q->rear)] = item;
    printf("Character %c is enqueued.\n",item);
}



void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return ;
    }
    char dequeuedItem = q->arr[q->front++];
    printf("Dequeued Character: %c\n",dequeuedItem);
}

void printQueue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return ;
    }
    printf("Characters in the queue are: ");
    for(int i=q->front ; i<q->rear ; i++){
        printf("%c ",q->arr[i]);
    }
    printf("%c",q->arr[q->rear]);
    printf("\n");
}


int main(){
    Queue q;
    initialize(&q);
    
    int n;
    char s;
    while(1){
        scanf("%d",&n);
        if(n==1){
            scanf(" %c",&s);
            enqueue(&q,s);
        }
        else if(n==2){
            dequeue(&q);
        }
        else if(n==3){
            printQueue(&q);
        }
        else if(n==4){
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
    return 0;
}


2.
Problem Statement



In a bustling IT department, staff regularly submit helpdesk tickets to request technical assistance. Managing these tickets efficiently is vital for providing quality support.



Your task is to develop a program that uses an array-based queue to handle and prioritize helpdesk tickets based on their unique IDs.



Implement a program that provides the following functionalities:

Enqueue Helpdesk Ticket: Add a new helpdesk ticket to the end of the queue. Provide a positive integer representing the ticket ID for the new ticket.
Dequeue Helpdesk Ticket: Remove and process the next helpdesk ticket from the front of the queue. The program will display the ticket ID of the processed ticket.
Display Queue: Display the ticket IDs of all the helpdesk tickets currently in the queue.
Input format :
The input consists of integers corresponding to the operation that needs to be performed:

Choice 1: Enqueue the ticket ID into the queue. If the choice is 1, the following input is a space-separated integer, representing the ticket ID to be enqueued into the queue.

Choice 2: Dequeue a ticket from the queue.

Choice 3: Display the ticket IDs in the queue.

Choice 4: Exit the program.

Output format :
The output displays messages according to the choice and the status of the queue:



If the choice is 1:

Insert the given ticket ID into the queue and display "Helpdesk Ticket ID [id] is enqueued." where [id] is the ticket ID that is inserted.
If the queue is full, print "Queue is full. Cannot enqueue."
If the choice is 2:

Dequeue a ticket ID from the queue and display "Dequeued Helpdesk Ticket ID " followed by the corresponding ID that is dequeued.
If the queue is empty without any elements, print "Queue is empty."
If the choice is 3:

The output prints "Helpdesk Ticket IDs in the queue are: " followed by the space-separated ticket IDs present in the queue.
If there are no elements in the queue, print "Queue is empty."
If the choice is 4:

Exit the program and print "Exiting the program"
If any other choice is entered, print "Invalid option."



Refer to the sample output for the exact text and format.

Code constraints :
Maximum number of helpdesk tickets stored in the queue = 5

Choice: 1, 2, 3, or 4

Sample test cases :
Input 1 :
1 101
1 202
1 203
1 204
1 205
1 206
3
2
3
4
Output 1 :
Helpdesk Ticket ID 101 is enqueued.
Helpdesk Ticket ID 202 is enqueued.
Helpdesk Ticket ID 203 is enqueued.
Helpdesk Ticket ID 204 is enqueued.
Helpdesk Ticket ID 205 is enqueued.
Queue is full. Cannot enqueue.
Helpdesk Ticket IDs in the queue are: 101 202 203 204 205
Dequeued Helpdesk Ticket ID: 101
Helpdesk Ticket IDs in the queue are: 202 203 204 205
Exiting the program
Input 2 :
2
1 105
5
4
Output 2 :
Queue is empty.
Helpdesk Ticket ID 105 is enqueued.
Invalid option.
Exiting the program
Input 3 :
1 105
3
2
3
2
4
Output 3 :
Helpdesk Ticket ID 105 is enqueued.
Helpdesk Ticket IDs in the queue are: 105
Dequeued Helpdesk Ticket ID: 105
Queue is empty.
Queue is empty.
Exiting the program

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Maximum number of helpdesk tickets in the queue

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Initialize the circular queue
void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Enqueue an item to the queue
void enqueue(CircularQueue *q, int ticketID) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = ticketID;
    printf("Helpdesk Ticket ID %d is enqueued.\n", ticketID);
}

// Dequeue an item from the queue
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int dequeuedID = q->arr[q->front];
    printf("Dequeued Helpdesk Ticket ID: %d\n", dequeuedID);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

// Display the elements in the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Helpdesk Ticket IDs in the queue are: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->arr[q->rear]);  // Print the last element
}

int main() {
    CircularQueue q;
    initialize(&q);

    int choice, ticketID;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &ticketID);
                enqueue(&q, ticketID);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting the program\n");
                return 0;

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}
