#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// 2. Function to insert at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
    }
    // CASE 3: Otherwise, insert at the beginning
    else {
        newNode->next = *head;
        *head = newNode;
    }
    return *head;
}

// 3. Function to insert at the end
struct Node* insertAtEnd(struct Node** head, int data) {
    // CASE 1: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 2: If head is NULL, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return *head;
    }
    
    // CASE 3: Otherwise, traverse to the end and insert
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return *head;
}

// 4. Function to insert at a specific position
struct Node* insertAtPosition(struct Node** head, int data, int pos) {
    // CASE 1: If position is 1, insert at beginning
    if (pos == 1) {
        return insertAtBeginning(head, data);
    }
    
    // CASE 2: Create a new node
    struct Node* newNode = createNode(data);
    
    // CASE 3: Traverse to the position and insert
    struct Node* current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // CASE 4: If position is out of range
    if (current == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return *head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return *head;
}

// 5. Function to insert after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    // CASE 1: If previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    // CASE 2: Create a new node and insert after prevNode
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// 6. Function to insert new data in place of old data
struct Node* insertInPlace(struct Node** head, int oldData, int newData) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return *head;
    }
    
    // CASE 2: Traverse the list and replace old data with new data
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return *head;
        }
        current = current->next;
    }
    
    // CASE 3: If old data not found
    printf("Old data not found in the list\n");
    return *head;
}

// 7. Function to delete at the beginning
struct Node* deleteAtBeginning(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: Delete the first node
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return *head;
}

// 8. Function to delete at the end
struct Node* deleteAtEnd(struct Node** head) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Traverse to the second last node
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Delete the last node
    free(current->next);
    current->next = NULL;
    return *head;
}

// 9. Function to delete at a specific position
struct Node* deleteAtPosition(struct Node** head, int position) {
    // CASE 1: If head is NULL or position is less than 1
    if (*head == NULL || position < 1) {
        return *head;
    }
    
    // CASE 2: If first position
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: If valid position
    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return *head;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return *head;
}

// 10. Function to delete a node with a specific key
struct Node* deleteNode(struct Node** head, int key) {
    // CASE 1: If head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: If key is in the first node
    if ((*head)->data == key) {
        return deleteAtBeginning(head);
    }
    
    // CASE 3: Traverse the list to find the key
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    // CASE 4: If key not found
    if (current == NULL) {
        printf("Key not found in the list\n");
        return *head;
    }
    
    // Delete the node with the key
    prev->next = current->next;
    free(current);
    return *head;
}

// 11. Function to search for a node with a specific key
struct Node* searchNode(struct Node* head, int key) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // CASE 2: Traverse the list to find the key
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    
    // CASE 3: If key not found
    printf("Key not found in the list\n");
    return NULL;
}

// 12. Function to traverse and print the list
void traverseList(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Traverse and print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 13. Function to find the length of the list
int lengthOfList(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 14. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: If head is NULL or only one node
    if (*head == NULL || (*head)->next == NULL) {
        return *head;
    }
    
    // CASE 2: Reverse the list
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
    return *head;
}

// 15. Function to find the middle node
void findMiddleNode(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // CASE 2: Use slow and fast pointers to find the middle
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    printf("Middle node: %d\n", slow->data);
}

// 16. Function to detect a loop in the list
int detectLoop(struct Node* head) {
    // CASE 1: If head is NULL
    if (head == NULL) {
        return 0;
    }
    
    // CASE 2: Use Floyd's cycle-finding algorithm
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // Loop detected
        }
    }
    
    return 0; // No loop
}

// 17. Function to remove duplicates from the list
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: If head is NULL or only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // CASE 2: Traverse the list and remove duplicates
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    return head;
}

