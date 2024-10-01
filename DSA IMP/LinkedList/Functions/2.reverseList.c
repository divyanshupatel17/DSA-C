// 1. Singly Linked List (Non-Circular)
struct Node* reverseSingly(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. Singly Linked List (Circular)
struct Node* reverseSinglyCircular(struct Node* head) {
    if (!head) return NULL;
    struct Node *prev = NULL, *curr = head, *next;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);
    head->next = prev;
    return prev;
}

// 3. Doubly Linked List (Non-Circular)
struct DNode* reverseDoubly(struct DNode* head) {
    struct DNode *temp, *curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        head = curr;
        curr = curr->prev;
    }
    return head;
}

// 4. Doubly Linked List (Circular)
struct DNode* reverseDoublyCircular(struct DNode* head) {
    if (!head) return NULL;
    struct DNode *curr = head, *temp;
    do {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    } while (curr != head);
    return head->prev;
}