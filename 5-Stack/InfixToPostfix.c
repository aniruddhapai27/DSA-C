#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100
typedef struct {
    int S[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX-1;
}

void push(Stack* s, char c) {
    if (isFull(s)){
        printf("Overflow\n");
        exit(0);
    }
    s->S[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
        exit(0);
    }
    return s->S[(s->top)--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
        exit(0);
    }
    return s->S[s->top];
}

int precedence(char c) {
    if (c=='^') {
        return 3;
    }
    if (c=='*' || c=='/' || c=='%') {
        return 2;
    }
    if (c=='+' || c=='-') {
        return 1;
    }
    return -1;
}

char associativity(char c) {
    if(c == '^') {
        return 'R';
    }
    else {
        return 'L';
    }
}

void infixtopostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j;
    for (i=0,j=0; infix[i]!='\0';i++){
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else{
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack)) && associativity(infix[i]) == 'L') {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        
    }
    while (!isEmpty(&stack)) {
        postfix[j++] =pop(&stack);
    }
    postfix[j] = '\0';

}

int evalpostfix(char* postfix) {
    Stack st;
    initialize(&st);
    int i, r, op1, op2;
    for (i=0; postfix[i]!='\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&st, postfix[i] - '0');
        }
        else {
            op2 = pop(&st);
            op1 = pop(&st);
            switch(postfix[i]) {
                case '+':
                    r = op1 + op2;
                    break;
                case '-':
                    r = op1 - op2;
                    break;
                case '*':
                    r = op1 * op2;
                    break;
                case '/':
                    r = op1 / op2;
                    break;
                case '%':
                    r = op1 % op2;
                    break;
                case '^':
                    r = pow(op1, op2);
                    break;
            }
            push(&st, r);
        }

    }
    return r;
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;
    do{
        printf("\n1- Infix to Postfix\n");
        printf("2- Evaluation of postfix\n");
        printf("3- Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                infixtopostfix(infix, postfix);
                printf("Postfix expression is: %s", postfix);
                break;
            case 2:
                printf("Enter the postfix expression: ");
                scanf("%s", postfix);
                int r = evalpostfix(postfix);
                printf("Result is: %d", r);
                break;
            case 3: 
                printf("Exiting...\n");
                break;
        }
    }while(choice != 3);
    return 0;

}