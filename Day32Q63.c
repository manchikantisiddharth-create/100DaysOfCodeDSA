/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom*/
#include <stdio.h>

int main() {
    int stack[100];
    int top = -1;
    int n, m, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    scanf("%d", &m);

    top = top - m;
    if (top < -1)
        top = -1;

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}