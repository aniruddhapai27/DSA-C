/*
Create a pointer to an integer array and pass this as parameter to a function called Reverse which reverses the array contents using pointer. Write different functions called Read (P) to read the array elements using pointer P and Display (P) to display the array contents using P before and after reverse.
*/

#include<stdio.h>

void read(int *a, int n);
void display(int *a, int n);
void reverse(int *a, int n);

int main(){
    int a[30], n, *p;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    p = a;

    printf("Enter elements: \n");
    read(p,n);

    printf("Original array: ");
    display(p,n);

    reverse(p,n);
    printf("Reversed array: ");
    display(p,n);
    
    return 0;

}

void read(int *a , int n){
    int i;

    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
}

void display(int *a, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

void reverse(int *a , int n){
    int* start = a;
    int* end = a+n-1;
     int temp;
    while(start<end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}