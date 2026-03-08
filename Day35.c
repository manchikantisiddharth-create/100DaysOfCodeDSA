/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,m,x,i;
    struct node *front=NULL,*rear=NULL,*temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        if(front==NULL){
            front=rear=temp;
            rear->next=front;
        }else{
            rear->next=temp;
            rear=temp;
            rear->next=front;
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        if(front==NULL) break;
        if(front==rear){
            free(front);
            front=rear=NULL;
        }else{
            temp=front;
            front=front->next;
            rear->next=front;
            free(temp);
        }
    }
    if(front!=NULL){
        temp=front;
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=front);
    }
    return 0;
}