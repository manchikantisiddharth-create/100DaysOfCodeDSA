/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int getMinIndex() {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int deleteElement() {
    if (size == 0)
        return -1;

    int minIndex = getMinIndex();
    int value = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return value;
}

int peek() {
    if (size == 0)
        return -1;

    int minIndex = getMinIndex();
    return pq[minIndex];
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }

        else if (strcmp(op, "delete") == 0) {
            int val = deleteElement();
            printf("%d\n", val);
        }

        else if (strcmp(op, "peek") == 0) {
            int val = peek();
            printf("%d\n", val);
        }
    }

    return 0;
}