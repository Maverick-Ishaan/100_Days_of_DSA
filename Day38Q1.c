#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

bool empty(Deque *dq) {
    return dq->size == 0;
}

int size(Deque *dq) {
    return dq->size;
}

void push_front(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque *dq, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

void pop_front(Deque *dq) {
    if (empty(dq)) return;
    Node *temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
}

void pop_back(Deque *dq) {
    if (empty(dq)) return;
    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
}

int front(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->front->data;
}

int back(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->rear->data;
}

void clear(Deque *dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void reverse(Deque *dq) {
    if (empty(dq)) return;
    Node *curr = dq->front;
    Node *temp = NULL;
    dq->rear = dq->front;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        dq->front = curr;
        curr = curr->prev;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sort(Deque *dq) {
    if (dq->size < 2) return;
    int *arr = (int*)malloc(dq->size * sizeof(int));
    Node *curr = dq->front;
    for (int i = 0; i < dq->size; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }
    qsort(arr, dq->size, sizeof(int), compare);
    curr = dq->front;
    for (int i = 0; i < dq->size; i++) {
        curr->data = arr[i];
        curr = curr->next;
    }
    free(arr);
}

void printDeque(Deque *dq) {
    Node *curr = dq->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque *dq = createDeque();

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_back(dq, 15);

    printf("Front: %d, Back: %d, Size: %d\n", front(dq), back(dq), size(dq));
    
    sort(dq);
    printf("Sorted: ");
    printDeque(dq);

    reverse(dq);
    printf("Reversed: ");
    printDeque(dq);

    pop_front(dq);
    pop_back(dq);
    printf("After pops: ");
    printDeque(dq);

    clear(dq);
    printf("Is empty: %s\n", empty(dq) ? "Yes" : "No");

    free(dq);
    return 0;
}
