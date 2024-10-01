Concat

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

// 1. Singly Linked List (non-circular)
void concat_singly_linked_lists(SinglyNode** list1, SinglyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else {
        SinglyNode* current = *list1;
        while (current->next) {
            current = current->next;
        }
        current->next = *list2;
    }
    *list2 = NULL;  // The second list is now empty
}

// 2. Singly Linked List (circular)
void concat_circular_singly_linked_lists(SinglyNode** list1, SinglyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        SinglyNode* last1 = *list1;
        while (last1->next != *list1) {
            last1 = last1->next;
        }
        SinglyNode* last2 = *list2;
        while (last2->next != *list2) {
            last2 = last2->next;
        }
        last1->next = *list2;
        last2->next = *list1;
    }
    *list2 = NULL;  // The second list is now empty
}

// 3. Doubly Linked List (non-circular)
void concat_doubly_linked_lists(DoublyNode** list1, DoublyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        DoublyNode* last1 = *list1;
        while (last1->next) {
            last1 = last1->next;
        }
        last1->next = *list2;
        (*list2)->prev = last1;
    }
    *list2 = NULL;  // The second list is now empty
}

// 4. Doubly Linked List (circular)
void concat_circular_doubly_linked_lists(DoublyNode** list1, DoublyNode** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        DoublyNode* last1 = (*list1)->prev;
        DoublyNode* last2 = (*list2)->prev;

        last1->next = *list2;
        (*list2)->prev = last1;
        last2->next = *list1;
        (*list1)->prev = last2;
    }
    *list2 = NULL;  // The second list is now empty
}

// Helper function to create a new singly linked node
SinglyNode* create_singly_node(int data) {
    SinglyNode* new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to create a new doubly linked node
DoublyNode* create_doubly_node(int data) {
    DoublyNode* new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Main function to demonstrate usage
int main() {
    // Example usage would go here
    // For brevity, actual list creation and concatenation calls are omitted
    printf("Linked list concatenation functions with double pointers implemented.\n");
    return 0;
}