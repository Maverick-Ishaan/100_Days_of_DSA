#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int items[1000];
    int front, rear;
};

struct Stack {
    int items[1000];
    int top;
};

void enqueue(struct Queue* q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    return q->items[++q->front];
}

void push(struct Stack* s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    return s->items[s->top--];
}

int main() {
    int n, val;
    struct Queue q;
    struct Stack s;
    
    q.front = -1;
    q.rear = -1;
    s.top = -1;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    while (q.front < q.rear) {
        push(&s, dequeue(&q));
    }

    q.front = -1;
    q.rear = -1;

    while (s.top != -1) {
        enqueue(&q, pop(&s));
    }

    for (int i = 0; i <= q.rear; i++) {
        printf("%d%s", q.items[i], (i == q.rear ? "" : " "));
    }

    return 0;
}
