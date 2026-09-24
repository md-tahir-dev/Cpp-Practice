#include <iostream>
using namespace std;
void is_find(int arr[],int size)
{
    int minVAL=arr[0];
    int maxVAL=arr[0];
    int autSUM=0;
    for (int i = 0; i < size; i++)
    {
        autSUM+=arr[i];
        if(arr[i]<minVAL)
        {
            minVAL=arr[i];
        }
        if(arr[i]>maxVAL)
        {
            maxVAL=arr[i];
        }
    }
    int expectedSUM=(maxVAL-minVAL+1)*(minVAL+maxVAL)/2;
    int missVAL=expectedSUM-autSUM;
    cout<<"Missing Value is "<<missVAL<<endl;
}
int main()
{
    int arr[]={14,12,11,15};
    int size=sizeof(arr)/sizeof(arr[0]);
    is_find(arr,size);
    return 0;
}