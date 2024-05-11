#include<stdio.h>
#include<stdlib.h>

//Ordinary queue using static memory allocation
#define SIZE 10
typedef struct {
    int Q[SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int val){
    if(q->rear == SIZE-1){
        printf("Queue overflow\n");
        return;
    }
    if(q->front == -1)
        q->front = 0;
        
    q->Q[++q->rear] = val;
    
}

int dequeue(Queue* q){
    if(q->front==-1 || q->front>q->rear){
        return -1;
    }
    int item = q->Q[q->front++];
    return item;
}

int peek(Queue* q){
    if(q->front == -1 || q->front > q->rear){
        return -1;
    }
    return q->Q[q->front];
}

void display(Queue* q){
    if(q->front == -1 || q->front > q->rear){
        printf("Queue underflow\n");
        return;
    }
    printf("Queue is: \n");
    for(int i=q->front;i<= q->rear;i++){
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}


int main(){
    int c,val;
    Queue q;
    q.front = -1;
    q.rear = -1;
    
    do {
        printf("1- Enqueue\n");
        printf("2- Dequeue\n");
        printf("3- Peek\n");
        printf("4- Display\n");
        printf("5- Exit\n");
        printf("Enter choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if(val == -1) {
                    printf("Queue underflow\n");
                }
                else {
                    printf("Deleted element is: %d\n",val);
                }
                break;
            case 3:
                val = peek(&q);
                if(val == -1) {
                    printf("Queue underflow\n");
                }
                else {
                printf("Front element is: %d\n",val);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5: 
            printf("Exiting");
                break;
        }
    }while(c != 5);
}
