// 1. Singly Linked List (Non-Circular)
void bubbleSortSingly(struct Node* head) {
    if (!head || !head->next) return;
    for (struct Node* i = head; i->next; i = i->next)
        for (struct Node* j = head; j->next; j = j->next)
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
}

// 2. Singly Linked List (Circular)
void bubbleSortSinglyCircular(struct Node* head) {
    if (!head || head->next == head) return;
    struct Node* end = head;
    do {
        for (struct Node* i = head; i->next != head && i->next != end; i = i->next)
            if (i->data > i->next->data) {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        end = end->next;
    } while (end != head);
}

// 3. Doubly Linked List (Non-Circular)
void bubbleSortDoubly(struct DNode* head) {
    if (!head || !head->next) return;
    for (struct DNode* i = head; i->next; i = i->next)
        for (struct DNode* j = head; j->next; j = j->next)
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
}

// 4. Doubly Linked List (Circular)
void bubbleSortDoublyCircular(struct DNode* head) {
    if (!head || head->next == head) return;
    struct DNode* end = head->prev;
    do {
        for (struct DNode* i = head; i != end; i = i->next)
            if (i->data > i->next->data) {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        end = end->prev;
    } while (end != head->prev);
}