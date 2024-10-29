1.
Problem Statement


Shreya needs a program that takes the number of nodes and a sequence of integers as input, constructs a binary tree using these integers in level order, and then prints the level order traversal of the constructed binary tree.
Input format :

The first line consists of an integer, n, representing the number of nodes in the binary tree.

The second line consists of n space-separated integers, representing the elements of the binary tree in level order.
Output format :

The output displays a single line containing the level order traversal of the constructed binary tree.


Refer to the sample output for the formatting specifications.
Code constraints :

1 ≤ n ≤ 15

1 ≤ elements ≤ 100

The binary tree is not empty.
Sample test cases :
Input 1 :

5
18 2 37 4 5

Output 1 :

18 2 37 4 5 

Input 2 :

8
15 10 20 8 12 16 25 30

Output 2 :

15 10 20 8 12 16 25 30 

Code Size : 1024 kb 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    
    struct Node** nodeArr = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        nodeArr[i] = createNode(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) nodeArr[i]->left = nodeArr[2 * i + 1];
        if (2 * i + 2 < n) nodeArr[i]->right = nodeArr[2 * i + 2];
    }
    
    struct Node* root = nodeArr[0];
    free(nodeArr);
    return root;
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[15];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printLevelOrder(root);

    return 0;
}


2.
Problem Statement


A company is designing an organizational structure to manage employees hierarchically. Each employee is represented as a node in a binary tree, where each node (positive integer) contains the employee's ID. The organization uses a level-order approach to insert employees into the tree. Each new employee is added to the next available position in the current level of the binary tree.


The system needs to:

    Insert new employee's ID positive integers into the organizational structure following a level-order traversal.
    Print out the IDs of employees in the organization using an in-order traversal.


Example


Input:

1 2 3 0

Output:

2 1 3

Explanation:

1 is the root of the Binary tree. 2 is the left child of 1, and 3 is the right child of 1. Hence the in-order traversal is 2 1 3, which follows the rule Left Root Right.
Input format :

The input consists of a sequence of positive integers, where each integer represents an employee ID.

The sequence ends with a non-positive integer (e.g., 0 or -1), which indicates the end of input.
Output format :

The output displays the sequence of integers representing the employee IDs in the in-order traversal of the binary tree.


Refer to the sample output for the formatting specifications.
Code constraints :

1 <= employee ID <= 100
Sample test cases :
Input 1 :

1 2 3 0

Output 1 :

2 1 3 

Input 2 :

1 2 3 4 5 6 7 -8

Output 2 :

4 2 5 1 6 3 7 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertLevelOrder(int arr[], int n) {
    if (n == 0) return NULL;
    
    struct Node** nodeArr = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            nodeArr[i] = createNode(arr[i]);
        } else {
            nodeArr[i] = NULL;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (nodeArr[i] != NULL) {
            if (2 * i + 1 < n) nodeArr[i]->left = nodeArr[2 * i + 1];
            if (2 * i + 2 < n) nodeArr[i]->right = nodeArr[2 * i + 2];
        }
    }
    
    struct Node* root = nodeArr[0];
    free(nodeArr);
    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left); 
    printf("%d ", root->data);     
    inOrderTraversal(root->right); 
}

int main() {
    int arr[100];  
    int n = 0;    

    while (1) {
        int id;
        scanf("%d", &id);
        if (id <= 0) break;
        arr[n++] = id;
    }

    struct Node* root = insertLevelOrder(arr, n);
    inOrderTraversal(root);

    return 0;
}


3.

Problem Statement


Seema is tasked with implementing a program that creates a binary tree using an array of integers as input. The program should then print the tree preorder traversal.


Help her with the program.
Input format :

The input consists of five integers separated by spaces. These integers represent the values of nodes in the binary tree.
Output format :

The first line of output displays "Preorder traversal:"

The second line prints space-separated integers, representing the preorder traversal values.


Refer to the sample output for the formatting specifications.
Code constraints :

1 ≤ value of nodes ≤ 1000

The input array size is fixed to 5 integers.
Sample test cases :
Input 1 :

1 2 3 4 5 

Output 1 :

Preorder traversal:
1 2 4 5 3 

Input 2 :

10 98 67 45 27

Output 2 :

Preorder traversal:
10 98 45 27 67 

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct Node* insertLevelOrder(int arr[],struct Node* root,int i,int n){
    if(i<n){
        struct Node* temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr,root->left,2*i+1,n);
        root->right = insertLevelOrder(arr,root->right,2*i+2,n);
    }
    return root;
}

void preOrderTraversal(struct Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    int arr[5];
    for(int i=0 ; i<5 ; i++){
        int data;
        scanf("%d",&arr[i]);
    }
    // struct Node* root = NULL;
    root = insertLevelOrder(arr,root,0,5);
    printf("Preorder traversal:\n");
    preOrderTraversal(root);
    return 0;
}


4.

Problem Statement


Jasmina needs a program that performs a postorder traversal on a binary tree constructed from an array of integers. The program should take an integer n as input, followed by n integers representing the elements of the array. 


It constructs a binary tree using the array elements in level order and then performs a postorder traversal on the constructed binary tree. Finally, it prints the sequence of nodes visited during the postorder traversal.
Input format :

The first line consists of an integer n, representing the number of elements in the array.

The second line consists of n space-separated integers representing the elements of the array.
Output format :

The output prints a single line containing the postorder traversal of the constructed binary tree.


Refer to the sample output for the formatting specifications.
Code constraints :

The input integers should be unique.

1 ≤ n ≤ 20

1 ≤ array elements ≤ 1500
Sample test cases :
Input 1 :

6
9 8 5 4 3 1

Output 1 :

4 3 8 1 5 9 

Input 2 :

5
1 3 5 7 9

Output 2 :

7 9 3 5 1 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = NULL;
    root = insertLevelOrder(arr, root, 0, n);
    postOrderTraversal(root);
    printf("\n");

    return 0;
}


