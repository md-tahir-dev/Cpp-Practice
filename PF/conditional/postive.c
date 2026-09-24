#include<stdio.h>
void main()
{
    int x,y;
    printf("Enter postive value: ");
    scanf("%d", &x);
    y=x*x;
    if (x>0)
    {
        printf("%d is square root of x(%d)\n",y,x);
    }

    else
    {
        printf("Enter a Postive value!!!");
    }




}