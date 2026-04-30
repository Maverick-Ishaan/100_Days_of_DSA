#include <stdio.h>
#include <stdbool.h>

// Function to check if a distribution is possible with 'maxPages' limit
bool isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book is larger than the limit, it's impossible
        if (arr[i] > maxPages) return false;

        if (currentSum + arr[i] > maxPages) {
            // Assign to next student
            studentsRequired++;
            currentSum = arr[i];

            if (studentsRequired > m) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    // If books are fewer than students, allocation is impossible 
    // based on the rule "each student gets at least one book"
    if (n < m) return -1;

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal; // Minimum possible "max pages"
    int high = sum;   // Maximum possible "max pages"
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;   // This capacity works, but try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;  // Capacity too small, increase it
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findPages(arr, n, m));

    return 0;
}
