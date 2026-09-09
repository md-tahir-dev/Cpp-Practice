#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    char arr[50];
    cout<<"Enter 50 character: ";
    cin.getline(arr,50);
    int lenght= strlen(arr);
    int maxCount=0;
    char mostFreq = arr[0];
    for (size_t i = 0; i < lenght; i++)
    {
        int count = 0;
        for (size_t j = 0; j < lenght; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
         if(count>maxCount)
         {
            maxCount=count;
            mostFreq=arr[0];
         }
    }
    cout<<"Most Freq character is: "<<mostFreq<<endl;
    cout<<"Count of max character is: "<<maxCount<<endl;
    
}