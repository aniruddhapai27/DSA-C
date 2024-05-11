#include<stdio.h>
#include<stdlib.h>

void insertatpos(int* p, int capacity, int *size, int pos, int val);
void deletebypos(int*p, int capacity, int *size, int pos);
void insertbykey(int *p, int capacity, int *size, int key, int val);
void deletebykey(int*p, int *size, int key);
void insertbyord(int* p, int *size,int val);
void searchbypos(int* p, int *size,int pos);
void searchbykey(int *p, int n, int key);
void reverse(int* p, int *size);
void display(int *p, int size);

int main(){
    int* p;
    int capacity, n;
    int pos, val, key, choice;
    printf("Enter capacity: ");
    scanf("%d",&capacity);
    printf("Enter size: ");
    scanf("%d",&n);
    p = (int*)malloc(capacity*sizeof(int));

    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
    }

    do{
        printf("\n1- Insert by position\n");
        printf("2- Delete by position\n");
        printf("3- Insert by key\n");
        printf("4- Delete by key\n");
        printf("5- Insert by order\n");
        printf("6- Search by key\n");
        printf("7- Search by position\n");
        printf("8- Reverse\n");
        printf("9- Exit\n");
        printf("Enter choice: \n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter position and value to insert: \n");
            scanf("%d%d",&pos, &val);
            insertatpos(p, capacity, &n, pos, val);
            break;   
        case 2:
            printf("Enter the position to delte: ");
            scanf("%d",&pos);
            deletebypos(p, capacity, &n, pos);
            break;
        case 3:
            printf("Enter the key: ");
            scanf("%d",&key);
            printf("Enter the value to replace with key: ");
            scanf("%d",&val);
            insertbykey(p, capacity, &n, key, val);
            break;
        case 4:
            printf("Enter the key to delete: ");
            scanf("%d",&key);
            deletebykey(p,&n,key);
            break;
        case 5:
            printf("Enter the value to insert by order: ");
            scanf("%d",&val);
            insertbyord(p , &n, val);
            break;
        case 6:
            printf("Enter the key to search: ");
            scanf("%d",&key);
            searchbykey(p, n, key);
            break;
        case 7:
            printf("Enter position to search: ");
            scanf("%d",&pos);
            searchbypos(p, &n, pos);
            break;
        case 8:
            printf("The Reversed array is:\n");
            reverse(p, &n);
            break;
        case 9: 
            printf("Exiting...\n");
            return 0;
        }
        display(p, n);
    }while(choice!=9);
}

void insertatpos(int* p, int capacity, int *size, int pos, int val){
    if(pos>*size || pos>capacity){
        printf("Invalid position\n");
        return;
    }
    if(*size >= capacity){
        printf("Array is full\n");
        return;
    }

    for(int i=*size-1;i>=pos;i--){
        p[i+1] = p[i];
    }

    p[pos] = val;
    *size+=1;
}

void display(int *p, int size){
    for(int i=0;i<size;i++){
        printf("%d ",p[i]);
    }

}

void insertbykey(int *p, int capacity, int *size, int key, int val) {
    if(*size >= capacity){
        printf("Array is full\n");
        return;
    }

    for (int i = 0; i < *size; i++) {
        if (p[i] == key) {
            p[i] = val;
            printf("Element %d replaced with %d\n", key, val);
            return;
        }
    }

        printf("Key not found\n");
}

void deletebykey(int*p, int *size, int key){
    int pos=-1;
    for(int i=0;i<*size;i++){
        if(p[i] == key){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Key element is not found\n");
        return;
    }
    for(int i=pos;i<*size;i++){
        p[i] = p[i+1];
    }
    *size-=1;
}

void searchbypos(int* p, int *size,int pos){
    if(pos<0 || pos>*size-1){
        printf("Invalid position\n");
        return;
    }
    printf("The value at position %d is :%d\n",pos,p[pos]);
}

void reverse(int* p, int *size){
    for(int i=*size-1;i>=0;i--){
        printf("%d ",p[i]);
    }
    printf("\n");
}

void insertbyord(int* p, int *size, int val){
    int i;
    for(i=*size-1;i>=0 && p[i]>val;i--){
        p[i+1] = p[i];
    }
    p[i+1] = val;
    *size+=1;
}

void deletebypos(int*p, int capacity, int *size, int pos){
    if(pos>*size-1 || pos>capacity){
        printf("Invalid position\n");
        return;
    }
    for(int i=pos;i<*size;i++){
        p[i] = p[i+1];
    }
    *size-=1;
}
void searchbykey(int *p, int size, int key){
    for(int i=0;i<size;i++){
        if(p[i] == key){
            printf("Key is found at position %d\n",i);
            return;
        }

    }
    printf("Key is not found\n");
}