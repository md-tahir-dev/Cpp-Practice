#include <iostream>
#include<string>
using namespace std;
void countalpa(char arr[],int size)
{
    int aCount=0,eCount=0,iCount=0,oCount=0,uCount=0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i]=='a')
        {
            aCount++;
        }
        else if(arr[i]=='e')
        {
            eCount++;
        }
        else if(arr[i]=='i')
        {
            iCount++;
        }
        else if(arr[i]=='o')
        {
            oCount++;
        }
        else if(arr[i]=='u')
        {
            uCount++;
        }
    }
    cout<<"Vowal:"<<endl;
    cout<<"For A: "<<aCount<<endl;
    cout<<"For E: "<<eCount<<endl;
    cout<<"For I: "<<iCount<<endl;
    cout<<"For O: "<<oCount<<endl;
    cout<<"For U: "<<uCount<<endl;    
}
void toUpper(char arr[],int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i]>='a'&&arr[i]<='z')
        arr[i]=arr[i]-32;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout<<"Element "<<i+1<<" is: "<<arr[i]<<endl;
    }
    
}
int main()
{
    char arr[8];
    
    int size = sizeof(arr)/sizeof(char);
    cout<<"Enter char: \n";
    for (size_t i = 0; i < size; i++)
    {
        cout<<"Enter "<<i+1<<" Element: ";
        cin>>arr[i];
        if((arr[i] < 'a' || arr[i] > 'z') && (arr[i] < 'A' || arr[i] > 'Z'))
        {
            cout<<"Invalid!!! Re-enter.";
            return -1;
        }
    }
    countalpa(arr,size);
    toUpper(arr,size);
    
    return 0;
}