1. 
Problem Statement



John is learning about Binary Search Trees (BST) in his computer science class. He wants to create a program that allows users to delete a node with a given value from a BST and print the remaining nodes.



Implement a function to help him delete a node with a given value from a BST.

Input format :
The first line of input consists of an integer N, representing the number of nodes in the BST.

The second line consists of N space-separated integers, representing the values of the BST nodes.

The third line consists of an integer V, which is the value to delete from the BST.

Output format :
The output prints the space-separated values in the BST in an in-order traversal, after the deletion of the specified value.

If the specified value is not available in the tree, print the given input values in-order traversal.



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases will fall under the following constraints:

1 ≤ N ≤ 10

1 ≤ node values ≤ 100

1 ≤ V ≤ 100

The input values are unique integers.

Sample test cases :
Input 1 :
5
10 5 15 2 7
15
Output 1 :
2 5 7 10 
Input 2 :
7
50 30 70 20 40 60 80
50
Output 2 :
20 30 40 60 70 80 
Input 3 :
3
4 7 6
8
Output 3 :
4 6 7 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int data) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorderT(struct Node* root) {
    if (root != NULL) {
        inorderT(root->left);
        printf("%d ", root->data);
        inorderT(root->right);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, v;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int ele;
        scanf("%d", &ele);
        root = insert(root, ele);
    }

    scanf("%d", &v);

    root = deleteNode(root, v);

    inorderT(root);

    return 0;
}



2.

Problem Statement



Liam needs to build a Binary Search Tree (BST) from user input and determine the in-order successor of a specific node. Write a program to help Liam construct the BST, then find and display the in-order successor of the target node. 



Assist Liam with a suitable program.





In the above diagram, the in-order successor of 8 is 10, the in-order successor of 10 is 12 and the in-order successor of 14 is 20.

Input format :
The first line of input consists of an integer n representing the number of nodes in the binary search tree.

The second line of input consists of n integers representing the values of the nodes in the binary search tree.

The third line of input consists of an integer T, representing the value for which to find the in-order successor.

Output format :
The output prints "In-order Successor of T is X" where X is an integer representing the in-order successor of the node with the target (T) value.

If an in-order successor doesnt exist, print "In-order Successor doesn't exist".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

3 ≤ n ≤ 20

1 ≤ node values ≤ 1000

1 ≤ T ≤ 1000

Sample test cases :
Input 1 :
7
20 8 22 4 12 10 14
8
Output 1 :
In-order Successor of 8 is 10
Input 2 :
7
20 8 22 4 12 10 14
14
Output 2 :
In-order Successor of 14 is 20
Input 3 :
5
10 5 15 3 7
15
Output 3 :
In-order Successor doesnt exist

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int data) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* findNode(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return findNode(root->left, key);
    return findNode(root->right, key);
}

struct Node* findInorderSuccessor(struct Node* root, struct Node* target) {
    if (target->right != NULL) return findMin(target->right);
    struct Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return successor;
}

int main() {
    struct Node* root = NULL;
    int n, T;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int ele;
        scanf("%d", &ele);
        root = insert(root, ele);
    }
    
    scanf("%d", &T);
    struct Node* target = findNode(root, T);
    
    if (target == NULL) {
        printf("In-order Successor doesn't exist");
        return 0;
    }
    
    struct Node* successor = findInorderSuccessor(root, target);
    
    if (successor != NULL)
        printf("In-order Successor of %d is %d", T, successor->data);
    else
        printf("In-order Successor doesn't exist");
    
    return 0;
}


// EXTRA 1 : Inorder Predecessor 
struct Node* findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

struct Node* findInorderPredecessor(struct Node* root, struct Node* target) {
    if (target->left != NULL) return findMax(target->left); // Case 1: Predecessor is the rightmost node in the left subtree
    
    struct Node* predecessor = NULL;
    
    while (root != NULL) {
        if (target->data > root->data) { // Move right and update predecessor
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left; // Move left, no update to predecessor
        } else {
            break;
        }
    }
    
    return predecessor;
}

// EXTRA 2 : Preorder Successor
struct Node* findPreorderSuccessor(struct Node* root, struct Node* target) {
    if (target->left != NULL) return target->left; // Case 1: Left child exists, it's the pre-order successor
    if (target->right != NULL) return target->right; // Case 2: No left child but right child exists
    
    struct Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else {
            // If the target node doesn't have left or right child, we find the first ancestor
            // whose left subtree contains this node
            while (root != NULL && (root->right == NULL || target->data > root->right->data)) {
                root = root->parent;
            }
            if (root != NULL) successor = root;
            break;
        }
    }
    return successor;
}



// EXTRA 3 : Postorder Successor
struct Node* findPostorderSuccessor(struct Node* root, struct Node* target) {
    struct Node* successor = NULL;
    
    // Case 1: If the target is the rightmost node, there's no successor
    if (root == NULL || target == NULL) return NULL;
    
    struct Node* parent = NULL;
    struct Node* curr = root;
    
