#include <stdio.h>
#include <math.h>

int main() 
{
    int i;
    printf("%-20s %s\n", "Number", "Square root");
    for (i = 0; i <= 5; i++) 
    {
        printf("%-26d %.2f\n", i, sqrt(i));
    }
    return 0;
}