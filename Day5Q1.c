#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    if (scanf("%d", &p) != 1) return 0;
    int *arr1 = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    if (scanf("%d", &q) != 1) return 0;
    int *arr2 = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0;
    int first = 1;

    while (i < p && j < q) {
        if (!first) printf(" ");
        if (arr1[i] <= arr2[j]) {
            printf("%d", arr1[i++]);
        } else {
            printf("%d", arr2[j++]);
        }
        first = 0;
    }

    while (i < p) {
        if (!first) printf(" ");
        printf("%d", arr1[i++]);
        first = 0;
    }

    while (j < q) {
        if (!first) printf(" ");
        printf("%d", arr2[j++]);
        first = 0;
    }

    printf("\n");

    free(arr1);
    free(arr2);

    return 0;
}
