/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero
*/
#include<Stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[1000];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int min_sum=1000000,num1,num2;
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n; j++){
            int sum=arr[i]+arr[j];
            if((sum)<(min_sum)){
                min_sum=sum;
                num1=arr[i];
                num2=arr[j];
            }
        }
}
printf("The pair of elements whose sum is closest to zero is: %d and %d\n", num1, num2);
return 0;
}