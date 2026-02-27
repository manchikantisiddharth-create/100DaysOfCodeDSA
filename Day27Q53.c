/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Append node
void append(struct Node** head, int val) {
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection using length method
int getIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    printf("\nLength of First List: %d\n", len1);
    printf("Length of Second List: %d\n", len2);

    int diff = abs(len1 - len2);

    struct Node* longer = (len1 > len2) ? head1 : head2;
    struct Node* shorter = (len1 > len2) ? head2 : head1;

    printf("Advancing longer list by %d nodes...\n", diff);

    for (int i = 0; i < diff; i++)
        longer = longer->next;

    printf("Traversing both lists simultaneously...\n");

    while (longer != NULL && shorter != NULL) {

        if (longer->data == shorter->data)
            return longer->data;

        longer = longer->next;
        shorter = shorter->next;
    }

    return -1;
}

int main() {

    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head1, val);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        append(&head2, val);
    }

    printf("\nFirst Linked List:\n");
    printList(head1);

    printf("Second Linked List:\n");
    printList(head2);

    int result = getIntersection(head1, head2);

    printf("\nResult:\n");
    if (result != -1)
        printf("Intersection Point Value: %d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}