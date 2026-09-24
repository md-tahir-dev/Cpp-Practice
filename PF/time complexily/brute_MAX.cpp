#include <iostream>
#include<vector>
using namespace std;
vector <int>Most_Freq(vector<int>dupli,int arr[],int size)
{
    cout<<"Most Freq element is: ";
    for (size_t i = 0; i < size; i++)
    {
        dupli[arr[i]]++;
    }
    cout<<endl;
    return dupli;
}
void printMAX(vector<int>dupli1,int size1)
{
    int MAXValue=dupli1[0];
    for (size_t i = 1; i < size1; i++)
    {
        if(dupli1[i]>MAXValue)
        {
            MAXValue=dupli1[i];
        }
    }
    cout<<"Most Freq element is: "<<MAXValue<<endl;
}
int main()
{
    int arr[]= {1, 5, 3,7,6,9,5,2,2,2, 7, 2, 5};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int max= arr[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    vector<int>dupli(max+1,0);
    vector<int>dupli1=Most_Freq(dupli,arr,size);
    size_t size1 = sizeof(dupli1)/sizeof(dupli1[0]);
    printMAX(dupli1,size1);
    return 0;
}