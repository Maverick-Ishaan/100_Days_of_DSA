#include <stdio.h>
#include <stdlib.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    if (scanf("%d", &n) != 1) return 0;

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (scanf("%d", &k) != 1) {
        free(nums);
        return 0;
    }

    k = k % n;

    if (k > 0) {
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], (i == n - 1 ? "" : " "));
    }
    printf("\n");

    free(nums);
    return 0;
}
