/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated*/
#include <stdio.h>
int main() {
    int n, i, j = 0; 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the sorted array: ");
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Unique elements: ");
    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}