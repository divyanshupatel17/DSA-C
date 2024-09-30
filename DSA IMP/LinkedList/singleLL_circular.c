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
    newNode->next = newNode;  // Points to itself in a circular list
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
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
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
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
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
    for (int i = 1; i < pos - 1 && current->next != *head; i++) {
        current = current->next;
    }
    
    // CASE 4: If position is out of range
    if (current->next == *head && pos > 2) {
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
    do {
        if (current->data == oldData) {
            current->data = newData;
            return *head;
        }
        current = current->next;
    } while (current != *head);
    
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
    
    // CASE 2: If only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Delete the first node
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    last->next = *head;
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
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return NULL;
    }
    
    // CASE 3: Traverse to the second last node
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != *head) {
        prev = current;
        current = current->next;
    }
    
    // Delete the last node
    prev->next = *head;
    free(current);
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
    struct Node* prev = NULL;
    int i;
    for (i = 1; i < position && current->next != *head; i++) {
        prev = current;
        current = current->next;
    }
    
    if (i != position) {
        printf("Position out of range\n");
        return *head;
    }
    
    prev->next = current->next;
    free(current);
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
    do {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            return *head;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    
    // CASE 4: If key not found
    printf("Key not found in the list\n");
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
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
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
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to start)\n");
}

// 13. Function to find the length of the list
int lengthOfList(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct Node* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// 14. Function to reverse the list
struct Node* reverseList(struct Node** head) {
    // CASE 1: If head is NULL or only one node
    if (*head == NULL || (*head)->next == *head) {
        return *head;
    }
    
    // CASE 2: Reverse the list
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    
    (*head)->next = prev;
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
    
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    
    printf("Middle node: %d\n", slow->data);
}

// 16. Function to detect a loop in the list
// Note: In a circular linked list, there's always a loop
int detectLoop(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1;  // Always returns 1 for a circular linked list
}

// 17. Function to remove duplicates from the list
struct Node* removeDuplicates(struct Node* head) {
    // CASE 1: If head is NULL or only one node
    if (head == NULL || head->next == head) {
        return head;
    }
    
    // CASE 2: Traverse the list and remove duplicates
    struct Node* current = head;
    do {
        struct Node* runner = current;
        while (runner->next != head) {
            if (runner->next->data == current->data) {
                struct Node* temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != head);
    
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
    
    // 3. Insert at end
    head = insertAtEnd(&head, 40);
    head = insertAtEnd(&head, 50);
    printf("After inserting at end: ");
    traverseList(head);
    
    // 4. Insert at position
    head = insertAtPosition(&head, 25, 3);
    printf("After inserting 25 at position 3: ");
    traverseList(head);
    
    // 5. Insert after node
    struct Node* node = searchNode(head, 25);
    if (node != NULL) {
        insertAfterNode(node, 35);
    }
    printf("After inserting 35 after 25: ");
    traverseList(head);
    
    // 6. Insert in place
    head = insertInPlace(&head, 20, 22);
    printf("After replacing 20 with 22: ");
    traverseList(head);
    
    // 7. Delete at beginning
    head = deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    traverseList(head);
    
    // 8. Delete at end
    head = deleteAtEnd(&head);
    printf("After deleting at end: ");
    traverseList(head);
    
    // 9. Delete at position
    head = deleteAtPosition(&head, 3);
    printf("After deleting at position 3: ");
    traverseList(head);
    
    // 10. Delete node with key
    head = deleteNode(&head, 25);
    printf("After deleting node with key 25: ");
    traverseList(head);
    
    // 11. Search for a node
    struct Node* foundNode = searchNode(head, 10);
    if (foundNode != NULL) {
        printf("Node with key 10 found\n");
    }
    
    // 13. Length of list
    printf("Length of list: %d\n", lengthOfList(head));
    
    // 14. Reverse list
    head = reverseList(&head);
    printf("After reversing the list: ");
    traverseList(head);
    
    // 15. Find middle node
    findMiddleNode(head);
    
    // 16. Detect loop (always true for circular linked list)
    if (detectLoop(head)) {
        printf("Loop detected in the list (as expected for circular list)\n");
    } else {
        printf("No loop detected in the list (unexpected for circular list)\n");
    }
    
    // 17. Remove duplicates (add some duplicates first)
    head = insertAtEnd(&head, 10);
    head = insertAtEnd(&head, 40);
    printf("Before removing duplicates: ");
    traverseList(head);
    head = removeDuplicates(head);
    printf("After removing duplicates: ");
    traverseList(head);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// /* 
//    Singly Circular Linked List Operations:

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

// // Definition of a singly circular linked list node
// struct Node {
//     int data;
//     struct Node* next; // Pointer to the next node
// };

// // 1. **createNode(int data)**: Creates a new node with given data.
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // 2. Insert Operations
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         newNode->next = *head;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->next = *head;
//         *head = newNode;
//     }
// }

// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         newNode->next = *head;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->next = *head;
//     }
// }

// void insertAtPosition(struct Node** head, int data, int pos) {
//     if (pos == 0) {
//         insertAtBeginning(head, data);
//     } else {
//         struct Node* newNode = createNode(data);
//         struct Node* temp = *head;
//         int i = 0;
//         while (i < pos - 1 && temp->next != *head) {
//             temp = temp->next;
//             i++;
//         }
//         if (i == pos - 1) {
//             newNode->next = temp->next;
//             temp->next = newNode;
//         } else {
//             printf("Position out of bounds.\n");
//             free(newNode);
//         }
//     }
// }

// void insertAfterNode(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("Previous node cannot be NULL.\n");
//         return;
//     }
//     struct Node* newNode = createNode(data);
//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
// }

// void insertInPlace(struct Node** head, int oldData, int newData) {
//     struct Node* temp = *head;
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     do {
//         if (temp->data == oldData) {
//             temp->data = newData;
//             return;
//         }
//         temp = temp->next;
//     } while (temp != *head);
//     printf("Data %d not found.\n", oldData);
// }

// // 3. Delete Operations
// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         struct Node* last = *head;
//         while (last->next != *head) {
//             last = last->next;
//         }
//         last->next = (*head)->next;
//         *head = (*head)->next;
//         free(temp);
//     }
// }

// void deleteAtEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//     } else {
//         struct Node* temp = *head;
//         struct Node* prev = NULL;
//         while (temp->next != *head) {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = *head;
//         free(temp);
//     }
// }

// void deleteAtPosition(struct Node** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     if (pos == 0) {
//         deleteAtBeginning(head);
//     } else {
//         struct Node* temp = *head;
//         struct Node* prev = NULL;
//         int i = 0;
//         while (i < pos && temp->next != *head) {
//             prev = temp;
//             temp = temp->next;
//             i++;
//         }
//         if (i == pos) {
//             prev->next = temp->next;
//             free(temp);
//         } else {
//             printf("Position out of bounds.\n");
//         }
//     }
// }

// void deleteNode(struct Node** head, int key) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = *head;
//     struct Node* prev = NULL;
//     if (temp->data == key && temp->next == *head) {
//         free(temp);
//         *head = NULL;
//         return;
//     }
//     if (temp->data == key) {
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = (*head)->next;
//         free(*head);
//         *head = temp->next;
//         return;
//     }
//     while (temp->next != *head && temp->data != key) {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp->data == key) {
//         prev->next = temp->next;
//         free(temp);
//     } else {
//         printf("Key not found.\n");
//     }
// }

// // 4. Search Node
// int searchNode(struct Node* head, int key) {
//     if (head == NULL) {
//         return 0;
//     }
//     struct Node* temp = head;
//     do {
//         if (temp->data == key) {
//             return 1;
//         }
//         temp = temp->next;
//     } while (temp != head);
//     return 0;
// }

// // 5. Traverse List
// void traverseList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = head;
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(back to head)\n");
// }

// // 6. Length of List
// int lengthOfList(struct Node* head) {
//     if (head == NULL) {
//         return 0;
//     }
//     int length = 0;
//     struct Node* temp = head;
//     do {
//         length++;
//         temp = temp->next;
//     } while (temp != head);
//     return length;
// }

// // 7. Reverse List
// void reverseList(struct Node** head) {
//     if (*head == NULL) {
//         return;
//     }
//     struct Node *prev = NULL, *curr = *head, *next = NULL;
//     struct Node* last = *head;
//     while (last->next != *head) {
//         last = last->next;
//     }
//     do {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     } while (curr != *head);
//     (*head)->next = prev;
//     last->next = prev;
//     *head = prev;
// }

// // 8. Find Middle Node
// void findMiddleNode(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* slow = head;
//     struct Node* fast = head;
//     while (fast->next != head && fast->next->next != head) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     printf("Middle node: %d\n", slow->data);
// }

// // 9. Detect Loop (Always present in a circular list, hence returns true)
// int detectLoop(struct Node* head) {
//     return 1; // Loop is inherent in circular linked lists
// }

// // 10. Remove Duplicates
// void removeDuplicates(struct Node* head) {
//     if (head == NULL) {
//         return;
//     }
//     struct Node* curr = head;
//     do {
//         struct Node* temp = curr;
//         while (temp->next != head) {
//             if (temp->next->data == curr->data) {
//                 struct Node* dup = temp->next;
//                 temp->next = temp->next->next;
//                 free(dup);
//             } else {
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     } while (curr->next != head);
// }

// // Main function to test the linked list operations
// int main() {
//     struct Node* head = NULL;

//     insertAtBeginning(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 30);
//     insertAtEnd(&head, 40);
//     insertAtBeginning(&head, 50);
    
//     printf("List: ");
//     traverseList(head);

//     findMiddleNode(head);
    
//     deleteAtPosition(&head, 2);
//     printf("After deletion at position 2: ");
//     traverseList(head);

//     return 0;
// }
