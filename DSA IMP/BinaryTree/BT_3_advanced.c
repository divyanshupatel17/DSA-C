/*
Advanced Binary Tree Operations:
35. Convert Binary Tree to Doubly Linked List
36. Serialize Binary Tree
37. Deserialize Binary Tree
38. Check Full Binary Tree
39. Check Perfect Binary Tree
40. Convert to Sum Tree
41. Build Tree from Traversals
42. Check Subtree
43. Find All Paths from Root to Leaf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for doubly linked list node
struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function declarations
void convertToDoublyLinkedList(struct Node* root, struct DLLNode** head);
char* serializeTree(struct Node* root);
struct Node* deserializeTree(char* str);
bool checkFullBinaryTree(struct Node* root);
bool checkPerfectBinaryTree(struct Node* root);
void convertToSumTree(struct Node* root);
struct Node* buildTreeFromTraversals(int* inorder, int* preorder, int size);
bool checkSubtree(struct Node* T, struct Node* S);
void findAllPathsRootToLeaf(struct Node* root);

// Helper function declarations
void convertToDLLHelper(struct Node* root, struct DLLNode** head);
void serializeTreeHelper(struct Node* root, char* str, int* index);
struct Node* deserializeTreeHelper(char* str, int* index);
int getHeight(struct Node* root);
int convertToSumTreeHelper(struct Node* root);
struct Node* buildTreeHelper(int* inorder, int* preorder, int inStart, int inEnd, int* preIndex, int size);
int search(int* arr, int start, int end, int value);
void printArray(int path[], int pathLen);
void findPathsHelper(struct Node* root, int path[], int pathLen);
bool identicalTrees(struct Node* a, struct Node* b);
bool isPerfectBinaryTreeHelper(struct Node* root, int level, int* leafLevel);
void printDLL(struct DLLNode* head);
void inorderTraversal(struct Node* root);

// 35. Convert Binary Tree to Doubly Linked List
void convertToDoublyLinkedList(struct Node* root, struct DLLNode** head) {
    /* Case 1: Empty tree */
    if (root == NULL) return;
    
    static struct DLLNode* prev = NULL;
    
    /* Case 2: Process left subtree */
    convertToDoublyLinkedList(root->left, head);
    
    /* Case 3: Process current node */
    struct DLLNode* curr = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    curr->data = root->data;
    curr->next = NULL;
    
    if (prev == NULL) {
        *head = curr;  // First node
        curr->prev = NULL;
    } else {
        curr->prev = prev;
        prev->next = curr;
    }
    prev = curr;
    
    /* Case 4: Process right subtree */
    convertToDoublyLinkedList(root->right, head);
}

