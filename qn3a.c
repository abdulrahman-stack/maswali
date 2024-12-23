#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                struct Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(12);
    head->next->next = newNode(11);
    head->next->next->next = newNode(11);
    head->next->next->next->next = newNode(12);
    head->next->next->next->next->next = newNode(11);
    head->next->next->next->next->next->next = newNode(10);

    printf("Linked list before removing duplicates:\n");
    printList(head);

    head = removeDuplicates(head);

    printf("\nLinked list after removing duplicates:\n");
    printList(head);

    return 0;
}