#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(int i){
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] > heap[i]){
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapify_down(int i){
    while(1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if(l < size && heap[l] < heap[smallest]) smallest = l;
        if(r < size && heap[r] < heap[smallest]) smallest = r;

        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int x){
    heap[size] = x;
    heapify_up(size);
    size++;
}

int extractMin(){
    if(size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify_down(0);
    return min;
}

int peek(){
    if(size == 0) return -1;
    return heap[0];
}

int main(){
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op,"insert") == 0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin") == 0){
            printf("%d\n", extractMin());
        }
        else if(strcmp(op,"peek") == 0){
            printf("%d\n", peek());
        }
    }

    return 0;
}