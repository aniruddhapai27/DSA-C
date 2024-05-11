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

void infixtoprefix(char* infix, char* prefix) {
    Stack stack;
    initialize(&stack);
    int i, j=0;
    int n = strlen(infix);
    for (i=0;i<n/2;i++) {
        char temp = infix[i];
        infix[i] = infix[n-i-1];
        infix[n-i-1] = temp;
    }
    for(i = 0;i<n;i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }

    for (i=0; infix[i]!='\0';i++){
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (peek(&stack) != '(') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if( !isEmpty(&stack) && infix[i] == '^' && peek(&stack) == '^' ){  // For a^b^c condition
            prefix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }

        else{
            while (!isEmpty(&stack) && precedence(infix[i]) < precedence(peek(&stack)) && associativity(infix[i]) == 'L') {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        
    }
    while (!isEmpty(&stack)) {
        prefix[j++] =pop(&stack);
    }

    prefix[j] = '\0';
    
    n= strlen(prefix);
    for (i=0;i<n/2;i++) {
        char temp = prefix[i];
        prefix[i] = prefix[n-i-1];
        prefix[n-i-1] = temp;
    }

}

int evalprefix(char* prefix) {
    Stack st;
    initialize(&st);
    int i, r, op1, op2;

    int n= strlen(prefix);
    for (i=0;i<n/2;i++) {
        char temp = prefix[i];
        prefix[i] = prefix[n-i-1];
        prefix[n-i-1] = temp;
    }

    for (i=0; prefix[i]!='\0'; i++) {
        if (isdigit(prefix[i])) {
            push(&st, prefix[i] - '0');
        }
        else {
            op1 = pop(&st);
            op2 = pop(&st);
            switch(prefix[i]) {
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
    char infix[MAX], prefix[MAX];
    int choice;
    do{
        printf("\n1- Infix to prefix\n");
        printf("2- Evaluation of prefix\n");
        printf("3- Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                infixtoprefix(infix, prefix);
                printf("Prefix expression is: %s", prefix);
                break;
            case 2:
                printf("Enter the prefix expression: ");
                scanf("%s", prefix);
                int r = evalprefix(prefix);
                printf("Result is: %d", r);
                break;
            case 3: 
                printf("Exiting...\n");
                break;
        }
    }while(choice != 3);
    return 0;

}