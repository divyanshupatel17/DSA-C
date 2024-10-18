/*
Complete Topics List:
1. Binary Tree Node Structure
2. Basic Operations:
   11. Level Order Traversal - Traverse tree level by level showing each level
   12. Count Total Nodes - Get total number of nodes
   13. Count Leaf Nodes - Count nodes without children
   14. Count Internal Nodes - Count nodes with at least one child
   15. Check if BST - Validate Binary Search Tree
   16. Find Predecessor - Get in-order predecessor
   17. Find Successor - Get in-order successor
   18. Find Depth - Get distance from root to specific node
   19. Print All Paths - Show all root-to-leaf paths
   20. Mirror Tree - Create mirror image of tree
   21. Check Identical Trees - Compare two trees
   22. Print Boundary Nodes - Print boundary in counterclockwise
3. Helper Functions for various operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// All function declarations
void levelOrderTraversal(struct Node* root);
int countNodes(struct Node* root);
int countLeaves(struct Node* root);
int countInternalNodes(struct Node* root);
bool isBST(struct Node* root);
struct Node* findPredecessor(struct Node* root, struct Node* node);
struct Node* findSuccessor(struct Node* root, struct Node* node);
int findDepth(struct Node* root, int target);
void printPaths(struct Node* root);
void mirrorTree(struct Node* root);
bool checkIdenticalTrees(struct Node* root1, struct Node* root2);
void printBoundaryNodes(struct Node* root);

// Helper function declarations
int height(struct Node* node);
void printCurrentLevel(struct Node* root, int level);
void printPathsRecursive(struct Node* root, int path[], int pathLen);
bool isBSTUtil(struct Node* root, int min, int max);
void printLeftBoundary(struct Node* root);
void printLeaves(struct Node* root);
void printRightBoundary(struct Node* root);
struct Node* findMin(struct Node* node);
struct Node* findMax(struct Node* node);

// Helper function for 11. levelOrderTraversal
int height(struct Node* node) {
    // Case 1: Empty tree
    if (node == NULL) {
        return 0;
    }
    // Case 2: Compute height
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

// Helper function for 11. levelOrderTraversal
void printCurrentLevel(struct Node* root, int level) {
    // Case 1: Empty tree
    if (root == NULL) {
        return;
    }
    // Case 2: Current level
    else if (level == 1) {
        printf("%d ", root->data);
    }
    // Case 3: Other levels
    else {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// 11. Level Order Traversal - Traverse the tree level by level
void levelOrderTraversal(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return;
    }
    // Case 2: Non-empty tree
    else {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printf("Level %d: ", i);
            printCurrentLevel(root, i);
            printf("\n");
        }
    }
}

// 12. Count Total Nodes
int countNodes(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return 0;
    
    // Case 2: Count current node and recursively count children
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 13. Count Leaf Nodes
int countLeaves(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return 0;
    
    // Case 2: Leaf node
    if (root->left == NULL && root->right == NULL) return 1;
    
    // Case 3: Internal node
    return countLeaves(root->left) + countLeaves(root->right);
}

// 14. Count Internal Nodes
int countInternalNodes(struct Node* root) {
    // Case 1: Empty tree or leaf node
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    // Case 2: Internal node
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// 15. Check if BST
bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper for 15: isBST
bool isBSTUtil(struct Node* root, int min, int max) {
    // Case 1: Empty tree is BST
    if (root == NULL) return true;
    
    // Case 2: Node value out of valid range
    if (root->data < min || root->data > max) return false;
    
    // Case 3: Check recursively for left and right subtrees
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

// 16. Find Predecessor
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    // Case 1: Empty tree or node
    if (root == NULL || node == NULL) return NULL;
    
    // Case 2: Left subtree exists, find max in left subtree
    if (node->left != NULL) {
        return findMax(node->left);
    }
    
    // Case 3: No left subtree, find ancestor where node is in right subtree
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (node->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return predecessor;
}

// 17. Find Successor
struct Node* findSuccessor(struct Node* root, struct Node* node) {
    // Case 1: Empty tree or node
    if (root == NULL || node == NULL) return NULL;
    
    // Case 2: Right subtree exists, find min in right subtree
    if (node->right != NULL) {
        return findMin(node->right);
    }
    
    // Case 3: No right subtree, find ancestor where node is in left subtree
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data) {
            root = root->right;
        }
        else break;
    }
    return successor;
}

// 18. Find Depth
int findDepth(struct Node* root, int target) {
    // Case 1: Empty tree
    if (root == NULL) return -1;
    
    // Case 2: Node found
    if (root->data == target) return 0;
    
    // Case 3: Search in left and right subtrees
    int leftDepth = findDepth(root->left, target);
    if (leftDepth >= 0) return leftDepth + 1;
    
    int rightDepth = findDepth(root->right, target);
    if (rightDepth >= 0) return rightDepth + 1;
    
    return -1;
}

// 19. Print All Paths
void printPaths(struct Node* root) {
    int path[1000];
    printPathsRecursive(root, path, 0);
}

// Helper for 19: Print Paths Recursive
void printPathsRecursive(struct Node* root, int path[], int pathLen) {
    // Case 1: Empty node
    if (root == NULL) return;
    
    // Case 2: Add current node to path
    path[pathLen] = root->data;
    pathLen++;
    
    // Case 3: Leaf node - print path
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    
    // Case 4: Recurse for left and right subtrees
    printPathsRecursive(root->left, path, pathLen);
    printPathsRecursive(root->right, path, pathLen);
}

// 20. Mirror Tree
void mirrorTree(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) return;
    
    // Case 2: Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Case 3: Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// 21. Check Identical Trees
bool checkIdenticalTrees(struct Node* root1, struct Node* root2) {
    // Case 1: Both empty
    if (root1 == NULL && root2 == NULL) return true;
    
    // Case 2: One empty, one not
    if (root1 == NULL || root2 == NULL) return false;
    
    // Case 3: Compare current nodes and recursively compare subtrees
    return (root1->data == root2->data &&
            checkIdenticalTrees(root1->left, root2->left) &&
            checkIdenticalTrees(root1->right, root2->right));
}

// 22. Print Boundary Nodes
void printBoundaryNodes(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    
    // Case 1: Print left boundary
    printLeftBoundary(root->left);
    
    // Case 2: Print leaves
    printLeaves(root->left);
    printLeaves(root->right);
    
    // Case 3: Print right boundary
    printRightBoundary(root->right);
}

// Helper functions for 22: Print Boundary Nodes
void printLeftBoundary(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    printf("%d ", root->data);
    if (root->left != NULL)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

void printLeaves(struct Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printRightBoundary(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    if (root->right != NULL)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);
    printf("%d ", root->data);
}

// Helper functions for finding predecessor/successor
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}


int main() {
    /* Creating a sample binary tree:
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // 11. Testing Level Order Traversal
    printf("\n11. Level Order Traversal:\n");
    levelOrderTraversal(root);
    /* Expected output:
    Level 1: 1
    Level 2: 2 3
    Level 3: 4 5 6 7
    */
    
    // 12. Testing Count Nodes
    printf("\n12. Total nodes: %d", countNodes(root));
    /* Expected output: 7 */
    
    // 13. Testing Count Leaves
    printf("\n13. Leaf nodes: %d", countLeaves(root));
    /* Expected output: 4 */
    
    // 14. Testing Count Internal Nodes
    printf("\n14. Internal nodes: %d", countInternalNodes(root));
    /* Expected output: 3 */
    
    // 15. Testing isBST
    printf("\n15. Is BST: %s", isBST(root) ? "Yes" : "No");
    /* Expected output: No */
    
    // 18. Testing Find Depth
    printf("\n18. Depth of node 5: %d", findDepth(root, 5));
    /* Expected output: 2 */
    
    // 19. Testing Print Paths
    printf("\n19. All root-to-leaf paths:\n");
    printPaths(root);
    /* Expected output:
    1 2 4
    1 2 5
    1 3 6
    1 3 7
    */
    
    // 20. Testing Mirror Tree
    printf("\n20. Mirror Tree - Level Order before mirroring: ");
    levelOrderTraversal(root);
    mirrorTree(root);
    printf("Level Order after mirroring: ");
    levelOrderTraversal(root);
    /* Expected output before: 1 2 3 4 5 6 7
       Expected output after:  1 3 2 7 6 5 4 */
    
    // 21. Testing Identical Trees
    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    printf("\n21. Trees identical: %s", 
           checkIdenticalTrees(root, root2) ? "Yes" : "No");
    /* Expected output: No */
    
    // 22. Testing Print Boundary Nodes
    printf("\n22. Boundary nodes: ");
    printBoundaryNodes(root);
    /* Expected output depends on current tree state after mirroring */
    
    return 0;
}