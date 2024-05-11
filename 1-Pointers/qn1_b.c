/*
Crate a pointer to an integer array. Read and display the contents using pointer and also display the contents in reverse order using pointer.
*/

#include <stdio.h>
int main()
{
    int a[30], *p, n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    p = a;
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
    }


    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");


    printf("Reversed array: ");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}