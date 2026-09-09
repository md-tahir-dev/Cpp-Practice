#include<iostream>
using namespace std;
void inputARR(int r, int c, int arr[100][100])
{
    for (int i = 0; i < r; i++)
    {   
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout << "Kindly enter number: ";
                cin >> arr[i][j];
            }
        }
    }
} 
int count(int arr[100][100])
{
    int count=0;
    for (int i = 0; i < 100; i++)
    {
        if(arr[i][0]==0)
        {
            break;
        }
        count++;
    }
    return count;
    
}
void printARR(int arr[100][100],int r,int c)
{
    for(int i = 0; i<r;i++)
    {
        for (int j = 0; j <c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int sum(int arr[100][100],int N, int target)
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
    i=r-1,j=c-1;
    while (i>=0&&j>=0)
    {
        sum= sum + arr[i][j];
        i--,j--;
    }
    i=r+1,j=c-1;
    while (i<N&&j>=0)
    {
        sum= sum+arr[i][j];
        i++,j--;
    }
    i=r-1,j=c+1;
    while (i>=0&&j<N)
    {
        sum = sum + arr[i][j];
        i--,j++;
    }
    return sum; 
}
int main()
{   
    int N;
    int target;
    int r,c;
    cout<<"Enter total number of rows: ";
    cin>>r;
    cout<<"Enter total number of Columns: ";
    cin>>c;
    int arr[100][100];
    cout<<"Enter elements:-"<<endl;
    inputARR(r,c,arr);
    N=count(arr);
    cout<<"Your entered elements:-"<<endl;
    printARR(arr,r,c);
    cout<<"Enter target: ";
    cin>>target;
    cout<<"Sum is "<<sum(arr,N,target);
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