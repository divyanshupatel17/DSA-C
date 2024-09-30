#include <stdio.h>
#include <stdlib.h>

/* 
   Doubly Circular Linked List Operations:

   1. **createNode(int data)**: 
      - Creates a new node with given data, next and prev pointers set to NULL.

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

// Definition of a doubly circular linked list node
struct Node {
    int data;
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = newNode; // Point to itself
        newNode->prev = newNode; // Point to itself
    }
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, the new node becomes the head
    } else {
        struct Node* tail = (*head)->prev; // Get the last node
        newNode->next = *head; // Link new node to head
        newNode->prev = tail; // Link new node to tail
        tail->next = newNode; // Link tail to new node
        (*head)->prev = newNode; // Link head to new node
        *head = newNode; // Update head to new node
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, the new node becomes the head
    } else {
        struct Node* tail = (*head)->prev; // Get the last node
        newNode->next = *head; // Link new node to head
        newNode->prev = tail; // Link new node to tail
        tail->next = newNode; // Link tail to new node
        (*head)->prev = newNode; // Link head to new node
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 0) {
        insertAtBeginning(head, data); // If position is 0, insert at the beginning
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next; // Traverse to the specified position
        }
        if (temp != NULL) {
            newNode->next = temp->next; // Link new node to next node
            newNode->prev = temp; // Link new node to current node
            temp->next->prev = newNode; // Link next node to new node
            temp->next = newNode; // Link current node to new node
        } else {
            printf("Position out of bounds\n");
        }
    }
}

// Function to insert a node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = prevNode->next; // Link new node to next node
        newNode->prev = prevNode; // Link new node to previous node
        prevNode->next->prev = newNode; // Link next node to new node
        prevNode->next = newNode; // Link previous node to new node
    }
}

// Function to insert new data in place of old data
void insertInPlace(struct Node** head, int oldData, int newData) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = *head;
        do {
            if (temp->data == oldData) {
                temp->data = newData; // Replace old data with new data
                return;
            }
            temp = temp->next; // Move to the next node
        } while (temp != *head);
        printf("Old data %d not found in the list\n", oldData);
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = *head;
        struct Node* tail = (*head)->prev; // Get the last node
        if (temp == tail) {
            free(temp); // If it's the only node, free it
            *head = NULL; // Update head to NULL
        } else {
            tail->next = temp->next; // Link tail to second node
            temp->next->prev = tail; // Link second node to tail
            free(temp); // Free the old head
            *head = tail->next; // Update head to the new head
        }
    }
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* tail = (*head)->prev; // Get the last node
        if (tail == *head) {
            free(tail); // If it's the only node, free it
            *head = NULL; // Update head to NULL
        } else {
            struct Node* newTail = tail->prev; // Get the new tail
            newTail->next = *head; // Link new tail to head
            (*head)->prev = newTail; // Link head to new tail
            free(tail); // Free the old tail
        }
    }
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if (pos == 0) {
        deleteAtBeginning(head); // If position is 0, delete at the beginning
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next; // Traverse to the specified position
        }
        if (temp != NULL) {
            if (temp->next == *head) {
                deleteAtEnd(head); // If it's the last node, delete at the end
            } else {
                temp->prev->next = temp->next; // Link previous node to next node
                temp->next->prev = temp->prev; // Link next node to previous node
                free(temp); // Free the deleted node
            }
        } else {
            printf("Position out of bounds\n");
        }
    }
}

// Function to delete a node with the specified key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = *head;
        do {
            if (temp->data == key) {
                if (temp == *head) {
                    deleteAtBeginning(head); // If it's the head, delete at the beginning
                } else {
                    temp->prev->next = temp->next; // Link previous node to next node
                    temp->next->prev = temp->prev; // Link next node to previous node
                    free(temp); // Free the deleted node
                }
                return;
            }
            temp = temp->next; // Move to the next node
        } while (temp != *head);
        printf("Key %d not found in the list\n", key);
    }
}

// Function to search for a node with a specific key
void searchNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        do {
            if (temp->data == key) {
                printf("Node with key %d found\n", key);
                return;
            }
            temp = temp->next; // Move to the next node
        } while (temp != head);
        printf("Node with key %d not found\n", key);
    }
}

// Function to print all nodes in the list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data); // Print node data
            temp = temp->next; // Move to the next node
        } while (temp != head);
        printf("\n");
    }
}

// Function to return the number of nodes in the list
int lengthOfList(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct Node* temp = head;
    do {
        count++; // Count nodes
        temp = temp->next; // Move to the next node
    } while (temp != head);
    return count;
}

// Function to reverse the list
void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current = *head, *temp = NULL, *prev = NULL;
    do {
        temp = current->prev; // Store previous node
        current->prev = current->next; // Swap next and prev
        current->next = temp; // Swap next and prev
        prev = current; // Update prev
        current = current->prev; // Move to next node
    } while (current != *head);
    *head = prev; // Update head to the new head
}

// Function to find and print the middle node
void findMiddleNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next; // Move slow pointer by one
        fast = fast->next->next; // Move fast pointer by two
    }
    printf("Middle node is %d\n", slow->data);
}

// Function to detect if there is a loop in the list
void detectLoop(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != head) {
        slow = slow->next; // Move slow pointer by one
        fast = fast->next->next; // Move fast pointer by two
        if (slow == fast) {
            printf("Loop detected in the list\n");
            return;
        }
    }
    printf("No loop detected in the list\n");
}

// Function to remove duplicate nodes from the list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        struct Node* runner = current->next;
        while (runner != head) {
            if (current->data == runner->data) {
                struct Node* temp = runner; // Store node to be deleted
                runner->prev->next = runner->next; // Link previous node to next
                runner->next->prev = runner->prev; // Link next node to previous
                runner = runner->next; // Move runner to next
                free(temp); // Free the deleted node
            } else {
                runner = runner->next; // Move runner to next
            }
        }
        current = current->next; // Move current to next
    } while (current != head);
}

// Main function to demonstrate the functionality
int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning
    insertAtBeginning(&head, 10);
    // List state: 10
    traverseList(head); // Expected Output: 10

    // Inserting nodes at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    // List state: 10 <-> 20 <-> 30
    traverseList(head); // Expected Output: 10 20 30

    // Inserting nodes at specific positions
    insertAtPosition(&head, 25, 2);
    // List state: 10 <-> 20 <-> 25 <-> 30
    traverseList(head); // Expected Output: 10 20 25 30

    // Inserting after a specific node
    insertAfterNode(head->next, 22);
    // List state: 10 <-> 20 <-> 22 <-> 25 <-> 30
    traverseList(head); // Expected Output: 10 20 22 25 30

    // Replacing old data with new data
    insertInPlace(&head, 22, 23);
    // List state: 10 <-> 20 <-> 23 <-> 25 <-> 30
    traverseList(head); // Expected Output: 10 20 23 25 30

    // Deleting a node at the beginning
    deleteAtBeginning(&head);
    // List state: 20 <-> 23 <-> 25 <-> 30
    traverseList(head); // Expected Output: 20 23 25 30

    // Deleting a node at the end
    deleteAtEnd(&head);
    // List state: 20 <-> 23 <-> 25
    traverseList(head); // Expected Output: 20 23 25

    // Deleting a node at a specific position
    deleteAtPosition(&head, 1);
    // List state: 20 <-> 25
    traverseList(head); // Expected Output: 20 25

    // Deleting a node with a specific key
    deleteNode(&head, 20);
    // List state: 25
    traverseList(head); // Expected Output: 25

    // Searching for a node with a specific key
    searchNode(head, 25); // Expected Output: Node with key 25 found
    searchNode(head, 30); // Expected Output: Node with key 30 not found

    // Length of the list
    printf("Length of the list: %d\n", lengthOfList(head)); // Expected Output: 1

    // Inserting some more nodes
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 45);
    // List state: 25 <-> 35 <-> 45
    traverseList(head); // Expected Output: 25 35 45

    // Reversing the list
    reverseList(&head);
    // List state: 45 <-> 35 <-> 25
    traverseList(head); // Expected Output: 45 35 25

    // Finding the middle node
    findMiddleNode(head); // Expected Output: Middle node is 35

    // Detecting loops
    detectLoop(head); // Expected Output: No loop detected in the list

    // Removing duplicates (none in this case)
    removeDuplicates(head);
    traverseList(head); // Expected Output: 45 35 25

    return 0;
}
