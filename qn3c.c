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
    while (current && current->next) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(3);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next->next = newNode(5);

    printf("List before removing duplicates: ");
    printList(head);

    head = removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}