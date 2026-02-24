#include<stdio.h>
#include<stdlib.h>
struct Node{ 
    int data;
    struct Node* next;
};
void insert(struct Node** head, int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=newNode;
    }
    }
void deleteKey(struct Node** head, int key){
    struct Node* temp = *head;  
    struct Node* prev = NULL;
    if (*head == NULL)
    return;
    if(temp != NULL && temp->data==key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev=temp;
        temp=temp->next;

    }
    if(temp != NULL){
        prev->next=temp->next;
        free(temp);
    }
}
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    struct Node* head = NULL;
    int n, key;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }
    scanf("%d", &key);
    deleteKey(&head, key);
    printList(head);
    return 0;
}