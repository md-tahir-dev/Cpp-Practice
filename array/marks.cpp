#include<iostream>
using namespace std;
int main()
{
    // int marks[5]{100, 89, 76, 59, 92};
    // int size = 5;
    // // double price[]{942, 3614, 9418};
    // // marks[1]=87;
    // // cout<<marks[0]<<endl;
    // // cout<<marks[1]<<endl;
    // // cout<<marks[2]<<endl;
    // // cout<<marks[3]<<endl;
    // // cout<<marks[4]<<endl;
    // // cout<<marks[-1]<<endl; if we enter something outside the array like here i tired for [-1] compiler didn't show me any error or warning, but compiler showed garbge value.
    // // gerenally we use loops for doing opreations on array.
    // // to check the size of array we use function sizeof, this is bulid-in function
    // // int size = sizeof(marks);
    // // cout<<size<<" Bytes"<<endl;//sizeof function gives us size in btyes as we know the int default size is 4 bytes
    // // cout<<size/sizeof(int);
    // for(int i=0;i<size;i++){
    //     cout<<marks[i]<<endl;
    // }
    int mark[5];
    int size = 5;
    for(int i = 0; i<size; i++)
    {
        cin>>mark[i];
    }
    for(int i = 0; i<size; i++){
        cout<< mark[i]<<endl;
    }

    return 0;
}
// array start from 0 and end on size-n like 5-1 it become [0-4] 