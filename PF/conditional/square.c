#include<stdio.h>
void main()
{   
    int x,y;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Enter number: ");
    scanf("%d", &y);
    if (y == x*x)
    {
        printf("y is the square of x");
    }
        else
        {
            printf("y is not the square of x");
        }
}