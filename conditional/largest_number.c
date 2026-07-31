#include<stdio.h>
void main()
{
    int x,y,z;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &x, &y, &z);  
    if (x>y && x>z)
    {
        printf("x is largest number: %d",x);
    }
    else if (y>z)
    {
        printf("y is largest number: %d",y);
    }
    else
    {
        printf("z is largest number: %d",z);
    }
    










}

/*#include <stdio.h>
int main()
{
    int x, y, z;
    printf("Enter the value of x, y, and z: ");
    scanf("%d %d %d",&x,&y,&z);
    if(x > y && x > z)
    {
        printf("Value of X is greater %d ",x);
        
    }
    else if(y > x && y > z)
    {
        printf("Value of Y is greater %d ",y);
        
    }
    else{
        printf("Value of Z is greater %d ",z);}
}*/