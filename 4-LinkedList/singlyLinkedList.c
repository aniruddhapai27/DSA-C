#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct list {
    struct node* head;
};

struct node* createnode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory allocation not possible\n");
        exit(0);
    }
    newnode->data = val;
    newnode->link = NULL;
    return newnode;
}

void createlist(struct list* list) {
    struct node* h = createnode(0);
    list->head = h;
}

void insertatfront(struct list* list, int val) {
    struct node* newnode = createnode(val);
    if(list->head == NULL) {
        list->head->link = newnode;
    }
    else {
        newnode->link = list->head->link;
        list->head->link = newnode;
    }
    list->head->data++;
}

void insertatrear(struct list* list, int val) {
    struct node* newnode = createnode(val);
    if(list->head == NULL) {
        list->head->link = newnode;
    }
    else {
        struct node* tail = list->head->link;
        while(tail->link != NULL) {
            tail = tail->link;
        }
        tail->link = newnode;
    }
    list->head->data++;
}

void insertatpos(struct list* list, int pos, int val) {
    if(pos<0 || pos>list->head->data) {
        printf("Invalid position\n");
        return;
    }
    if(pos == 0) {
        insertatfront(list, val);
        return;
    }
    else if(pos == list->head->data) {
        insertatrear(list, val);
        return;
    }
    struct node* current = list->head->link;
    for(int i=1; i<pos; i++) {
        current = current->link;
    }
    struct node* newnode = createnode(val);
    newnode->link = current->link;
    current->link = newnode;
    list->head->data++;
}

void deleteatfront(struct list* list) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* temp = list->head->link;
    if(list->head->link->link == NULL) {
        list->head->link = NULL;
    }
    else {
        list->head->link = temp->link;
    }
    free(temp);
    list->head->data--;
}

void deleteatrear(struct list* list) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* tail = list->head->link;
    if(list->head->link->link == NULL) {
        list->head->link = NULL;
    }
    else {
        struct node* prev = NULL;
        while(tail->link != NULL) {
            prev = tail;
            tail = tail->link;
        }
        prev->link = NULL;
    }
    free(tail);
    list->head->data--;
}

void deleteatpos(struct list* list, int pos) {
    if(pos<0 || pos>=list->head->data) {
        printf("Invalid position\n");
        return;
    }
    if(pos == 0) {
        deleteatfront(list);
        return;
    }
    else if(pos==list->head->data - 1) {
        deleteatrear(list);
        return;
    }
    struct node* current = list->head->link;
    struct node* prev = NULL;
    for(int i=0; i<pos; i++) {
        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
    list->head->data--;
}

void display(struct list* list) {
    if(list->head == NULL || list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* current = list->head->link;
    while(current != NULL) {
        printf("%d-> ",current->data);
        current = current->link;
    }
    printf("NULL\n");
    printf("Number of nodes: %d\n",list->head->data);
}

void freelist(struct list* list) {
    if(list->head->link == NULL) {
       free(list->head);
       free(list);
       return;
    }
    struct node* current = list->head->link;
    struct node* prev = NULL;
    while(current != NULL) {
        prev = current;
        current = current->link;
        free(prev);
    }
    free(list->head);
    free(list);
}


int searchbykey(struct list* list, int key){
    if(list->head->link == NULL) {
        return -1;
    }
    struct node* current = list->head->link;
    int pos = 0;
    while(current!=NULL){
        if(current->data == key) {
            return pos;
        }
        current = current->link;
        pos++;
    }
    return -1;

}

void deletebykey(struct list* list, int key) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
    }
    int pos= searchbykey(list, key);
    if(pos==-1) {
        printf("Key not found\n");
        return;
    }
    deleteatpos(list, pos);
}

void searchbypos(struct list* list, int pos) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    if(pos<0 || pos>=list->head->data) {
        printf("Invalid position\n");
        return;
    }
    struct node* current = list->head->link;
    for(int i=0; i<pos; i++) {
        current = current->link;
    }
    printf("Element is: %d\n", current->data);
}

void insertbyorder(struct list* list, int val) {
    struct node* current = list->head->link;
    if(list->head->link == NULL || current->data > val) {
        insertatfront(list, val);
        return;
    }    
    while(current->link != NULL && val>current->link->data){
        current = current->link;
        if(current->link == NULL) {
            insertatrear(list, val);
            return;
        }
    }
    struct node* new = createnode(val);
    new->link = current->link;
    current->link = new;
    list->head->data++;
}

void reverse(struct list* list) {
    if(list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* current = list->head->link;
    struct node* next = NULL;
    struct node* prev = NULL;
    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    list->head->link = prev;
}

void copylist(struct list* list, struct list* newlist) {
    if(list->head == NULL || list->head->link == NULL) {
        printf("Empty list\n");
        return;
    }

    struct node* current = list->head->link;
    struct node* tail = newlist->head;

    while(current != NULL) {
        struct node* newnode = createnode(current->data);
        tail->link = newnode;
        tail = tail->link;
        current = current->link;
    }

    newlist->head->data = list->head->data;

    printf("Copied list is: \n");
    display(newlist);
}
 


int main() {
    struct list list;
    createlist(&list);
    struct list newlist; //for copylist operation
    int val, choice, pos, key;
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
        printf("11 - Reverse list\n");
        printf("12 - Copy list\n");
        printf("13 -Display list\n");
        printf("14 -Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert at start: ");
                scanf("%d",&val);
                insertatfront(&list, val);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d",&val);
                insertatrear(&list, val);
                break;
            case 3:
                printf("Enter position and value to insert: ");
                scanf("%d%d",&pos,&val);
                insertatpos(&list, pos, val);
                break;
            case 4:
                deleteatfront(&list);
                break;
            case 5:
                deleteatrear(&list);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d",&pos);
                deleteatpos(&list, pos);
                break;
            case 7:
                printf("Enter the key to search: ");
                scanf("%d",&key);
                int i=searchbykey(&list, key);
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
                deletebykey(&list, key);
                break;
            case 9:
                printf("Enter the position to search: ");
                scanf("%d",&pos);
                searchbypos(&list, pos);
                break;
            case 10:
                printf("Enter the element to insert in order: ");
                scanf("%d",&val);
                insertbyorder(&list, val);
                break;
            case 11:
                reverse(&list);
                break;
            case 12:
                createlist(&newlist);
                copylist(&list, &newlist);
                freelist(&newlist);
                break;
            case 13:
                printf("List is:\n");
                display(&list);
                break;
            case 14:
                freelist(&list);
                return 0;
        }
        

    }while(choice != 14);

    
}

