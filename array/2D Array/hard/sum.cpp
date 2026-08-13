#include<iostream>
using namespace std;
void printARR(int arr[5][5],int N)
{
    for(int i = 0; i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int sum(int arr[5][5],int N, int target)
{
    int r=(target-1)/N;
    int c=(target-1)%N;
    int sum=0;
    int i = r,j=c;
    while (i < N&&j<N)
    {
        sum = sum+ arr[i][j];
         i++,j++;
    }
    
    // for (int i = r,j=c; i < N&&j<N; i++,j++)
    // {
    //     sum = sum+ arr[i][j];
    // }
    cout<<"sum of first: "<<sum<<endl;
    i=r-1,j=c-1;
    while (i>=0&&j>=0)
    {
        sum= sum + arr[i][j];
        i--,j--;
    }
    
    // for(int i=r-1,j=c-1;i>=0,j>=0;i--,j--)
    // {
    //     sum= sum + arr[i][j];
      
    // }
    cout<<"sum of second: "<<sum<<endl;
    i=r+1,j=c-1;
    while (i<N&&j>=0)
    {
        sum= sum+arr[i][j];
        i++,j--;
    }
    
    // for(int i=r+1,j=c-1; i<N,j>=0;i++,j--)
    // {
    //     sum= sum+arr[i][j];
    // }
    cout<<"sum of third: "<<sum<<endl;
    i=r-1,j=c+1;
    while (i>=0&&j<N)
    {
        sum = sum + arr[i][j];
        i--,j++;
    }
    
    // for(int i=r-1,j=c+1;i>=0,j<N;i--,j++)
    // {
    //     sum = sum + arr[i][j];
    // }
    cout<<"sum of four: "<<sum<<endl;
    return sum; 
    
}
int main()
{   
    int N=5;
    int target;
    int arr[5][5]={
        1, 2, 3, 4, 5,
        6, 7, 8, 9,10,
        11,12,13,14,15,
        16,17,18,19,20,
        21,22,23,24,25
    };
    printARR(arr,N);
    cout<<"Enter target: ";
    cin>>target;
    cout<<sum(arr,N,target);
}


/*in first loop 
first sum arr[i][j]
i++, j++
in second
i--, j-- 
sum arr[i][j]
in third loop
i--, j++ 
sum arr[i][j]
in frouth loop 
i++, j--
sum arr[i][j]*/