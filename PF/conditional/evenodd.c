#include <stdio.h>
#include<conio.h>

int main()
{
    int x;
    clrscr();
    printf("Enter number: ");
    scanf("%d", &x);
    
    if (x % 2 == 0)
    {
    printf("even");

}
if (x%2==1)

{ printf("odd");   }
    getch();
    
    return 0;
}
