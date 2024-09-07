1.
Problem Statement



Gokul is working on a program to rearrange elements in a queue using an array. Given a queue of integers, he needs to modify it by interleaving its first half with the second half. Write a program to help Gokul achieve this task.



Note:  Interleaving involves merging elements from two separate halves in an alternating fashion to create a new sequence.



Example

Input 

6

1 2 3 7 9 5

Output 

1 7 2 9 3 5 



Explanation

The interleave rearranges elements in a queue by alternating between two halves. For instance, given input [1, 2, 3, 7, 9, 5], it splits into [1, 2, 3] and [7, 9, 5], then interleaves them as [1, 7, 2, 9, 3, 5]. It achieves this by splitting the queue into two halves and then merging them in an interleaved manner.



Company Tags: Adobe

Input format :
The first line of input consists of an integer n, representing the number of elements in the queue.

The second line consists of n space-separated integers, representing the queue elements.

Output format :
The output prints n space-separated integers, representing the rearranged queue after interleaving its first half with the second half.



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ n ≤ 10, where n will always be even.

1 ≤ queue elements ≤ 1000

Sample test cases :
Input 1 :
6
1 2 3 7 9 5
Output 1 :
1 7 2 9 3 5 
Input 2 :
4
14 62 56 41
Output 2 :
14 56 62 41 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int dequeuedItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedItem;
}

void interleaveQueue(Queue *q) {
    int n = (q->rear - q->front + 1);  // Total number of elements
    int half = n / 2;

    int firstHalf[MAX_SIZE], secondHalf[MAX_SIZE];

    // Dequeue the first half into firstHalf array
    for (int i = 0; i < half; i++) {
        firstHalf[i] = dequeue(q);
    }

    // Dequeue the second half into secondHalf array
    for (int i = 0; i < half; i++) {
        secondHalf[i] = dequeue(q);
    }

    // Interleave the first and second halves back into the queue
    for (int i = 0; i < half; i++) {
        enqueue(q, firstHalf[i]);
        enqueue(q, secondHalf[i]);
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    int n;
    scanf("%d", &n);  // Number of elements in the queue

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        enqueue(&q, num);
    }

    // Interleave the queue
    interleaveQueue(&q);

    // Display the interleaved queue
    display(&q);

    return 0;
}


2.


Problem Statement



Liam is developing a financial application that calculates the moving average of stock prices over a series of time intervals. He wants a program using a queue to process a stream of stock prices and return the moving average of the prices seen so far.



Example

Input

3

1 2 3

Output

1.00 1.50 2.00 

Explanation

The moving average of the first element is 1.00.

The next elements are 1 and 2, the moving average is (1 + 2) / 2 = 1.50.

The next elements are 1, 2, and 3, the moving average is (1 + 2 + 3) / 3 = 2.00.

Input format :
The first line of input consists of an integer n, representing the number of stock prices

The second line consists of n space-separated integers, representing a stock price.

Output format :
The output displays space-separated double values representing the moving average of the stock prices up to the current price, each rounded to two decimal places.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 15

10 ≤ queue elements ≤ 100

Sample test cases :
Input 1 :
3
1 2 3
Output 1 :
1.00 1.50 2.00 
Input 2 :
5
40 26 22 12 83
Output 2 :
40.00 33.00 29.33 25.00 36.60

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = item;
}

void calculateMovingAverage(Queue *q) {
    float sum = 0.0;
    for (int i = q->front; i <= q->rear; i++) {
        sum += q->arr[i];
        float avg = sum / (i - q->front + 1);
        printf("%.2f ", avg);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    int n;
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {
        int price;
        scanf("%d", &price);
        enqueue(&q, price);
    }

    calculateMovingAverage(&q);

    return 0;
}


3.

Problem Statement



You are working as a software engineer for a bus ticketing system. The system needs to handle ticket requests efficiently. Each request arrives at the system with a timestamp representing the time when the request was made. To process these requests in the correct order, you need to sort them by their timestamps before handling them.



Your task is to write a program that reads a list of ticket request timestamps, sorts them in ascending order, and then prints the sorted list. The queue of ticket requests will be implemented using a linked list.

Input format :
The first line consists of an integer n, the number of ticket requests.

The second line consists of space-separated integers, representing the request timestamp.

Output format :
The output displays integers, representing the sorted request timestamps on a single line, separated by spaces.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ n ≤ 25

0 ≤ timestamp ≤ 100

Sample test cases :
Input 1 :
4
19 29 12 18
Output 1 :
12 18 19 29 
Input 2 :
7
4 5 6 7 8 9 3 
Output 2 :
3 4 5 6 7 8 9 
Input 3 :
5
10 26 29 28 17
Output 3 :
10 17 26 28 29 

1. Queue Implementation Using Array with qsort

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25  // Maximum size for the array queue

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} QueueArray;

void initializeQueueArray(QueueArray *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueArrayFull(QueueArray *q) {
    return q->rear == MAX_SIZE - 1;
}

int isQueueArrayEmpty(QueueArray *q) {
    return q->front > q->rear;
}

void enqueueArray(QueueArray *q, int item) {
    if (isQueueArrayFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[++(q->rear)] = item;
}

int dequeueArray(QueueArray *q) {
    if (isQueueArrayEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->arr[q->front++];
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    QueueArray q;
    initializeQueueArray(&q);
    
    int n;
    scanf("%d", &n);
    int timestamps[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        int timestamp;
        scanf("%d", &timestamp);
        enqueueArray(&q, timestamp);
    }
    
    // Copy queue elements to array for sorting
    for (int i = 0; i < n; i++) {
        timestamps[i] = dequeueArray(&q);
    }
    
    // Sort timestamps using qsort
    qsort(timestamps, n, sizeof(int), compare);
    
    // Print sorted timestamps
    for (int i = 0; i < n; i++) {
        printf("%d ", timestamps[i]);
    }
    printf("\n");
    
    return 0;
}

2. Queue Implementation Using Linked List with qsort

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25  // Maximum size for the array queue

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} QueueLinkedList;

void initializeQueueLinkedList(QueueLinkedList *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueLinkedListEmpty(QueueLinkedList *q) {
    return q->front == NULL;
}

void enqueueLinkedList(QueueLinkedList *q, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    
    if (isQueueLinkedListEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeueLinkedList(QueueLinkedList *q) {
    if (isQueueLinkedListEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main() {
    QueueLinkedList q;
    initializeQueueLinkedList(&q);
    
    int n;
    scanf("%d", &n);
    int timestamps[MAX_SIZE];
    int size = 0;
    
    for (int i = 0; i < n; i++) {
        int timestamp;
        scanf("%d", &timestamp);
        enqueueLinkedList(&q, timestamp);
    }
    
    // Copy queue elements to array for sorting
    while (!isQueueLinkedListEmpty(&q)) {
        timestamps[size++] = dequeueLinkedList(&q);
    }
    
    // Sort timestamps using qsort
    qsort(timestamps, size, sizeof(int), compare);
    
    // Print sorted timestamps
    for (int i = 0; i < size; i++) {
        printf("%d ", timestamps[i]);
    }
    printf("\n");
    
    return 0;
}
