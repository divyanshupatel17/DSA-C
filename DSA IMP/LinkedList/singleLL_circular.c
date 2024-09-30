#include <stdio.h>
#include <stdlib.h>

/* 
   Singly Circular Linked List Operations:

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

// Definition of a singly circular linked list node
struct Node {
    int data;
    struct Node* next; // Pointer to the next node
};

// 1. **createNode(int data)**: Creates a new node with given data.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2. Insert Operations
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos == 0) {
        insertAtBeginning(head, data);
    } else {
        struct Node* newNode = createNode(data);
        struct Node* temp = *head;
        int i = 0;
        while (i < pos - 1 && temp->next != *head) {
            temp = temp->next;
            i++;
        }
        if (i == pos - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Position out of bounds.\n");
            free(newNode);
        }
    }
}

void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertInPlace(struct Node** head, int oldData, int newData) {
    struct Node* temp = *head;
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        if (temp->data == oldData) {
            temp->data = newData;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Data %d not found.\n", oldData);
}

// 3. Delete Operations
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 0) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        int i = 0;
        while (i < pos && temp->next != *head) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (i == pos) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Position out of bounds.\n");
        }
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp->data == key && temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }
    if (temp->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }
    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Key not found.\n");
    }
}

// 4. Search Node
int searchNode(struct Node* head, int key) {
    if (head == NULL) {
        return 0;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);
    return 0;
}

// 5. Traverse List
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// 6. Length of List
int lengthOfList(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    int length = 0;
    struct Node* temp = head;
    do {
        length++;
        temp = temp->next;
    } while (temp != head);
    return length;
}

// 7. Reverse List
void reverseList(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != *head);
    (*head)->next = prev;
    last->next = prev;
    *head = prev;
}

// 8. Find Middle Node
void findMiddleNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle node: %d\n", slow->data);
}

// 9. Detect Loop (Always present in a circular list, hence returns true)
int detectLoop(struct Node* head) {
    return 1; // Loop is inherent in circular linked lists
}

// 10. Remove Duplicates
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* curr = head;
    do {
        struct Node* temp = curr;
        while (temp->next != head) {
            if (temp->next->data == curr->data) {
                struct Node* dup = temp->next;
                temp->next = temp->next->next;
                free(dup);
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    } while (curr->next != head);
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtBeginning(&head, 50);
    
    printf("List: ");
    traverseList(head);

    findMiddleNode(head);
    
    deleteAtPosition(&head, 2);
    printf("After deletion at position 2: ");
    traverseList(head);

    return 0;
}
