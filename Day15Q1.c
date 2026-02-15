#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    int limit = (m < n) ? m : n;

    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);

    return 0;
}
