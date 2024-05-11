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

void insertatrear(struct queue* q, int val) {
    if(q->front == -1) {
        q->front = 0;
        q->Q[++q->rear] = val;
    }
    else if(q->rear != q->size-1) {
        q->Q[++q->rear] = val;
        
    }
    else {
        printf("Rear insertion not possible\n");
    }
}

void insertatfront(struct queue* q, int val){
    if(q->front == -1) {
        q->front = 0;
        q->Q[++q->rear] = val;
    }
    else if(q->front > 0) {
        q->Q[--q->front] = val;
    }
    else{
        printf("Front insertion not possible\n");
    }
}

int deleteatfront(struct queue* q) {
    if(q->front == -1) {
        printf("Underflow\n");
        return -1;
    }
    int x = q->Q[q->front++];
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return x;
}

int deleteatrear(struct queue* q) {
    if(q->front == -1) {
        printf("Underflow\n");
        return -1;
    }
    int x = q->Q[q->rear--];
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return x;
}

void display(struct queue* q) {
    if(q->front == -1) {
        printf("Underflow\n");
        return;
    }
    for(int i=q->front; i<=q->rear; i++) {
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
        printf("\n1- Insert front\n2- Insert rear\n3- Delete front\n4- Delete rear\n5- Display\n6- Exit");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d",&val);
                insertatfront(&q, val);
                break;
          
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d",&val);
                insertatrear(&q, val);
                break;
                  
            case 3:
                val = deleteatfront(&q);
                printf("Deleted element is: %d\n",val);
                break;

            case 4:
                val = deleteatrear(&q);
                printf("Deleted element is: %d\n",val);
                break;
                
            case 5:
                printf("Queue is: \n");
                display(&q);
                break;

            case 6:
                printf("Exiting");
                return 0;
        }
        display(&q);
    }while(choice != 6 );
}