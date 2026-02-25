/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
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
int countOccurrences(struct Node* head, int key){
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp=temp->next;
    }
    return count;
}
int main(){
    struct Node* head=NULL;
    int n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("Enter the key to count occurrences: "); 
    scanf("%d", &key);
    int result=countOccurrences(head, key);
    printf("%d", result);
    return 0;
}