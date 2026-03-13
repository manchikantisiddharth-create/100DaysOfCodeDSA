#include <stdio.h>
#include <string.h>

int dq[1000];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (isEmpty()) {
        front = rear = 0;
        dq[front] = x;
    } else {
        for (int i = rear; i >= front; i--)
            dq[i + 1] = dq[i];
        dq[front] = x;
        rear++;
    }
}

void push_back(int x) {
    if (isEmpty()) {
        front = rear = 0;
        dq[rear] = x;
    } else {
        dq[++rear] = x;
    }
}

int pop_front() {
    if (isEmpty()) return -1;
    int val = dq[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;
    int val = dq[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return val;
}

int get_front() {
    if (isEmpty()) return -1;
    return dq[front];
}

int get_back() {
    if (isEmpty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
            printf("Inserted %d at front\n", x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
            printf("Inserted %d at back\n", x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        }
        else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(op, "clear") == 0) {
            clear();
            printf("Deque cleared\n");
        }
    }

    return 0;
}
