//day35
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,x,i;
    struct node *front=NULL,*rear=NULL,*temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        if(front==NULL){
            front=rear=temp;
        }else{
            rear->next=temp;
            rear=temp;
        }
    }
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}