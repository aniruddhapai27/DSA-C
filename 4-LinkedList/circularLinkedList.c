#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct clist{
    struct node* head;
};

struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation not possible\n");
        exit(0);
    }
    newnode->data = val;
    newnode->link = NULL;
    return newnode;
}

void createlist(struct clist* list){
    struct node* h = createnode(0);
    list->head = h;
}

void display(struct clist* list){
    if(list->head->link == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* current = list->head->link;
    while(current->link!=list->head->link){
        printf("%d -> ",current->data);
        current = current->link;
    }
    printf("%d\n",current->data);
    printf("Number of nodes: %d\n",list->head->data);
}

void freelist(struct clist* list){
    if(list->head->link == NULL){
        free(list->head);
        free(list);
        return;
    }
    struct node* current = list->head->link;
    while(current->link != list->head->link){
        struct node* temp = current;
        current = current->link;
        free(temp);
    }
    free(current);
    free(list->head);
    free(list);
}

void insertatstart(struct clist* list, int val){
    struct node* new = createnode(val);
    if(list->head->link == NULL){
        list->head->link = new;
        new->link = new;
    }
    else{
        struct node* current = list->head->link;
        while(current->link!=list->head->link){
            current = current->link;
        }
        new->link = list->head->link;
        list->head->link = new;
        current->link = new;
    }
    list->head->data++;
}

void insertatend(struct clist* list, int val){
    struct node* new = createnode(val);
    if(list->head->link == NULL){
        list->head->link = new;
        new->link = new;
    }
    else{
        struct node* current = list->head->link;
        while(current->link!= list->head->link){
            current = current->link;
        }
        current->link = new;
        new->link = list->head->link;
    }
    list->head->data++;

}

void insertatpos(struct clist* list, int pos, int val){
    if(pos<0 || pos>list->head->data){
        printf("Invalid position\n");
        return;
    }
    if(pos == 0){
        insertatstart(list, val);
        return;
    }
    else if(pos == list->head->data){
        insertatend(list, val);
        return;
    }
    struct node* new = createnode(val);
    struct node* current = list->head->link;
    for(int i=1;i<pos;i++){
        current = current->link;
    }
    new->link = current->link;
    current->link = new;
    list->head->data++;

}

void deleteatstart(struct clist* list){
    if(list->head->link == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* temp = list->head->link;
    if(temp->link == list->head->link){
        free(temp);
        list->head->link = NULL;
    }
    else{
        struct node* tail = list->head->link;
        while(tail->link!=list->head->link){
            tail = tail->link;
        }
        tail->link = temp->link;
        list->head->link = temp->link;
        free(temp);
    }
    list->head->data--;
}

void deleteatend(struct clist* list){
    if(list->head->link == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* temp = list->head->link;
    if(temp->link == list->head->link){
        free(temp);
        list->head->link = NULL;
    }
    else{
        struct node* prev = NULL;
        while(temp->link!=list->head->link){
            prev = temp;
            temp = temp->link;
        }
        prev->link = list->head->link;
        free(temp);
    }
    list->head->data--;
}



void deleteatpos(struct clist* list, int pos){
    if(pos > list->head->data-1 || pos < 0){
            printf("Invalid position\n");
            return;
    }
    
    if(pos==0){
        deleteatstart(list);
        return;
    }
    else if(pos==list->head->data-1){
        deleteatend(list);
        return;
    }
    struct node* current = list->head->link;
    struct node* prev = NULL;
    for(int i=0;i<pos;i++){
        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
    list->head->data--;

}

int searchbykey(struct clist* list, int key){
    if(list->head->link == NULL){
        printf("Empty list\n");
        return -1;
    }
    struct node* current = list->head->link;
    int i=0;
    do{
        if(current->data == key){
            return i;
        }
        i++;
        current = current->link;
    }while(current != list->head->link);
    return -1;
}

void deletebykey(struct clist* list, int key){
    if(list->head->link == NULL){
        printf("Empty list\n");
        return;
    }
    int pos = searchbykey(list, key);
    if(pos==-1){
        printf("Key not found\n");
        return;
    }
    if(pos==0){
        deleteatstart(list);
        return;
    }
    else if(pos==list->head->data-1){
        deleteatend(list);
        return;
    }
    struct node* current = list->head->link;
    struct node* prev = NULL;
    for(int i=0;i<pos;i++){
        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
    list->head->data--;
}

void searchbypos(struct clist* list, int pos){
    if(pos<0 || pos>list->head->data-1){
        printf("Invalid position\n");
        return;
    }
    struct node* current = list->head->link;
    for(int i=0;i<pos;i++){
        current = current->link;
    }
    printf("Element at position %d is %d\n",pos,current->data);
    
}

void createordlist(struct clist* list, int val){
    struct node* current = list->head->link;
    if(list->head->link == NULL || current->data > val){
        insertatstart(list, val);
        return;
    }
    
    while(current->link!=list->head->link && val>current->link->data){
            current = current->link; 
    }
    if(current->link == list->head->link){
        insertatend(list, val);
        return; 
    }

    struct node* new = createnode(val);
    new->link = current->link;
    current->link = new;
    list->head->data++;
    
}

void reverse(struct clist* list) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* current = list->head->link;
    struct node* next = NULL;
    struct node* prev = NULL;
    do {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }while(current != list->head->link);

    list->head->link->link = prev;
    list->head->link = prev;

}

void copylist(struct clist* list, struct clist* newlist) {
    if(list->head->link == NULL) {
        return;
    }
    struct node* current = list->head->link;
    struct node* tail = newlist->head;

    do {
        struct node* newnode = createnode(current->data);
        tail->link = newnode;
        tail = tail->link;
        current = current->link;
        

    }while(current != list->head->link);

    tail->link = newlist->head->link;
    newlist->head->data = list->head->data;
}




int main(){
    struct clist mylist;
    createlist(&mylist);
    struct clist newlist; // for copylist operation
    int choice, val, pos, key;
    do{
        printf("1 -Insert at start\n");
        printf("2 -Insert at end\n");
        printf("3 -Insert at position\n");
        printf("4 -Delete at start\n");
        printf("5 -Delete at end\n");
        printf("6 -Delete at position\n");
        printf("7 -Search by key\n");
        printf("8 -Delete by key\n");
        printf("9 -Search by Position\n");
        printf("10 -Create ordered list\n");
        printf("11 -Reverse list\n");
        printf("12 -Copy list\n");
        printf("13 -Display list\n");
        printf("14 -Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to insert at start: ");
                scanf("%d",&val);
                insertatstart(&mylist, val);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d",&val);
                insertatend(&mylist, val);
                break;
            case 3:
                printf("Enter position and value to insert: ");
                scanf("%d%d",&pos,&val);
                insertatpos(&mylist, pos, val);
                break;
            case 4:
                deleteatstart(&mylist);
                break;
            case 5:
                deleteatend(&mylist);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d",&pos);
                deleteatpos(&mylist, pos);
                break;
            case 7:
                printf("Enter the key to search: ");
                scanf("%d",&key);
                int i=searchbykey(&mylist, key);
                if(i==-1){
                    printf("Key element not found\n");
                }
                else{
                printf("The key element is found at position %d\n",i);
                }
                break;
            case 8:
                printf("Enter the key to delete: ");
                scanf("%d",&key);
                deletebykey(&mylist, key);
                break;
            case 9:
                printf("Enter the position to search: ");
                scanf("%d",&pos);
                searchbypos(&mylist, pos);
                break;
            case 10:
                printf("Enter the element to insert in order: ");
                scanf("%d",&val);
                createordlist(&mylist, val);
                break;
            case 11:
                reverse(&mylist);
                break;
            case 12:
                createlist(&newlist);
                copylist(&mylist, &newlist);
                display(&newlist);
                freelist(&newlist);
                break;

            case 13:
                display(&mylist);
                break;
            
            case 14:
                freelist(&mylist);
                return 0;
        }
        

    }while(choice != 14);

    
}