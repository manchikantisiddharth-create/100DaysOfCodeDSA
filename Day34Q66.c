/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char postfix[100];
    char *token;
    int op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    token = strtok(postfix, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            op2 = pop();
            op1 = pop();

            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("Result = %d\n", pop());

    return 0;
}