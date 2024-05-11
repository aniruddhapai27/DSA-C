//Design 1: Enqueue is normal, search done while dequeue
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue* q, int val) {
    q->size = val;
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}


void enqueue(struct queue* q, int val) {
    if(q->rear == q->size-1){
        printf("Overflow\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    int j = q->rear;
    while(j>=q->front && val < q->Q[j]){
        q->Q[j+1] = q->Q[j];
        j--;
    }
    q->rear++;
    q->Q[j+1] = val;
}


int dequeue(struct queue* q) {
    if(q->front == -1 ) {
        printf("Underflow\n");
        return -1;
    }
    int x = q->Q[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;   
    }
    else{
        q->front = (q->front+1)%q->size;
    }
    return x;
}

void display(struct queue* q){
    if(q->front == -1 || q->front > q->rear){
        printf("Queue underflow\n");
        return;
    }
    for(int i=q->front;i<= q->rear;i++){
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}


int main(){
    struct queue q;
    int size;
    printf("Enter size of the queue: ");
    scanf("%d",&size);
    create(&q, size);
    int choice, val;
    do{
        printf("\n1- Enqueue\n2- Dequeue\n3- Display\n4- Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if(val == -1) {
                    printf("Queue underflow");
                }
                else {
                    printf("Deleted element is: %d\n",val);
                }
                break;
            case 3:
                printf("Queue is: \n");
                display(&q);
                break;
            case 4:
                printf("Exiting");
                return 0;
        }
    }while(choice != 4);
}