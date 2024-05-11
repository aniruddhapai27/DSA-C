/*
Define a structure called Time containing 3 integer members (hour, minute, second). Develop a menu driven program to perform the following by writing separate function for each operation.
03.
a) Read (T): To read time b) Display (T):To display time c) update(T):To Update time d) Add (T1, T2): Add two times.
Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero. While adding two time variable, normalize the resultant time value as in the case of update function.
Note: Illustrate the use of pointer to pass time variable to different functions
*/

#include<stdio.h>
#include<stdlib.h>

struct time{
    int h;
    int s;
    int m;
};

struct time read(struct time* t) {
    printf("Enter hour, minute, second: \n");
    scanf("%d%d%d",&t->h, &t->m, &t->s);
    return *t;
}

void display(struct time* t) {
    printf("Time is:\n");
    printf("%02d:%02d:%02d\n",t->h, t->m, t->s);
}

void update(struct time* t) {
    t->s+=1;
    if(t->s >= 60){
        t->s = 0;
        t->m += 1;
        if(t->m >= 60) {
            t->m = 0;
            t->h += 1;
            if(t->h >= 24) {
                t->h = 0;
            }
        }
    }
    display(t);

}

void add(struct time t1, struct time t2) {
    struct time r;
    r.h = t1.h+t2.h;
    r.m = t1.m+t2.m;
    r.s = t1.s+t2.s;
    if(r.s >= 60) {
        r.s -= 60;
        r.m+=1;
    }
    if(r.m >= 60) {
        r.m -= 60;
        r.h+=1;
    }
    if(r.h>=24) {
        r.h -= 24;
    }
    
    
    display(&r);

}

int main(){
    struct time *p;
    struct time *t1;
    struct time *t2;
    p = (struct time*)malloc(sizeof(struct time));
    int choice;
    do{
        printf("\n1-Read\n2-Display\n3-Update\n4-Add\n5-Exit\n\n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            *p = read(p);
            break;
        case 2:
            display(p);
            break;
        case 3:
            update(p);
            break;
        case 4:
            t1 = (struct time*)malloc(sizeof(struct time));
            t2 = (struct time*)malloc(sizeof(struct time));
            read(t1);
            read(t2);
            add(*t1, *t2);
            break;

    }
    
    }while(choice!=5);
}