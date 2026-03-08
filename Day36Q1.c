#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;

    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;
    int current_size = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        queue[rear] = val;
        rear = (rear + 1) % n;
        current_size++;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (current_size > 0) {
            front = (front + 1) % n;
            current_size--;
        }
    }

    for (int i = 0; i < current_size; i++) {
        printf("%d", queue[(front + i) % n]);
        if (i < current_size - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(queue);
    return 0;
}
