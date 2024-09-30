
// 1.   createNode

// 2.a  insertAtBeginning
// 2.b  insertAtEnd
// 2.c  insertAtPosition
// 2.d  insertAfterNode

// 3.a  deleteAtBeginning
// 3.b  deleteAtEnd
// 3.c  deleteAtPosition
// 3.d  deleteNode

// 4.   searchNode
// 5.a  traversalList_forward  (for single and double both)
// 5.b  traversalList_backward (for double both)
// 6.   lengthOfList
// 7.   reverseList
// 8.   findMiddleNode
// 9.   detectLoop
// 10.  removeDuplicates

// 11.  Any other important operation


// format of all functions like :
// 3.c Delete at a specific position
struct Node* deleteAtPosition(struct Node* head, int position) {
    // CASE 1 : if head is null or position is less than 1
    if (head == NULL || position < 1) {
        return head;
    } 
    // CASE 2 : if first position
    else  if (position == 1) {
                return deleteAtBeginning(head);
    } 
    // CASE 3 : If valid position
    else {
        struct Node* current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        
        if (current == NULL || current->next == NULL) {
            printf("Position out of range\n");
            return head;
        }
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        return head;
            
    }
}