int main() {
    struct Node* head = NULL;
    
    // 2. Insert at beginning
    head = insertAtBeginning(&head, 10);
    head = insertAtBeginning(&head, 20);
    head = insertAtBeginning(&head, 30);
    printf("After inserting at beginning: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 10 -> NULL
    
    // 3. Insert at end
    head = insertAtEnd(&head, 40);
    head = insertAtEnd(&head, 50);
    printf("After inserting at end: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 10 -> 40 -> 50 -> NULL
    
    // 4. Insert at position
    head = insertAtPosition(&head, 25, 3);
    printf("After inserting 25 at position 3: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 25 -> 10 -> 40 -> 50 -> NULL
    
    // 5. Insert after node
    struct Node* node = searchNode(head, 25);
    if (node != NULL) {
        insertAfterNode(node, 35);
    }
    printf("After inserting 35 after 25: ");
    traverseList(head);
    // Expected output: 30 -> 20 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 6. Insert in place
    head = insertInPlace(&head, 20, 22);
    printf("After replacing 20 with 22: ");
    traverseList(head);
    // Expected output: 30 -> 22 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 7. Delete at beginning
    head = deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 35 -> 10 -> 40 -> 50 -> NULL
    
    // 8. Delete at end
    head = deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 35 -> 10 -> 40 -> NULL
    
    // 9. Delete at position
    head = deleteAtPosition(&head, 3);
    printf("After deleting at position 3: ");
    traverseList(head);
    // Expected output: 22 -> 25 -> 10 -> 40 -> NULL
    
    // 10. Delete node with key
    head = deleteNode(&head, 25);
    printf("After deleting node with key 25: ");
    traverseList(head);
    // Expected output: 22 -> 10 -> 40 -> NULL
    
    // 11. Search for a node
    struct Node* foundNode = searchNode(head, 10);
    if (foundNode != NULL) {
        printf("Node with key 10 found\n");
    }
    
    // 13. Length of list
    printf("Length of list: %d\n", lengthOfList(head));
    // Expected output: Length of list: 3
    
    // 14. Reverse list
    head = reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head);
    // Expected output: 40 -> 10 -> 22 -> NULL
    
    // 15. Find middle node
    findMiddleNode(head);
    // Expected output: Middle node: 10
    
    // 16. Detect loop (no loop in this case)
    if (detectLoop(head)) {
        printf("Loop detected in the list\n");
    } else {
        printf("No loop detected in the list\n");
    }
    // Expected output: No loop detected in the list
    
    // 17. Remove duplicates (add some duplicates first)
    head = insertAtEnd(&head, 10);
    head = insertAtEnd(&head, 40);
    printf("Before removing duplicates: ");
    traverseList(head);
    head = removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head);
    // Expected output: 40 -> 10 -> 22

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// /* 
//    Singly Linked List Operations:

//    1. **createNode(int data)**: 
//       - Creates a new node with given data, next pointer set to NULL.

//    2. **insert**:
//      - **insertAtBeginning(struct Node** head, int data)**: Inserts a node at the beginning.
//      - **insertAtEnd(struct Node** head, int data)**: Inserts a node at the end.
//      - **insertAtPosition(struct Node** head, int data, int pos)**: Inserts a node at a specific position.
//      - **insertAfterNode(struct Node* prevNode, int data)**: Inserts a node after a given node.
//      - **insertInPlace(struct Node** head, int oldData, int newData)**: Inserts new data in place of old data.

//    3. **delete**:
//      - **deleteAtBeginning(struct Node** head)**: Deletes the node at the beginning.
//      - **deleteAtEnd(struct Node** head)**: Deletes the node at the end.
//      - **deleteAtPosition(struct Node** head, int pos)**: Deletes the node at a specific position.
//      - **deleteNode(struct Node** head, int key)**: Deletes a node with the specified key.

//    4. **searchNode(struct Node* head, int key)**: Searches for a node with a specific key.

//    5. **traverseList(struct Node* head)**: Prints all nodes in the list from head to end.

//    6. **lengthOfList(struct Node* head)**: Returns the number of nodes in the list.

//    7. **reverseList(struct Node** head)**: Reverses the list.

//    8. **findMiddleNode(struct Node* head)**: Finds and prints the middle node.

//    9. **detectLoop(struct Node* head)**: Detects if there is a loop in the list.

//    10. **removeDuplicates(struct Node* head)**: Removes duplicate nodes from the list.
// */

// // Definition of a singly linked list node
// struct Node {
//     int data;
//     struct Node* next;
// };

// // 1. **createNode**: Creates a new node with given data
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode != NULL) {
//         newNode->data = data;
//         newNode->next = NULL;
//     } else {
//         printf("Memory allocation failed\n");
//     }
//     return newNode;
// }

// // 2. **insertAtBeginning**: Inserts a node at the beginning
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (newNode != NULL) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         printf("Failed to insert at beginning\n");
//     }
// }

// // 2. **insertAtEnd**: Inserts a node at the end
// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         if (newNode != NULL) {
//             *head = newNode;
//         }
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         if (newNode != NULL) {
//             temp->next = newNode;
//         } else {
//             printf("Failed to insert at end\n");
//         }
//     }
// }

// // 2. **insertAtPosition**: Inserts a node at a specific position
// void insertAtPosition(struct Node** head, int data, int pos) {
//     struct Node* newNode = createNode(data);
//     if (newNode != NULL) {
//         if (pos == 0) {
//             insertAtBeginning(head, data);
//         } else {
//             struct Node* temp = *head;
//             for (int i = 1; i < pos && temp != NULL; i++) {
//                 temp = temp->next;
//             }
//             if (temp != NULL) {
//                 newNode->next = temp->next;
//                 temp->next = newNode;
//             } else {
//                 printf("Position out of bounds\n");
//             }
//         }
//     } else {
//         printf("Failed to insert at position\n");
//     }
// }

// // 2. **insertAfterNode**: Inserts a node after a given node
// void insertAfterNode(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("The given previous node cannot be NULL\n");
//     } else {
//         struct Node* newNode = createNode(data);
//         if (newNode != NULL) {
//             newNode->next = prevNode->next;
//             prevNode->next = newNode;
//         } else {
//             printf("Failed to insert after node\n");
//         }
//     }
// }

// // 2. **insertInPlace**: Inserts new data in place of old data
// void insertInPlace(struct Node** head, int oldData, int newData) {
//     struct Node* temp = *head;
//     while (temp != NULL) {
//         if (temp->data == oldData) {
//             temp->data = newData;
//             return;
//         }
//         temp = temp->next;
//     }
//     printf("Data %d not found in the list\n", oldData);
// }

// // 3. **deleteAtBeginning**: Deletes the node at the beginning
// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else {
//         struct Node* temp = *head;
//         *head = (*head)->next;
//         free(temp);
//     }
// }

// // 3. **deleteAtEnd**: Deletes the node at the end
// void deleteAtEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if ((*head)->next == NULL) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next->next != NULL) {
//             temp = temp->next;
//         }
//         free(temp->next);
//         temp->next = NULL;
//     }
// }

// // 3. **deleteAtPosition**: Deletes the node at a specific position
// void deleteAtPosition(struct Node** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if (pos == 0) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         for (int i = 1; i < pos && temp->next != NULL; i++) {
//             temp = temp->next;
//         }
//         if (temp->next != NULL) {
//             struct Node* delNode = temp->next;
//             temp->next = temp->next->next;
//             free(delNode);
//         } else {
//             printf("Position out of bounds\n");
//         }
//     }
// }

// // 3. **deleteNode**: Deletes a node with the specified key
// void deleteNode(struct Node** head, int key) {
//     if (*head == NULL) {
//         printf("List is empty, cannot delete\n");
//     } else if ((*head)->data == key) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != NULL && temp->next->data != key) {
//             temp = temp->next;
//         }
//         if (temp->next != NULL) {
//             struct Node* delNode = temp->next;
//             temp->next = temp->next->next;
//             free(delNode);
//         } else {
//             printf("Key %d not found in the list\n", key);
//         }
//     }
// }

// // 4. **searchNode**: Searches for a node with a specific key
// void searchNode(struct Node* head, int key) {
//     struct Node* temp = head;
//     int found = 0; // Flag to check if the node is found
//     while (temp != NULL) {
//         if (temp->data == key) {
//             found = 1;
//             break;
//         }
//         temp = temp->next;
//     }
//     if (found) {
//         printf("Node with key %d found\n", key);
//     } else {
//         printf("Node with key %d not found\n", key);
//     }
// }

// // 5. **traverseList**: Prints all nodes in the list from head to end
// void traverseList(struct Node* head) {
//     struct Node* temp = head;
//     if (temp == NULL) {
//         printf("List is empty\n");
//     } else {
//         while (temp != NULL) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// // 6. **lengthOfList**: Returns the number of nodes in the list
// void lengthOfList(struct Node* head) {
//     int count = 0;
//     struct Node* temp = head;
//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }
//     printf("Length of the list: %d\n", count);
// }

// // 7. **reverseList**: Reverses the list
// void reverseList(struct Node** head) {
//     struct Node* prev = NULL;
//     struct Node* current = *head;
//     struct Node* next = NULL;
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head = prev;
// }

// // 8. **findMiddleNode**: Finds and prints the middle node
// void findMiddleNode(struct Node* head) {
//     struct Node* slow = head;
//     struct Node* fast = head;
//     if (head == NULL) {
//         printf("List is empty, no middle node\n");
//     } else {
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         printf("Middle node: %d\n", slow->data);
//     }
// }

// // 9. **detectLoop**: Detects if there is a loop in the list
// void detectLoop(struct Node* head) {
//     struct Node* slow = head;
//     struct Node* fast = head;
//     int loopExists = 0; // Flag to check if loop exists
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast) {
//             loopExists = 1;
//             break;
//         }
//     }
//     if (loopExists) {
//         printf("Loop detected in the list\n");
//     } else {
//         printf("No loop detected in the list\n");
//     }
// }

// // 10. **removeDuplicates**: Removes duplicate nodes from the list
// void removeDuplicates(struct Node* head) {
//     struct Node* current = head;
//     struct Node* nextNode;
//     if (current == NULL) {
//         printf("List is empty, cannot remove duplicates\n");
//     } else {
//         while (current->next != NULL) {
//             if (current->data == current->next->data) {
//                 nextNode = current->next->next;
//                 free(current->next);
//                 current->next = nextNode;
//             } else {
//                 current = current->next;
//             }
//         }
//     }
// }

// // Main function to demonstrate the linked list operations
// int main() {
//     struct Node* head = NULL;

//     // Insert nodes at the end
//     insertAtEnd(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 30);
    
//     // Print list
//     printf("Initial List: ");
//     traverseList(head); // Expected: 10 -> 20 -> 20 -> 30 -> NULL

//     // Insert at beginning
//     insertAtBeginning(&head, 5);
//     printf("After inserting at beginning: ");
//     traverseList(head); // Expected: 5 -> 10 -> 20 -> 20 -> 30 -> NULL

//     // Insert at position
//     insertAtPosition(&head, 15, 2);
//     printf("After inserting 15 at position 2: ");
//     traverseList(head); // Expected: 5 -> 10 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Insert after a node
//     insertAfterNode(head->next, 12); // Insert after node with data 10
//     printf("After inserting 12 after 10: ");
//     traverseList(head); // Expected: 5 -> 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Delete at beginning
//     deleteAtBeginning(&head);
//     printf("After deleting at beginning: ");
//     traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> 20 -> 30 -> NULL

//     // Delete at end
//     deleteAtEnd(&head);
//     printf("After deleting at end: ");
//     traverseList(head); // Expected: 10 -> 12 -> 15 -> 20 -> NULL

//     // Delete at position
//     deleteAtPosition(&head, 1);
//     printf("After deleting at position 1: ");
//     traverseList(head); // Expected: 10 -> 15 -> 20 -> NULL

//     // Delete node
//     deleteNode(&head, 15);
//     printf("After deleting node with key 15: ");
//     traverseList(head); // Expected: 10 -> 20 -> NULL

//     // Search for a node
//     searchNode(head, 10); // Expected: Node with key 10 found
//     searchNode(head, 15); // Expected: Node with key 15 not found

//     // Get length of list
//     lengthOfList(head); // Expected: Length of the list: 2

//     // Reverse the list
//     reverseList(&head);
//     printf("After reversing the list: ");
//     traverseList(head); // Expected: 20 -> 10 -> NULL

//     // Find middle node
//     findMiddleNode(head); // Expected: Middle node: 20

//     // Detect loop
//     detectLoop(head); // Expected: No loop detected in the list

//     // Remove duplicates
//     insertAtEnd(&head, 20); // Adding duplicate for testing
//     insertAtEnd(&head, 20);
//     printf("List before removing duplicates: ");
//     traverseList(head); // Expected: 20 -> 10 -> 20 -> 20 -> NULL
//     removeDuplicates(head);
//     printf("After removing duplicates: ");
//     traverseList(head); // Expected: 20 -> 10 -> NULL

//     return 0;
// }
