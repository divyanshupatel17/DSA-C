/*
Topics list:
1. Node creation
2. Insertion
3. Searching
4. Tree traversals (Inorder, Preorder, Postorder)
5. Finding minimum and maximum values
6. Node deletion
7. Tree height calculation
*/



#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insert(struct Node* root, int value);
struct Node* search(struct Node* root, int value);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* findMin(struct Node* root);
struct Node* findMax(struct Node* root);
struct Node* deleteNode(struct Node* root, int value);
int height(struct Node* root);

// 1. createNode: Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. insert: Insert a new node into the binary search tree
struct Node* insert(struct Node* root, int value) {
    // Case 1: If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }
    
    // Case 2: If the value is less than the root, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Case 3: If the value is greater than or equal to the root, insert in the right subtree
    else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 3. search: Search for a value in the binary search tree
struct Node* search(struct Node* root, int value) {
    // Case 1: Root is NULL or the value is found at the root
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Case 2: Value is less than the root, search in the left subtree
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // Case 3: Value is greater than the root, search in the right subtree
    return search(root->right, value);
}

// 4. inorderTraversal: Perform inorder traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 5. preorderTraversal: Perform preorder traversal of the binary tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 6. postorderTraversal: Perform postorder traversal of the binary tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// 7. findMin: Find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return NULL;
    }
    
    // Case 2: Leftmost node (minimum)
    if (root->left == NULL) {
        return root;
    }
    
    // Case 3: Recurse to the left
    return findMin(root->left);
}

// 8. findMax: Find the maximum value in the binary search tree
struct Node* findMax(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return NULL;
    }
    
    // Case 2: Rightmost node (maximum)
    if (root->right == NULL) {
        return root;
    }
    
    // Case 3: Recurse to the right
    return findMax(root->right);
}

// 9. deleteNode: Delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    // Case 1: Empty tree
    if (root == NULL) {
        return root;
    }
    
    // Case 2: Value to be deleted is in the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // Case 3: Value to be deleted is in the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // Case 4: Value to be deleted is found
    else {
        // Case 4a: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 4b: Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 10. height: Calculate the height of the binary tree
int height(struct Node* root) {
    // Case 1: Empty tree
    if (root == NULL) {
        return -1;
    }
    
    // Case 2: Leaf node
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    
    // Case 3: Internal node
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


int main() {
    struct Node* root = NULL;
    
    // 2. Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    /* Expected tree after insertions:
           50
         /    \
        30    70
       / \    / \
      20 40  60 80
    */

    // 4. Inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    /* Expected output: 20 30 40 50 60 70 80 */

    // 5. Preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    /* Expected output: 50 30 20 40 70 60 80 */

    // 6. Postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    /* Expected output: 20 40 30 60 80 70 50 */

    // 3. Search
    struct Node* searchResult = search(root, 40);
    printf("Search for 40: %s\n", searchResult ? "Found" : "Not found");
    /* Expected output: Search for 40: Found */

    // 7. Find minimum
    struct Node* minNode = findMin(root);
    printf("Minimum value: %d\n", minNode->data);
    /* Expected output: Minimum value: 20 */

    // 8. Find maximum
    struct Node* maxNode = findMax(root);
    printf("Maximum value: %d\n", maxNode->data);
    /* Expected output: Maximum value: 80 */

    // 10. Height of the tree
    printf("Height of the tree: %d\n", height(root));
    /* Expected output: Height of the tree: 2 */

    // 9. Delete node
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");
    /* Expected output: 20 40 50 60 70 80 */

    /* Expected tree after deletion of 30:
           50
         /    \
        40    70
       /     / \
      20    60 80
    */


    // Free the allocated memory
    freeTree(root);
    return 0;
}