/*
Create 3 pointers called P1, P2, P3 and an integer variable X where P1 points to P2, P2 points to P3 and P3 points to X. Demonstrate how to read and retrieve the value of X using P1, P2 and P3.
*/


#include <stdio.h>
int main()
{
    int *p3, **p2, ***p1;
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    p3 = &x;
    p2 = &p3;
    p1 = &p2;
    printf("Value of x using p3: %d\n", *p3);
    printf("Value of x using p2: %d\n", **p2);
    printf("Value of x using p1: %d\n", ***p1);
    return 0;
}