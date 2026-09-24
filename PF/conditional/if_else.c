#include <stdio.h>
int main() 
{
    float score;
    printf("enter your score(0-100): ");
    scanf ("%f",&score);
    if(score>=90.00)
    {
        printf("Your Grade is A+");
    }
    else if (score>=80.00)
    {
        printf("Your Grade is A");
    }
    else if (score>=70.00)
    {
        printf("Your Grade is B");
    }
    else if (score>=60.00)
    {
        printf("Your Grade is C");
    }
    else if (score>=50.00)
    {
        printf("Your Grade is D");
    }
    else if (score>=40.00)
    {
        printf("Your Grade is E");
    }
    else{
        printf("Fail");
    }
    return 0;
}

/*Syntax of if-else statement*/
/* if(condition) {
        // code to be executed if condition is true
   }
   else {
        // code to be executed if condition is false
   } */