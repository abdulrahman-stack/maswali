#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Dequeue {
    struct Node* front;
    struct Node* rear;
};

void initDequeue(struct Dequeue* dq) {
    dq->front = dq->rear = NULL;
}

int isEmpty(struct Dequeue* dq) {
    return (dq->front == NULL);
}

void insertFront(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->front != NULL) {
        dq->front->prev = newNode;
    }
    dq->front = newNode;

    if (dq->rear == NULL) {
        dq->rear = dq->front;
    }
}

void insertRear(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (dq->rear != NULL) {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
    }
    dq->rear = newNode;

    if (dq->front == NULL) {
        dq->front = dq->rear;
    }
}

int deleteFront(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return -1;
    }

    int data = dq->front->data;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return -1;
    }

    int data = dq->rear->data;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL;
    }

    free(temp);
    return data;
}

void printDequeue(struct Dequeue* dq) {
    struct Node* temp = dq->front;
    printf("Dequeue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Dequeue dq;
    initDequeue(&dq);

    insertFront(&dq, 10);
    insertFront(&dq, 20);
    insertRear(&dq, 30);
    insertRear(&dq, 40);

    printDequeue(&dq);

    printf("Deleted from front: %d\n", deleteFront(&dq));
    printf("Deleted from rear: %d\n", deleteRear(&dq));

    printDequeue(&dq);

    return 0;
}