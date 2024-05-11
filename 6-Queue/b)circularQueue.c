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
    if((q->rear+1)%q->size == q->front) {
        printf("Overflow\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear+1)%q->size;  
    q->Q[q->rear] = val;
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
void display(struct queue* q) {
    if(q->front == -1 ) {
        printf("Underflow\n");
        return;
    }
    int i = q->front;
    while(i!=q->rear) {
        printf("%d ",q->Q[i]);
        i = (i+1)%q->size;
    }
    printf("%d \n",q->Q[i]);
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
                printf("Deleted element is: %d\n",val);
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