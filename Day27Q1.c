#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int n) {
    if (n <= 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        temp->next = createNode(val);
        temp = temp->next;
    }
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void findIntersection(struct Node* head1, struct Node* head2, int n, int m) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(n - m);

    if (n > m) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* head1 = buildList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* head2 = buildList(m);

    findIntersection(head1, head2, n, m);

    return 0;
}