    // Traverse to find the node and its parent
    while (curr != NULL && curr->data != target->data) {
        parent = curr;
        if (target->data < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    
    // If we reached the target node
    if (curr != NULL) {
        // If the node has no children, successor is its parent
        if (parent != NULL) successor = parent;
        
        // If it's a left child, successor is its right sibling (if exists)
        if (parent != NULL && parent->left == target && parent->right != NULL) successor = parent->right;
    }
    
    return successor;
}



3.
Problem Statement



Rao wants to analyze the frequency of words in a collection of text. He plans to implement a program using a Binary Search Tree (BST) to efficiently store and manage the words along with their frequencies.



The program should read words from the input until the word "end" is encountered, construct the BST, and then output the words in alphabetical order along with their frequencies. Additionally, Rao wants to find and display the most frequent word in the text.

Input format :
The input consists of a series of words separated by spaces. Each word contains only alphabetical characters and has a maximum length of 99 characters.

The input terminates when the word "end" is entered.

Output format :
The output displays all unique words entered by the user in alphabetical order, along with their frequencies in the format

"Words in alphabetical order:"

word 1 (n times)

word 2 (n times)

...

word n (n times)"



The last line of output displays the identification and the most frequent word along with its frequency in the format:

"The most frequent word: [word] (n times).



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases will fall under the following constraints:

The length of each word is ≤ 99 characters

Sample test cases :
Input 1 :
apple banana cherry cherry apple apple
end
Output 1 :
Words in alphabetical order:
apple (3 times)
banana (1 times)
cherry (2 times)
The most frequent word: apple (3 times)
Input 2 :
programming code debugging programming testing
end
Output 2 :
Words in alphabetical order:
code (1 times)
debugging (1 times)
programming (2 times)
testing (1 times)
The most frequent word: programming (2 times)
Note :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[100];
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* word) {
    if (root == NULL) return createNode(word);
    int cmp = strcmp(word, root->word);
    if (cmp == 0) root->count++;
    else if (cmp < 0) root->left = insert(root->left, word);
    else root->right = insert(root->right, word);
    return root;
}

void inorder(Node* root, Node** mostFreq) {
    if (root != NULL) {
        inorder(root->left, mostFreq);
        printf("%s (%d times)\n", root->word, root->count);
        if (*mostFreq == NULL || root->count > (*mostFreq)->count)
            *mostFreq = root;
        inorder(root->right, mostFreq);
    }
}

int main() {
    Node* root = NULL;
    char word[100];
    Node* mostFreq = NULL;
    
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "end") == 0) break;
        root = insert(root, word);
    }

    printf("Words in alphabetical order:\n");
    inorder(root, &mostFreq);
    if (mostFreq != NULL) {
        printf("The most frequent word: %s (%d times)\n", mostFreq->word, mostFreq->count);
    }

    return 0;
}

4.


Problem Statement



﻿Emma is working on a navigation system that needs to find the distance between two nodes in a Binary Search Tree (BST). Implement a function to help Emma calculate the distance between two nodes.



Example



Input:

7

20 10 30 5 15 25 35

5 35

Output:

4

Explanation:

The BST for the nodes is 



The nodes for which we need to find the distance are 5 and 35. 

The path from 5 to 35 is, from 5 to 10 (1 step), from 10 to 20 (1 step), from 20 to 30 (1 step), from 30 to 35 (1 step).

Thus, the total distance is 4 steps.

Input format :
The first line contains an integer n, representing the number of nodes to be inserted into the BST.

The second line consists of n space-separated integers, representing the values to be inserted.

The third line consists of two integers n1 and n2, representing the values of the two nodes.

Output format :
The output prints the distance between the two given nodes.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 25

1 ≤ tree elements, n1, n2 ≤ 100

Sample test cases :
Input 1 :
7
20 10 30 5 15 25 35
5 35
Output 1 :
4
Input 2 :
5
56 64 8 9 43
8 43
Output 2 :
2

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node in the BST
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data); // Base case: create a new node if root is NULL
    if (data < root->data) root->left = insert(root->left, data); // Recur to the left subtree
    else root->right = insert(root->right, data); // Recur to the right subtree
    return root;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes n1 and n2
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL; // Base case: If root is NULL, return NULL
    
    // If both n1 and n2 are smaller than root, LCA lies in the left subtree
    if (root->data > n1 && root->data > n2) return findLCA(root->left, n1, n2);
    
    // If both n1 and n2 are greater than root, LCA lies in the right subtree
    if (root->data < n1 && root->data < n2) return findLCA(root->right, n1, n2);
    
    // Otherwise, root is the LCA of n1 and n2
    return root;
}

// Function to find the distance from root to a given node value
int findDistanceFromRoot(Node* root, int value) {
    if (root->data == value) return 0; // Base case: if the node is found, return 0
    
    // If value is smaller, move to the left subtree and increment the distance by 1
    if (value < root->data) return 1 + findDistanceFromRoot(root->left, value);
    
    // If value is larger, move to the right subtree and increment the distance by 1
    return 1 + findDistanceFromRoot(root->right, value);
}

// Function to calculate the distance between two nodes in the BST
int findDistanceBetweenNodes(Node* root, int n1, int n2) {
    // Find the Lowest Common Ancestor (LCA) of n1 and n2
    Node* lca = findLCA(root, n1, n2);
    
    // Find the distance from the LCA to n1 and n2
    int d1 = findDistanceFromRoot(lca, n1);
    int d2 = findDistanceFromRoot(lca, n2);
    
    // Return the total distance as the sum of distances from the LCA to n1 and n2
    return d1 + d2;
}

int main() {
    int n, i, n1, n2, val;
    Node* root = NULL;
    
    // Read the number of nodes to be inserted into the BST
    scanf("%d", &n);
    
    // Insert each node into the BST
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    // Read the two nodes whose distance is to be found
    scanf("%d %d", &n1, &n2);
    
    // Find and print the distance between the two nodes
    printf("%d\n", findDistanceBetweenNodes(root, n1, n2));
    
    return 0;
}
