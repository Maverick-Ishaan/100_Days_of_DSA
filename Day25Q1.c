#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) {
        if (n == 0) {
            scanf("%d", &key);
            printf("0\n");
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d\n", count);

    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
