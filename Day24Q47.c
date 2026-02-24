/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated
*/
#include <stdio.h>
#include <stdlib.h>

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

void deleteKey(struct Node** head, int key){
    struct Node* temp = *head;  
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL){
        prev->next = temp->next;
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

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++){
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    deleteKey(&head, key);

    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}