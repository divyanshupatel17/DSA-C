Split in Even Odd

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

// 1. Split even-odd for Singly Linked List (non-circular)
void split_even_odd_singly(SinglyNode* head, SinglyNode** even, SinglyNode** odd) {
    *even = *odd = NULL;
    SinglyNode *e_tail = NULL, *o_tail = NULL;
    int index = 0;
    while (head) {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = head;
            else e_tail = e_tail->next = head;
        } else {
            if (!*odd) *odd = o_tail = head;
            else o_tail = o_tail->next = head;
        }
        head = head->next;
        index++;
    }
    if (e_tail) e_tail->next = NULL;
    if (o_tail) o_tail->next = NULL;
}

// 2. Split even-odd for Singly Linked List (circular)
void split_even_odd_singly_circular(SinglyNode* head, SinglyNode** even, SinglyNode** odd) {
    if (!head) {
        *even = *odd = NULL;
        return;
    }
    *even = *odd = NULL;
    SinglyNode *e_tail = NULL, *o_tail = NULL;
    SinglyNode* curr = head;
    int index = 0;
    do {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = curr;
            else e_tail = e_tail->next = curr;
        } else {
            if (!*odd) *odd = o_tail = curr;
            else o_tail = o_tail->next = curr;
        }
        curr = curr->next;
        index++;
    } while (curr != head);
    if (e_tail) e_tail->next = *even;
    if (o_tail) o_tail->next = *odd;
}

// 3. Split even-odd for Doubly Linked List (non-circular)
void split_even_odd_doubly(DoublyNode* head, DoublyNode** even, DoublyNode** odd) {
    *even = *odd = NULL;
    DoublyNode *e_tail = NULL, *o_tail = NULL;
    int index = 0;
    while (head) {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = head;
            else {
                e_tail->next = head;
                head->prev = e_tail;
                e_tail = head;
            }
        } else {
            if (!*odd) *odd = o_tail = head;
            else {
                o_tail->next = head;
                head->prev = o_tail;
                o_tail = head;
            }
        }
        head = head->next;
        index++;
    }
    if (e_tail) e_tail->next = NULL;
    if (o_tail) o_tail->next = NULL;
    if (*even) (*even)->prev = NULL;
    if (*odd) (*odd)->prev = NULL;
}

// 4. Split even-odd for Doubly Linked List (circular)
void split_even_odd_doubly_circular(DoublyNode* head, DoublyNode** even, DoublyNode** odd) {
    if (!head) {
        *even = *odd = NULL;
        return;
    }
    *even = *odd = NULL;
    DoublyNode *e_tail = NULL, *o_tail = NULL;
    DoublyNode* curr = head;
    int index = 0;
    do {
        if (index % 2 == 0) {
            if (!*even) *even = e_tail = curr;
            else {
                e_tail->next = curr;
                curr->prev = e_tail;
                e_tail = curr;
            }
        } else {
            if (!*odd) *odd = o_tail = curr;
            else {
                o_tail->next = curr;
                curr->prev = o_tail;
                o_tail = curr;
            }
        }
        curr = curr->next;
        index++;
    } while (curr != head);
    if (*even) {
        e_tail->next = *even;
        (*even)->prev = e_tail;
    }
    if (*odd) {
        o_tail->next = *odd;
        (*odd)->prev = o_tail;
    }
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
    printf("Split even-odd functions for all four types of linked lists implemented.\n");
    return 0;
}