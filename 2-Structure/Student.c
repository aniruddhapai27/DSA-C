/*
Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_marks.
Develop a menu driven program to perform the following by writing separate function for each operation: a) read information of N students b) display student's information c) to calculate the average of best two test marks of each student.
Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.
*/

#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[30];
    int rno;
    int m[3];
};

void read(struct student* s, int n) {
    for(int i=0;i<n;i++) {
        printf("Enter details of student %d: \n",(i+1));
        printf("Enter name: ");
        scanf("%s",(s+i)->name);
        printf("Enter reg no: ");
        scanf("%d",&(s+i)->rno);
        printf("Enter marks in 3 subjects: \n");
        scanf("%d%d%d",&(s+i)->m[0],&(s+i)->m[1],&(s+i)->m[2]); 
    }
}

void display(struct student* s, int n) {
    for(int i=0;i<n;i++) {
        printf("\nStudent %d:\n",(i+1));
        printf("Name: %s\n",(s+i)->name);
        printf("Reg no: %d\n",(s+i)->rno);
        printf("Marks in 3 subjects: \nSub-1 :%d\nSub-2 :%d\nSub-3 :%d\n", (s+i)->m[0],(s+i)->m[1],(s+i)->m[2]);
        printf("Average: %.2f\n",((s+i)->m[0]+(s+i)->m[1]+(s+i)->m[2])/3.0);
        
    }
}

float avg(int a, int b, int c) {
    float avg;
    if(a>b && a>c) {
        avg = (a+((b>c)?b:c))/2.0;
    }
    else if(b>c && b>a) {
        avg = (b+((a>c)?a:c))/2.0;
    } 
    if(c>b && c>a) {
        avg = (c+((a>b)?a:b))/2.0;
    } 
    return avg; 
}



int main(){
    struct student *s;
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    s = (struct student*)malloc(n*sizeof(struct student));
    if(s==NULL) {
        printf("Memory not allocated");
        exit(0);
    }
    int choice;

    do{
        printf("\n1- Read\n2- Display\n3- Average\n4-Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                read(s, n);
                break;
            case 2:
                display(s, n);
                break;
            case 3:
                printf("Average of best two marks: \n");
                for(int i=0;i<n;i++) {
                    printf("%s: %.2f\n",(s+i)->name, avg((s+i)->m[0],(s+i)->m[1],(s+i)->m[2]));
                }
                break;
            case 4:
                printf("Exiting...\n");
        }
    }while(choice!=4);



}