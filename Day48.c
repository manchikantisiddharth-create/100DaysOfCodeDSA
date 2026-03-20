//day48
#include <stdio.h>

int countLeafNodes(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            continue;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if both children are absent
        if ((left >= n || arr[left] == -1) &&
            (right >= n || arr[right] == -1)) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countLeafNodes(arr, n);
    printf("%d\n", result);

    return 0;
}