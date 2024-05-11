/*
Create a pointer to two dimensional array of integers. Write functions Read (P) and Display (P) to read and display the contents using pointer.
*/

#include<stdio.h>

void Read(int *a, int m, int n){
    int i,j;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",((a+i*n)+j));
        }
    }
}
void Display(int *a,int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",*((a+i*n)+j));
        }
        printf("\n");
    }
}


int main() {
    int a[30][30], m, n;
    int *p;
    p = &a[0][0];
    printf("Enter m and n: ");
    scanf("%d%d",&m,&n);
    printf("Enter array elements: \n");
    Read(p,m,n);     
    printf("The array elements are: \n");
    Display(p,m,n);
    return 0;
}