// Helper function to print Doubly Linked List
void printDLL(struct DLLNode* head) {
    struct DLLNode* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 36. Serialize Binary Tree
char* serializeTree(struct Node* root) {
    char* str = (char*)malloc(1000 * sizeof(char));
    int index = 0;
    
    /* Case 1: Empty tree */
    if (root == NULL) {
        str[index] = '\0';
        return str;
    }
    
    /* Case 2: Non-empty tree */
    serializeTreeHelper(root, str, &index);
    str[index-1] = '\0';  // Remove last space
    return str;
}

// Helper function for serializeTree
void serializeTreeHelper(struct Node* root, char* str, int* index) {
    /* Case 1: Null node */
    if (root == NULL) {
        *index += sprintf(&str[*index], "N ");
        return;
    }
    
    /* Case 2: Valid node */
    *index += sprintf(&str[*index], "%d ", root->data);
    serializeTreeHelper(root->left, str, index);
    serializeTreeHelper(root->right, str, index);
}

// 37. Deserialize Binary Tree
struct Node* deserializeTree(char* str) {
    int index = 0;
    
    /* Case 1: Empty string */
    if (strlen(str) == 0) return NULL;
    
    /* Case 2: Non-empty string */
    return deserializeTreeHelper(str, &index);
}

// Helper function for deserializeTree
struct Node* deserializeTreeHelper(char* str, int* index) {
    /* Case 1: Null node */
    if (str[*index] == 'N') {
        *index += 2;  // Skip 'N' and space
        return NULL;
    }
    
    /* Case 2: Valid node */
    int num = 0;
    while (str[*index] != ' ' && str[*index] != '\0') {
        num = num * 10 + (str[*index] - '0');
        (*index)++;
    }
    (*index)++;  // Skip space
    
    struct Node* root = createNode(num);
    root->left = deserializeTreeHelper(str, index);
    root->right = deserializeTreeHelper(str, index);
    
    return root;
}

// Helper function for inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 38. Check Full Binary Tree
bool checkFullBinaryTree(struct Node* root) {
    /* Case 1: Empty tree */
    if (root == NULL) return true;
    
    /* Case 2: Leaf node */
    if (root->left == NULL && root->right == NULL) return true;
    
    /* Case 3: Internal node with both children */
    if (root->left && root->right)
        return checkFullBinaryTree(root->left) && checkFullBinaryTree(root->right);
    
    /* Case 4: Node with only one child */
    return false;
}

// 39. Check Perfect Binary Tree
bool checkPerfectBinaryTree(struct Node* root) {
    int leafLevel = -1;
    return isPerfectBinaryTreeHelper(root, 0, &leafLevel);
}

// Helper function for checkPerfectBinaryTree
bool isPerfectBinaryTreeHelper(struct Node* root, int level, int* leafLevel) {
    /* Case 1: Empty tree */
    if (root == NULL) return true;
    
    /* Case 2: Leaf node */
    if (root->left == NULL && root->right == NULL) {
        if (*leafLevel == -1)
            *leafLevel = level;
        return level == *leafLevel;
    }
    
    /* Case 3: Internal node with one child */
    if (root->left == NULL || root->right == NULL)
        return false;
    
    /* Case 4: Internal node with both children */
    return isPerfectBinaryTreeHelper(root->left, level + 1, leafLevel) &&
           isPerfectBinaryTreeHelper(root->right, level + 1, leafLevel);
}

// 40. Convert to Sum Tree
void convertToSumTree(struct Node* root) {
    convertToSumTreeHelper(root);
}

// Helper function for convertToSumTree
int convertToSumTreeHelper(struct Node* root) {
    /* Case 1: Empty node */
    if (root == NULL) return 0;
    
    /* Case 2: Leaf node */
    int oldValue = root->data;
    int leftSum = convertToSumTreeHelper(root->left);
    int rightSum = convertToSumTreeHelper(root->right);
    
    /* Case 3: Update node value */
    root->data = leftSum + rightSum;
    
    return root->data + oldValue;
}

// 41. Build Tree from Traversals
struct Node* buildTreeFromTraversals(int* inorder, int* preorder, int size) {
    int preIndex = 0;
    return buildTreeHelper(inorder, preorder, 0, size - 1, &preIndex, size);
}

// Helper function for buildTreeFromTraversals
struct Node* buildTreeHelper(int* inorder, int* preorder, int inStart, int inEnd, int* preIndex, int size) {
    /* Case 1: Invalid indices */
    if (inStart > inEnd) return NULL;
    
    /* Case 2: Create node */
    struct Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;
    
    /* Case 3: Leaf node */
    if (inStart == inEnd) return node;
    
    /* Case 4: Find partition index and build subtrees */
    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex, size);
    node->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex, size);
    
    return node;
}

