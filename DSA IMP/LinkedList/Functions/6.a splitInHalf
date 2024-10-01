Split in Half

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked lists
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

// Node structure for doubly linked lists
typedef struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

// 1. Split in half for Singly Linked List (non-circular)
void split_singly(SinglyNode** head, SinglyNode** second) {
    if (!*head || !(*head)->next) {
        *second = NULL;
        return;
    }
    SinglyNode *slow = *head, *fast = (*head)->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = NULL;
}

// 2. Split in half for Singly Linked List (circular)
void split_singly_circular(SinglyNode** head, SinglyNode** second) {
    if (!*head) return;
    SinglyNode *slow = *head, *fast = *head;
    while (fast->next != *head && fast->next->next != *head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = *head;
    SinglyNode* temp = *second;
    while (temp->next != *head) temp = temp->next;
    temp->next = *second;
}

// 3. Split in half for Doubly Linked List (non-circular)
void split_doubly(DoublyNode** head, DoublyNode** second) {
    if (!*head || !(*head)->next) {
        *second = NULL;
        return;
    }
    DoublyNode *slow = *head, *fast = (*head)->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = NULL;
    if (*second) (*second)->prev = NULL;
}

// 4. Split in half for Doubly Linked List (circular)
void split_doubly_circular(DoublyNode** head, DoublyNode** second) {
    if (!*head) return;
    DoublyNode *slow = *head, *fast = *head;
    while (fast->next != *head && fast->next->next != *head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *second = slow->next;
    slow->next = *head;
    (*head)->prev = slow;
    (*second)->prev = fast->next == *head ? fast : fast->next;
    (*second)->prev->next = *second;
}

// Helper function to create a singly linked node
SinglyNode* create_singly_node(int data) {
    SinglyNode* node = (SinglyNode*)malloc(sizeof(SinglyNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Helper function to create a doubly linked node
DoublyNode* create_doubly_node(int data) {
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

// Main function (for demonstration)
int main() {
    // Example usage would go here
    printf("Split-in-half functions for all four types of linked lists implemented.\n");
    return 0;
}