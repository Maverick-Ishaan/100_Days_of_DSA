#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Greedy function: Returns 1 (true) if we can place k cows 
// with at least 'mid' distance between them.
int canPlaceCows(int stalls[], int n, int k, int mid) {
    int count = 1; // Place first cow in the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= mid) {
            count++;
            lastPos = stalls[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    
    // Read n and k
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *stalls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stall positions using qsort
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search on the minimum distance
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;     // Try for a larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // Distance too large, shrink it
        }
    }

    printf("%d\n", ans);

    free(stalls);
    return 0;
}
