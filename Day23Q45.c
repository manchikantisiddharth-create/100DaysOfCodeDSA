/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode; 
    }
}
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2){
    struct Node* mergedhead = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            insert(&mergedhead, temp1->data);
            temp1 = temp1->next;
        }
        else{
            insert(&mergedhead, temp2->data);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insert(&mergedhead, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insert(&mergedhead, temp2->data);
        temp2 = temp2->next;
    }
    return mergedhead;
}
int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, m;

    printf("Enter the number of integers in the first list: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter %d elements for the first list separated by space: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
        insert(&head1, arr1[i]);
    }

    printf("Enter the number of integers in the second list: ");
    scanf("%d", &m);
    int arr2[m];
    printf("Enter %d elements for the second list separated by space: ", m);
    for(int i = 0; i < m; i++){
        scanf("%d", &arr2[i]);
        insert(&head2, arr2[i]);
    }

    struct Node* mergedHead = mergeSortedLists(head1, head2);

    printf("Merged sorted linked list: ");
    struct Node* temp = mergedHead;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    return 0;
}   