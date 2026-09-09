#include <iostream>
using namespace std;

int main()
{
    char ch;
    int aCount=0,eCount=0,iCount=0,oCount=0,uCount=0;
    cout<<"Enter character: ";
    while (true)
    {
        ch = cin.get();
        if(ch=='\n')
        {
            break;
        }
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        {
            if(ch>='A'&&ch<='Z')
            {
                ch=ch+('a'-'A');
            }
            if(ch=='a')
            {
                aCount++;
            }
            else if(ch=='e')
            {
                eCount++;
            }
            else if(ch=='i')
            {
                iCount++;
            }
            else if(ch=='o')
            {
                oCount++;
            }
            else if(ch=='u')
            {
                uCount++;
            }
        }
        else
        {
            cout<<"Invaild number.";
        }
    }
    cout<<"Vowal:"<<endl;
    cout<<"For A: "<<aCount<<endl;
    cout<<"For E: "<<eCount<<endl;
    cout<<"For I: "<<iCount<<endl;
    cout<<"For O: "<<oCount<<endl;
    cout<<"For U: "<<uCount<<endl;
    
    return 0;
}