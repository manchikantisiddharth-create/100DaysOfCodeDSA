#include <stdio.h>

void rotate(int arr[], int n, int k) {
    if (n == 0) return;
    
    k = k % n;
    
    int temp[1000];
    
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;
    
    scanf("%d", &n);
    
    int arr[1000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    rotate(arr, n, k);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
