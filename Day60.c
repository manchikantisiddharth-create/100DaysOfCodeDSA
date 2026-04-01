#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[i] > arr[left])
            return false;
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    if (isMinHeap(arr, N))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}