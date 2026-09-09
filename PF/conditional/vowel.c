#include <stdio.h>
int main()
{
    char ch; 
    printf(" Enter a Character: ");
    scanf("%c", &ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch ==  'U')
    {
        printf("Character is vowel");
    }
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("Character isn't vowel");
    }
    else{
        printf("what did you write, it is not character");
    }
}