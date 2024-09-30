#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 1. Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// 2.a Function to insert at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
    // CASE 1: Empty list
    if (*head == NULL) {
        *head = createNode(data);
    }
    // CASE 2: Non-empty list
    else {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
    return *head;
}

// 2.b Function to insert at the end
struct Node* insertAtEnd(struct Node** head, int data) {
    // CASE 1: Empty list
    if (*head == NULL) {
        *head = createNode(data);
    }
    // CASE 2: Non-empty list
    else {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    return *head;
}

// 2.c Function to insert at a specific position
struct Node* insertAtPosition(struct Node** head, int data, int position) {
    // CASE 1: Invalid position
    if (position < 1) {
        printf("Invalid position\n");
        return *head;
    }
    // CASE 2: Insert at beginning
    else if (position == 1) {
        return insertAtBeginning(head, data);
    }
    // CASE 3: Insert at specific position
    else {
        struct Node* newNode = createNode(data);
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return *head;
}

// 2.d Function to insert after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    // CASE 1: Invalid previous node
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    // CASE 2: Insert after the given node
    else {
        struct Node* newNode = createNode(data);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }
}

// 3.a Function to delete at the beginning
struct Node* deleteAtBeginning(struct Node** head) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Only one node
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    // CASE 3: More than one node
    else {
        struct Node* temp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        free(temp);
    }
    return *head;
}

// 3.b Function to delete at the end
struct Node* deleteAtEnd(struct Node** head) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Only one node
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    // CASE 3: More than one node
    else {
        struct Node* lastNode = (*head)->prev;
        lastNode->prev->next = *head;
        (*head)->prev = lastNode->prev;
        free(lastNode);
    }
    return *head;
}

// 3.c Function to delete at a specific position
struct Node* deleteAtPosition(struct Node** head, int position) {
    // CASE 1: Invalid position or empty list
    if (*head == NULL || position < 1) {
        printf("Invalid operation\n");
        return *head;
    }
    // CASE 2: Delete first node
    else if (position == 1) {
        return deleteAtBeginning(head);
    }
    // CASE 3: Delete at specific position
    else {
        struct Node* temp = *head;
        for (int i = 1; i < position && temp->next != *head; i++) {
            temp = temp->next;
        }
        if (temp == *head) {
            printf("Position out of range\n");
            return *head;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return *head;
}

// 3.d Function to delete a node with a specific key
struct Node* deleteNode(struct Node** head, int key) {
    // CASE 1: Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Key is in the first node
    else if ((*head)->data == key) {
        return deleteAtBeginning(head);
    }
    // CASE 3: Key is in other nodes
    else {
        struct Node* temp = (*head)->next;
        while (temp != *head && temp->data != key) {
            temp = temp->next;
        }
        if (temp == *head) {
            printf("Key not found\n");
            return *head;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return *head;
}

// 4. Function to search for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    // CASE 2: Search for the key
    else {
        struct Node* temp = head;
        do {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Key not found\n");
        return NULL;
    }
}

// 5.a Function to traverse and print the list forward
void traversalList_forward(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Print the list
    else {
        struct Node* temp = head;
        printf("Forward Traversal: ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to start)\n");
    }
}

// 5.b Function to traverse and print the list backward
void traversalList_backward(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Print the list
    else {
        struct Node* temp = head->prev;
        printf("Backward Traversal: ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        } while (temp != head->prev);
        printf("(back to start)\n");
    }
}

// 6. Function to find the length of the list
int lengthOfList(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        return 0;
    }
    // CASE 2: Count the nodes
    else {
        int count = 0;
        struct Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
}

// 7. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: Empty list or only one node
    if (*head == NULL || (*head)->next == *head) {
        return *head;
    }
    // CASE 2: Reverse the list
    else {
        struct Node* current = *head;
        struct Node* temp;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != *head);
        *head = (*head)->next;
        return *head;
    }
}

// 8. Function to find the middle node
void findMiddleNode(struct Node* head) {
    // CASE 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // CASE 2: Find the middle node
    else {
        struct Node* slow = head;
        struct Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("Middle node: %d\n", slow->data);
    }
}

// 9. Function to detect a loop
int detectLoop(struct Node* head) {
    // Note: In a circular doubly linked list, there's always a loop
    return (head != NULL);
}

// 10. Function to remove duplicates
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: Empty list or only one node
    if (head == NULL || head->next == head) {
        return head;
    }
    // CASE 2: Remove duplicates
    else {
        struct Node* current = head;
        do {
            struct Node* runner = current->next;
            while (runner != head) {
                if (runner->data == current->data) {
                    struct Node* temp = runner;
                    runner->prev->next = runner->next;
                    runner->next->prev = runner->prev;
                    runner = runner->next;
                    free(temp);
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        } while (current != head);
        return head;
    }
}

// 11. Function to swap two nodes
void swapNodes(struct Node** head, int x, int y) {
    // CASE 1: x and y are same
    if (x == y) return;

    // CASE 2: Search for x and y
    struct Node *prevX = NULL, *currX = *head;
    while (currX->data != x) {
        prevX = currX;
        currX = currX->next;
        if (currX == *head) {
            printf("x not found in the list\n");
            return;
        }
    }

    struct Node *prevY = NULL, *currY = *head;
    while (currY->data != y) {
        prevY = currY;
        currY = currY->next;
        if (currY == *head) {
            printf("y not found in the list\n");
            return;
        }
    }

    // CASE 3: If either x or y is head
    if (currX == *head) *head = currY;
    else if (currY == *head) *head = currX;

    // CASE 4: Swap the nodes
    struct Node* temp;
    temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    temp = currX->prev;
    currX->prev = currY->prev;
    currY->prev = temp;

    if (currX->next != currY) currX->next->prev = currX;
    if (currX->prev != currY) currX->prev->next = currX;
    if (currY->next != currX) currY->next->prev = currY;
    if (currY->prev != currX) currY->prev->next = currY;

    if (prevX != NULL && prevX != currY) prevX->next = currY;
    if (prevY != NULL && prevY != currX) prevY->next = currX;
}

int main() {
    struct Node* head = NULL;

    // Test insertions
    head = insertAtBeginning(&head, 1);
    head = insertAtEnd(&head, 3);
    head = insertAtPosition(&head, 2, 2);
    insertAfterNode(head->next, 4);

    printf("After insertions:\n");
    traversalList_forward(head);
    traversalList_backward(head);

    // Test deletions
    head = deleteAtBeginning(&head);
    head = deleteAtEnd(&head);
    head = deleteAtPosition(&head, 2);
    head = deleteNode(&head, 2);

    printf("After deletions:\n");
    traversalList_forward(head);

    // Test search
    struct Node* found = searchNode(head, 4);
    if (found) printf("Node with data 4 found\n");

    // Test length
    printf("Length of list: %d\n", lengthOfList(head));

    // Test reverse
    head = reverseList(&head);
    printf("After reversal:\n");
    traversalList_forward(head);

    // Test middle node
    findMiddleNode(head);

    // Test loop detection
    printf("Loop detected: %s\n", detectLoop(head) ? "Yes" : "No");

    // Test remove duplicates
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 4);
    printf("Before removing duplicates:\n");
    traversalList_forward(head);
    head = removeDuplicates(head);
    printf("After removing duplicates:\n");
    traversalList_forward(head);

    // Test swap nodes
    head = insertAtEnd(&head, 5);
    head = insertAtEnd(&head, 6);
    printf("Before swapping nodes:\n");
    traversalList_forward(head);
    swapNodes(&head, 4, 6);
    printf("After swapping nodes 4 and 6:\n");
    traversalList_forward(head);

    return 0;
}