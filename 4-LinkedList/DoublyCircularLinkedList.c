#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* nlink;
    struct node* plink;
};

struct dlist{
    struct node* head;
};

struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation not possible\n");
        exit(0);
    }
    newnode->data = val;
    newnode->nlink = NULL;
    newnode->plink = NULL;
    return newnode;
}

void createlist(struct dlist* list){
    struct node* h = createnode(0);
    list->head = h;
}

void display(struct dlist* list){
    if(list->head->nlink == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* current = list->head->nlink;
    while(current->nlink!=list->head->nlink){
        printf("%d -> ",current->data);
        current = current->nlink;
    }
    printf("%d\n",current->data);
    printf("Number of nodes: %d\n",list->head->data);
}

void freelist(struct dlist* list){
    if(list->head->nlink == NULL){
        free(list->head);
        free(list);
        return;
    }
    struct node* current = list->head->nlink;
    while(current->nlink != list->head->nlink){
        struct node* temp = current;
        current = current->nlink;
        free(temp);
    }
    free(current);
    free(list->head);
    free(list);
}

void insertatstart(struct dlist* list, int val){
    struct node* new = createnode(val);
    if(list->head->nlink == NULL){
        list->head->nlink = new;
        new->nlink = new;
        new->plink = new;
    }
    else{
        struct node* tail = list->head->nlink->plink;
        new->nlink = list->head->nlink;
        new->plink = tail;
        list->head->nlink->plink = new;
        tail->nlink = new;
        list->head->nlink = new;
    }
    list->head->data++;
}

void insertatend(struct dlist* list, int val){
    struct node* new = createnode(val);
    if(list->head->nlink == NULL){
        list->head->nlink = new;
        new->nlink = new;
        new->plink = new;
    }
    else{
        struct node* tail = list->head->nlink->plink;
        tail->nlink = new;
        new->plink = tail;
        new->nlink = list->head->nlink;
        list->head->nlink->plink = new;
        
    }
    list->head->data++;

}

void insertatpos(struct dlist* list, int pos, int val){
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
    struct node* current = list->head->nlink;
    for(int i=1;i<pos;i++){
        current=current->nlink;
    }
    struct node* new = createnode(val);
    current->nlink->plink = new;
    new->nlink = current->nlink;
    current->nlink = new;
    new->plink = current;
    list->head->data++;

}

void deleteatstart(struct dlist* list){
    if(list->head->nlink == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* temp = list->head->nlink;
    if(temp->nlink == list->head->nlink){
        free(temp);
        list->head->nlink = NULL;
    }
    else{
        struct node* tail = list->head->nlink->plink;
        tail->nlink = temp->nlink;
        temp->nlink->plink = tail;
        list->head->nlink = temp->nlink;
        free(temp);
    }
    list->head->data--;
}

void deleteatend(struct dlist* list){
    if(list->head->nlink == NULL){
        printf("Empty list\n");
        return;
    }
    struct node* temp = list->head->nlink;
    if(temp->nlink == list->head->nlink){
        free(temp);
        list->head->nlink = NULL;
    }
    else{
        struct node* tail = list->head->nlink->plink;
        struct node* prev = list->head->nlink->plink->plink;
        prev->nlink = list->head->nlink;
        list->head->nlink->plink = prev;
        free(tail);
    }
    list->head->data--;
}


void deleteatpos(struct dlist* list, int pos){
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
    struct node* current = list->head->nlink;
    struct node* prev = NULL;
    for(int i=0;i<pos;i++){
        prev = current;
        current = current->nlink;
    }
    current->nlink->plink = prev;
    prev->nlink = current->nlink;
    free(current);
    list->head->data--;

}

int searchbykey(struct dlist* list, int key){
    if(list->head->nlink == NULL){
        printf("Empty list\n");
        return -1;
    }
    struct node* current = list->head->nlink;
    int i=0;
    do{
        if(current->data == key){
            return i;
        }
        i++;
        current = current->nlink;
    }while(current != list->head->nlink);
    return -1;
}

void deletebykey(struct dlist* list, int key){
    if(list->head->nlink == NULL){
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
    struct node* current = list->head->nlink;
    struct node* prev = NULL;
    for(int i=0;i<pos;i++){
        prev = current;
        current = current->nlink;
    }
    current->nlink->plink = prev;
    prev->nlink = current->nlink;
    free(current);
    list->head->data--;
}


void searchbypos(struct dlist* list, int pos){
    if(pos<0 || pos>list->head->data-1){
        printf("Invalid position\n");
        return;
    }
    struct node* current = list->head->nlink;
    for(int i=0;i<pos;i++){
        current = current->nlink;
    }
    printf("Element at position %d is %d\n",pos,current->data);
    
}

void createordlist(struct dlist* list, int val){
    struct node* current = list->head->nlink;
    if(list->head->nlink == NULL || current->data > val){
        insertatstart(list, val);
        return;
    }
    
    while(current->nlink!=list->head->nlink && val>current->nlink->data){
            current = current->nlink; 
    }
    if(current->nlink == list->head->nlink){
        insertatend(list, val);
        return; 
    }

    struct node* new = createnode(val);
    current->nlink->plink = new;
    new->nlink = current->nlink;
    current->nlink = new;
    new->plink = current;
    list->head->data++;
    
}

void reverse(struct dlist* list) {
    if(list->head->nlink == NULL) {
        return;
    }
    struct node* current = list->head->nlink;
    struct node* next = NULL;
    do {
        next = current->nlink;
        current->nlink = current->plink;
        current->plink = next;
        current = next;
    }while(current != list->head->nlink);
    list->head->nlink = current->nlink;
}

void copylist(struct dlist* list, struct dlist* newlist) {
    if(list->head->nlink == NULL) {
        return;
    }
    struct node* current = list->head->nlink;
    
    while(current->nlink != list->head->nlink) {
        insertatend(newlist, current->data);
        current = current->nlink;
    }
    insertatend(newlist, current->data);
    newlist->head->data = list->head->data;
}

int main(){
    struct dlist mylist;
    createlist(&mylist);
    struct dlist newlist; // for copylist operation
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