// Helper function for buildTreeFromTraversals
int search(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// 42. Check Subtree
bool checkSubtree(struct Node* T, struct Node* S) {
    /* Case 1: Subtree is NULL */
    if (S == NULL) return true;
    
    /* Case 2: Main tree is NULL */
    if (T == NULL) return false;
    
    /* Case 3: Check if trees are identical */
    if (identicalTrees(T, S)) return true;
    
    /* Case 4: Recursively check left and right subtrees */
    return checkSubtree(T->left, S) || checkSubtree(T->right, S);
}

// Helper function for checkSubtree
bool identicalTrees(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    
    return (a->data == b->data) &&
           identicalTrees(a->left, b->left) &&
           identicalTrees(a->right, b->right);
}

// 43. Find All Paths Root to Leaf
void findAllPathsRootToLeaf(struct Node* root) {
    int path[1000];
    findPathsHelper(root, path, 0);
}

// Helper function for findAllPathsRootToLeaf
void findPathsHelper(struct Node* root, int path[], int pathLen) {
    /* Case 1: Empty node */
    if (root == NULL) return;
    
    /* Case 2: Add current node to path */
    path[pathLen] = root->data;
    pathLen++;
    
    /* Case 3: Leaf node - print path */
    if (root->left == NULL && root->right == NULL) {
        printArray(path, pathLen);
    } else {
        /* Case 4: Internal node - recurse */
        findPathsHelper(root->left, path, pathLen);
        findPathsHelper(root->right, path, pathLen);
    }
}

// Helper function for findAllPathsRootToLeaf
void printArray(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Original Tree structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    / \\\n");
    printf("   4   5\n\n");
    
    /* Test 35: Convert to Doubly Linked List
     * Expected Output: 4 2 5 1 3
     * Original Tree:
     *       1
     *      / \
     *     2   3
     *    / \
     *   4   5
     */
    struct DLLNode* head = NULL;
    convertToDoublyLinkedList(root, &head);
    printDLL(head);
    
    /* Test 36: Serialize Tree
     * Expected Output: 1 2 4 N N 5 N N 3 N N
     */
    char* serialized = serializeTree(root);
    printf("Serialized tree: %s\n", serialized);
    
    /* Test 37: Deserialize Tree
     * Expected Output: Inorder traversal: 4 2 5 1 3
     */
    struct Node* deserializedRoot = deserializeTree(serialized);
    printf("Deserialized tree inorder traversal: ");
    inorderTraversal(deserializedRoot);
    printf("\n");
    
    /* Test 38: Check Full Binary Tree
     * Expected Output: false
     */
    bool isFull = checkFullBinaryTree(root);
    printf("Is full binary tree: %s\n", isFull ? "true" : "false");
    
    /* Test 39: Check Perfect Binary Tree
     * Expected Output: false
     */
    bool isPerfect = checkPerfectBinaryTree(root);
    printf("Is perfect binary tree: %s\n", isPerfect ? "true" : "false");
    
    /* Test 40: Convert to Sum Tree
     * Expected Output:
     *       15
     *      /  \
     *     9    0
     *    / \
     *   0   0
     */
    struct Node* sumTreeRoot = createNode(1);
    sumTreeRoot->left = createNode(2);
    sumTreeRoot->right = createNode(3);
    sumTreeRoot->left->left = createNode(4);
    sumTreeRoot->left->right = createNode(5);
    
    convertToSumTree(sumTreeRoot);
    printf("Sum tree inorder traversal: ");
    inorderTraversal(sumTreeRoot);
    printf("\n");
    
    /* Test 41: Build Tree from Traversals
     * Expected Output: Same structure as original tree
     */
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    struct Node* builtTree = buildTreeFromTraversals(inorder, preorder, 5);
    printf("Built tree inorder traversal: ");
    inorderTraversal(builtTree);
    printf("\n");
    
    /* Test 42: Check Subtree
     * Expected Output: true
     * Subtree structure:
     *     2
     *    / \
     *   4   5
     */
    struct Node* subtree = createNode(2);
    subtree->left = createNode(4);
    subtree->right = createNode(5);
    bool isSubtree = checkSubtree(root, subtree);
    printf("Is subtree: %s\n", isSubtree ? "true" : "false");
    
    /* Test 43: Find All Paths Root to Leaf
     * Expected Output:
     * 1 2 4
     * 1 2 5
     * 1 3
     * Tree structure:
     *       1
     *      / \
     *     2   3
     *    / \
     *   4   5
     */
    printf("All paths from root to leaf:\n");
    findAllPathsRootToLeaf(root);
    
    // Free allocated memory
    free(serialized);
    
    // Note: In a real application, you should also free all nodes
    // in the binary trees and the doubly linked list
    
    return 0;
}