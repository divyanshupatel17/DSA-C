1.
Problem Statement


Kristen wants to build a binary tree where each node contains only positive values. She needs a program that allows her to input the values, and then print the in-order traversal of the binary tree. If she enters -1, it indicates no node at that position. Assist her with a suitable program.


Example

Input

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Output

4 2 5 1 3 6 

Explanation

﻿

Enter the root 1

Enter left child of 1: 2

Enter left child of 2: 4

Enter left child of 4: -1

Enter right child of 4: -1

Enter right child of 2: 5

Enter left child of 5: -1

Enter right child of 5: -1

Enter right child of 1: 3

Enter left child of 3: -1

Enter right child of 3: 6

Enter left child of 6: -1

Enter right child of 6: -1

In-order traversal of binary tree is: 4 2 5 1 3 6.
Input format :

The input consists of a sequence of space-separated integers representing the nodes of a binary tree, starting with the root value.

For each non-null node, provide the left child value. If there is no left child, enter -1.

For each non-null node, provide the right child value. If there is no right child, enter -1.
Output format :

The output displays the in-order traversal of the constructed binary tree.


Refer to the sample output for formatting specifications.
Code constraints :

1 ≤ value of each node ≤ 100

1 ≤ number of nodes in the binary tree ≤ 100.
Sample test cases :
Input 1 :

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Output 1 :

4 2 5 1 3 6 

Input 2 :

1 2 3 4 -1 -1 -1 -1 -1

Output 2 :

4 3 2 1 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *buildTree(struct Node *root) {
    int data;

    // printf("Enter the data for the root node: ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    root = createNode(data);

    // printf("Enter the data for the left child of %d: ", data);
    root->left = buildTree(root->left);

    // printf("Enter the data for the right child of %d: ", data);
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    struct Node *root = NULL;

    root = buildTree(root);

    // printf("In-order traversal of the binary tree: ");
    inOrderTraversal(root);

    return 0;
}

2.

Problem Statement


A citys botanical garden is hosting a special event where they want to arrange a set of flower beds in a hierarchical structure and display them in a specific order to create a visual spiral effect.


The event organizers have a data structure representing the hierarchy of flower beds, where each node represents a flower bed, and each node can have at most two children representing sub-flower beds. They want to print the arrangement of these flower beds-level by level but in a spiral order: the first level from left to right, the next level from right to left, and so on.
Input format :

The input consists of seven space-separated integers representing the flower beds in the following order:

a - the root flower bed.

a1 - the left child of the root.

b - the right child of the root.

b1 - the left child of a1.

c - the right child of a1.

c1 - the left child of b.

d - the right child of b.
Output format :

The output is a single line of integers representing the flower beds displayed in a spiral order, separated by spaces.


Refer to the sample output for the formatting specifications.
Code constraints :

The input consists of 7 integers.

The binary tree is not empty.

1 ≤ elements ≤ 100
Sample test cases :
Input 1 :

1 2 3 7 6 5 4

Output 1 :

1 2 3 4 5 6 7 

Input 2 :

2 3 4 5 6 7 1

Output 2 :

2 3 4 1 7 6 5 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print current level in zigzag order
void printCurrentLevel(struct Node* root, int level, bool leftToRight) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        if (leftToRight) {
            printCurrentLevel(root->left, level - 1, leftToRight);
            printCurrentLevel(root->right, level - 1, leftToRight);
        } else {
            printCurrentLevel(root->right, level - 1, leftToRight);
            printCurrentLevel(root->left, level - 1, leftToRight);
        }
    }
}

// Function to calculate height of the tree
int height(struct Node* node) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Zigzag level order traversal
void zigzagLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    int h = height(root);
    bool leftToRight = false;
    
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i, leftToRight);
        leftToRight = !leftToRight; // Alternate the direction for next level
    }
}

int main() {
    int arr[7];
    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]); // Read input
    }
    
    // Create the binary tree from input
    struct Node* root = createNode(arr[0]);
    root->left = createNode(arr[1]);
    root->right = createNode(arr[2]);
    root->left->left = createNode(arr[3]);
    root->left->right = createNode(arr[4]);
    root->right->left = createNode(arr[5]);
    root->right->right = createNode(arr[6]);
    
    // Call the zigzag level order traversal
    zigzagLevelOrder(root);
    printf("\n"); // Print newline at the end
    
    return 0;
}

3.
Problem Statement


Robert needs a program to process a binary tree and calculate the sum of values of all right child nodes. The program prompts for an integer n, indicating the number of nodes in the binary tree. Following this, Robert provides n integers representing the values of these nodes.


The program constructs the binary tree from the provided values and calculates the sum of values of all right child nodes. Finally, it prints the computed sum.


Note: A right child node is a node that is positioned to the right of its parent node in the binary tree.
Input format :

The first line consists of an integer n, representing the number of nodes in the binary tree.

The second line consists of n space-separated integers representing the values of the nodes in the binary tree.
Output format :

The program displays a single integer representing the sum of values of all right child nodes in the binary tree.


Refer to the sample output for the formatting specifications.
Code constraints :

The input integers should be unique.

1 ≤ n ≤ 15

1 ≤ Node values ≤ 30
Sample test cases :
Input 1 :

5
6 7 4 3 2

Output 1 :

6

Input 2 :

8
9 3 7 10 8 6 4 2

Output 2 :

19

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

// Function to insert nodes in level order
struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        struct Node* temp = createNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int sumRightChildren(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (root->right != NULL) {
        sum += root->right->data;
    }

    sum += sumRightChildren(root->left);
    sum += sumRightChildren(root->right);

    return sum;
}

int main() {
    int n;
    scanf("%d", &n); 

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }

    struct Node* root = insertLevelOrder(arr, NULL, 0, n);

    int sum = sumRightChildren(root);

    printf("%d\n", sum);

    return 0;
}


4.
Problem Statement


Sakshi is given a binary tree and her task is to generate its zig-zag level order traversal. Help her with a suitable program.


Example 1:

Input:

Output:

1 3 2 4 5 6 7
Input format :

The first line consists of an integer n, representing the number of elements (nodes) in the binary tree.

The second line contains n space-separated integers representing the values of the nodes in level order.
Output format :

The output prints a single line containing the Zig-Zag Level Order Traversal of the Binary Tree.


Refer to the sample output for the formatting specifications.
Code constraints :

In this scenario, the given test cases will fall under the following constraints:

1 ≤ n ≤ 20

1 ≤ node values ≤ 100
Sample test cases :
Input 1 :

5
18 59 20 83 88

Output 1 :

18 20 59 83 88 

Input 2 :

7
1 2 3 4 5 6 7

Output 2 :

1 3 2 4 5 6 7 


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
    newNode->left = newNode->right = NULL;
    return newNode;
}


int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
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

void printCurrentLevel(struct Node* root, int level, bool leftToRight) {
    if (root == NULL)
        return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        if (leftToRight) {
            printCurrentLevel(root->left, level - 1, leftToRight);
            printCurrentLevel(root->right, level - 1, leftToRight);
        } else {
            printCurrentLevel(root->right, level - 1, leftToRight);
            printCurrentLevel(root->left, level - 1, leftToRight);
        }
    }
}

void zigzagLevelOrder(struct Node* root) {
    if (root == NULL)
        return;

    int h = height(root);
    bool leftToRight = true;

    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i, leftToRight);
        // printf("\n");
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = insertLevelOrder(arr, NULL, 0, n);

    zigzagLevelOrder(root);

    return 0;
}