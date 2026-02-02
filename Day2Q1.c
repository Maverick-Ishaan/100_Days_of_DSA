#include <stdio.h>

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        return; 
    }

    int indexToRemove = pos - 1;

    for (int i = indexToRemove; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main() {
    int n, pos;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

    deleteElement(arr, &n, pos);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
