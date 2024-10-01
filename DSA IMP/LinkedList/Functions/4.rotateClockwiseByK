Rotate clockwise by k

// 1. Singly Linked List (Non-Circular)
struct Node* rotateSingly(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct Node *curr = head, *new_head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    curr->next = head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    new_head = curr->next;
    curr->next = NULL;
    return new_head;
}

// 2. Singly Linked List (Circular)
struct Node* rotateSinglyCircular(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct Node *curr = head;
    int len = 1;
    while (curr->next != head) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    head = curr->next;
    return head;
}

// 3. Doubly Linked List (Non-Circular)
struct DNode* rotateDoubly(struct DNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct DNode *curr = head, *new_head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    new_head = head;
    for (int i = 0; i < len - k; i++) {
        new_head = new_head->next;
    }
    curr->next = head;
    head->prev = curr;
    head = new_head;
    head->prev->next = NULL;
    head->prev = NULL;
    return head;
}

// 4. Doubly Linked List (Circular)
struct DNode* rotateDoublyCircular(struct DNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct DNode *curr = head;
    int len = 1;
    while (curr->next != head) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    head = curr->next;
    return head;
}