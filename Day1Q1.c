#include <stdio.h>

int main() {
    int n, pos, x;

    // Input the size of the array
    if (scanf("%d", &n) != 1) return 1;

    // Initialize array with enough space for the extra element
    int arr[n + 1];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position and the element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    // We start from the end to avoid losing data
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the 0-indexed position
    arr[pos - 1] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}
