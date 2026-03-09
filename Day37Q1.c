#include <stdio.h>
#include <stdlib.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    heap[size] = val;
    int curr = size;
    size++;
    
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    
    int curr = 0;
    while (2 * curr + 1 < size) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = left;
        
        if (right < size && heap[right] < heap[left]) {
            smallest = right;
        }
        
        if (heap[curr] <= heap[smallest]) {
            break;
        }
        
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char op[10];
    int val;
    
    while (n--) {
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        } else if (op[0] == 'd') {
            delete();
        } else if (op[0] == 'p') {
            peek();
        }
    }
    
    return 0;
}
