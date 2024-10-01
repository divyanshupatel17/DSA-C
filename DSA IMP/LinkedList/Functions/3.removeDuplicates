// 1. Singly Linked List (Non-Circular)
void removeDuplicatesSingly(struct Node* head) {
    struct Node *curr, *runner, *temp;
    for (curr = head; curr && curr->next; curr = curr->next) {
        for (runner = curr; runner->next;) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
    }
}

// 2. Singly Linked List (Circular)
void removeDuplicatesSinglyCircular(struct Node** head) {
    if (!*head) return;
    struct Node *curr = *head, *runner, *temp;
    do {
        runner = curr;
        while (runner->next != *head) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                if (temp == *head) *head = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    } while (curr != *head);
}

// 3. Doubly Linked List (Non-Circular)
void removeDuplicatesDoubly(struct DNode* head) {
    struct DNode *curr, *runner, *temp;
    for (curr = head; curr && curr->next; curr = curr->next) {
        for (runner = curr; runner->next;) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                if (temp->next) temp->next->prev = runner;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
    }
}

// 4. Doubly Linked List (Circular)
void removeDuplicatesDoublyCircular(struct DNode** head) {
    if (!*head) return;
    struct DNode *curr = *head, *runner, *temp;
    do {
        runner = curr;
        while (runner->next != *head) {
            if (curr->data == runner->next->data) {
                temp = runner->next;
                runner->next = temp->next;
                temp->next->prev = runner;
                if (temp == *head) *head = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    } while (curr != *head);
}