#include <stdio.h>
#include <stdlib.h>

/* 
   Singly Linked List Operations:

   1. **createNode(int data)**: 
      - Creates a new node with given data, next pointer set to NULL.

   2. **insert**:
     - **insertAtBeginning(struct Node** head, int data)**: Inserts a node at the beginning.
     - **insertAtEnd(struct Node** head, int data)**: Inserts a node at the end.
     - **insertAtPosition(struct Node** head, int data, int pos)**: Inserts a node at a specific position.
     - **insertAfterNode(struct Node* prevNode, int data)**: Inserts a node after a given node.
     - **insertInPlace(struct Node** head, int oldData, int newData)**: Inserts new data in place of old data.

   3. **delete**:
     - **deleteAtBeginning(struct Node** head)**: Deletes the node at the beginning.
     - **deleteAtEnd(struct Node** head)**: Deletes the node at the end.
     - **deleteAtPosition(struct Node** head, int pos)**: Deletes the node at a specific position.
     - **deleteNode(struct Node** head, int key)**: Deletes a node with the specified key.

   4. **searchNode(struct Node* head, int key)**: Searches for a node with a specific key.

   5. **traverseList(struct Node* head)**: Prints all nodes in the list from head to end.

   6. **lengthOfList(struct Node* head)**: Returns the number of nodes in the list.

   7. **reverseList(struct Node** head)**: Reverses the list.

   8. **findMiddleNode(struct Node* head)**: Finds and prints the middle node.

   9. **detectLoop(struct Node* head)**: Detects if there is a loop in the list.

   10. **removeDuplicates(struct Node* head)**: Removes duplicate nodes from the list.
*/

// Definition of a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// 1. **createNode**: Creates a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    } else {
        printf("Memory allocation failed\n");
    }
    return newNode;
}

// 2. **insertAtBeginning**: Inserts a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        printf("Failed to insert at beginning\n");
    }
}

// 2. **insertAtEnd**: Inserts a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        if (newNode != NULL) {
            *head = newNode;
        }
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (newNode != NULL) {
            temp->next = newNode;
        } else {
            printf("Failed to insert at end\n");
        }
    }
}

// 2. **insertAtPosition**: Inserts a node at a specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (pos == 0) {
            insertAtBeginning(head, data);
        } else {
            struct Node* temp = *head;
            for (int i = 1; i < pos && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp != NULL) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                printf("Position out of bounds\n");
            }
        }
    } else {
        printf("Failed to insert at position\n");
    }
}

// 2. **insertAfterNode**: Inserts a node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
    } else {
        struct Node* newNode = createNode(data);
        if (newNode != NULL) {
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        } else {
            printf("Failed to insert after node\n");
        }
    }
}

// 2. **insertInPlace**: Inserts new data in place of old data
void insertInPlace(struct Node** head, int oldData, int newData) {
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == oldData) {
            temp->data = newData;
            return;
        }
        temp = temp->next;
    }
    printf("Data %d not found in the list\n", oldData);
}

// 3. **deleteAtBeginning**: Deletes the node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// 3. **deleteAtEnd**: Deletes the node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// 3. **deleteAtPosition**: Deletes the node at a specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if (pos == 0) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < pos && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            struct Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        } else {
            printf("Position out of bounds\n");
        }
    }
}

// 3. **deleteNode**: Deletes a node with the specified key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else if ((*head)->data == key) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            struct Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        } else {
            printf("Key %d not found in the list\n", key);
        }
    }
}

// 4. **searchNode**: Searches for a node with a specific key
void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    int found = 0; // Flag to check if the node is found
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        printf("Node with key %d found\n", key);
    } else {
        printf("Node with key %d not found\n", key);
    }
}

// 5. **traverseList**: Prints all nodes in the list from head to end
void traverseList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 6. **lengthOfList**: Returns the number of nodes in the list
void lengthOfList(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Length of the list: %d\n", count);
}

// 7. **reverseList**: Reverses the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// 8. **findMiddleNode**: Finds and prints the middle node
void findMiddleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    if (head == NULL) {
        printf("List is empty, no middle node\n");
    } else {
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("Middle node: %d\n", slow->data);
    }
}

// 9. **detectLoop**: Detects if there is a loop in the list
void detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    int loopExists = 0; // Flag to check if loop exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = 1;
            break;
        }
    }
    if (loopExists) {
        printf("Loop detected in the list\n");
    } else {
        printf("No loop detected in the list\n");
    }
}

// 10. **removeDuplicates**: Removes duplicate nodes from the list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    if (current == NULL) {
        printf("List is empty, cannot remove duplicates\n");
    } else {
        while (current->next != NULL) {
            if (current->data == current->next->data) {
                nextNode = current->next->next;
                free(current->next);
                current->next = nextNode;
            } else {
                current = current->next;
            }
        }
    }
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    // Print list
    printf("Initial List: ");
    traverseList(head); // Expected: 10 -> 20 -> 20 -> 30 -> NULL

    // Insert at beginning
    insertAtBeginning(&head, 5);
    printf("After inserting at beginning: ");
    traverseList(head); // Expected: 5 -> 10 -> 20 -> 20 -> 30 -> NULL

    // Insert at position
    insertAtPosition(&head, 15, 2);
    printf("After inserting 15 at position 2: ");
    traverseList(head); // Expected: 5 -> 10 -> 15 -> 20 -> 20 -> 30 -> NULL

    // Insert after a node
    insertAfterNode(head->next, 12); // Insert after node with data 10
    printf("After inserting 12 after 10: ");
    traverseList(head); // Expected: 5 -> 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

    // Delete at beginning
    deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

    // Delete at end
    deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> NULL

    // Delete at position
    deleteAtPosition(&head, 1);
    printf("After deleting at position 1: ");
    traverseList(head); // Expected: 10 -> 15 -> 20 -> NULL

    // Delete node
    deleteNode(&head, 15);
    printf("After deleting node with key 15: ");
    traverseList(head); // Expected: 10 -> 20 -> NULL

    // Search for a node
    searchNode(head, 10); // Expected: Node with key 10 found
    searchNode(head, 15); // Expected: Node with key 15 not found

    // Get length of list
    lengthOfList(head); // Expected: Length of the list: 2

    // Reverse the list
    reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head); // Expected: 20 -> 10 -> NULL

    // Find middle node
    findMiddleNode(head); // Expected: Middle node: 20

    // Detect loop
    detectLoop(head); // Expected: No loop detected in the list

    // Remove duplicates
    insertAtEnd(&head, 20); // Adding duplicate for testing
    insertAtEnd(&head, 20);
    printf("List before removing duplicates: ");
    traverseList(head); // Expected: 20 -> 10 -> 20 -> 20 -> NULL
    removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head); // Expected: 20 -> 10 -> NULL

    return 0;
}
