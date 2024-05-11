#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelorder(struct node* root){
    if(root == NULL){
        printf("Empty tree\n");
        return;
    }
    struct node *Q[100], *temp;
    int front=0, rear=-1;
    Q[++rear] = root;
    
    while(front<=rear) {
        temp = Q[front++];
        printf("%d ", temp->data);
        if(temp->left!=NULL) {
            Q[++rear] = temp->left;
        }
         
        if(temp->right!=NULL) {
            Q[++rear] = temp->right;
        }
    }
    printf("\n");
}

int count;
int countnode(struct node* root) {
    if(root == NULL) {
        return 0;
    }
    countnode(root->left);
    countnode(root->right);
    count++;
    return count;
}

int height(struct node* root) {
    if(root == NULL) {
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    return ((x>y)?x:y)+1;
}

struct node* insert(struct node* root, int val) {
    if(root == NULL) {
        struct node* newnode = createnode(val);
        root = newnode;
        return root;
    }
    if(val < root->data) {
        root->left = insert(root->left, val);  
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

void searchbykey(struct node* root, int key) {
    if(root == NULL) {
        printf("Emtpy tree\n");
        return;
    }
    struct node* child = root;
    struct node* parent = NULL;

    while(child != NULL) {
        if(child->data == key) {
            printf("%d is found\n",key);
        
        if(parent!=NULL) {
            printf("Parent value is: %d\n",parent->data);
        }
        else {
            printf("This is the root node\n");
        }
            return;
        }
        
        parent = child;
        if(key < child->data) {
            child = child->left;
        }
        else {
            child = child->right;
        }
    }
    printf("Key not found\n");
}

void findmax(struct node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) { //for single node
        printf("Max node is %d\n", root->data);
        return;
    }
    struct node* child = root;
    struct node* parent = NULL;
    while(child->right != NULL) {
        parent = child;
        child = child->right;
    }
    printf("Maximum node is %d\n",child->data);
    printf("Parent is %d\n", parent->data);
}

struct node* delete(struct node* root, int val) {
    if(root == NULL) {
        printf("Empty tree\n");
        return root;
    }
    struct node* current = root;
    struct node* parent = NULL;
    while(current!=NULL && current->data != val) {
        parent = current;
        if(val < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    if(current == NULL) {
        printf("Value not found\n");
        return root;
    }

    if(current->left!=NULL && current->right!= NULL) {
        struct node* parentSuccessor = current;
        struct node* successor = current->right;
        while(successor->left != NULL) {
            parentSuccessor = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        current = successor;
        parent = parentSuccessor;
    }


    struct node* child;
    if(current->left != NULL) {
        child = current->left;
    }
    else {
        child = current->right;
    }

    if(parent == NULL) {
        root = child;
    }
    else if(parent->left == current) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    free(current);
    return root;

}

int main() {
    struct node* root = NULL;
    int choice, val, key;
    do {
        printf("\n1- Insert\n2- Preorder\n3- Inorder\n4- Postorder\n5- Level order");
        printf("\n6- Search by key\n7- Count nodes\n8- Height of tree\n9- Maximum value node\n10- Delete by key\n11- Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: \n");
                do {
                scanf("%d",&val);
                if(val == -1) {
                    break;
                }
                root = insert(root, val);
                }while(1);
                break;
             case 2:
                printf("Preorder: ");
                preorder(root);
                if(root == NULL) {
                    printf(" Empty tree\n");
                }
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                if(root == NULL) {
                    printf(" Empty tree\n");
                }
                break;
             case 4:
                printf("Postorder: ");
                postorder(root);
                if(root == NULL) {
                    printf(" Empty tree\n");
                }
                break;
            case 5:
                printf("Level order: ");
                levelorder(root);
                break;
            case 6:
                printf("Enter key to search: ");
                scanf("%d",&key);
                searchbykey(root, key);
                break;
            case 7:
                count = 0;
                val = countnode(root);
                printf("%d",val);
                break;
            case 8:
                val = height(root);
                printf("%d",val);
                break;
            case 9:
                findmax(root);
                break;
            case 10:
                printf("Enter value to delete: ");
                scanf("%d",&val);
                root = delete(root, val);
                break;
        }
    }while(choice!= 11);
}
