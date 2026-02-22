/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result*/
#include<Stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node**head, int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){

        *head=newNode;
    }
    else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void countNodes(struct Node* head){
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Number of nodes in the linked list: %d\n", count);
}

int main(){
    struct Node* head=NULL;
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements separated by space: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        insert(&head, arr[i]);
    }
    countNodes(head);
    return 0;
}