/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.*/
#include <stdio.h>  
int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrixA[m][n], matrixB[m][n], result[m][n];
    
    printf("Enter the elements of the first matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    printf("Enter the elements of the second matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    

    printf("Resultant matrix after addition:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
