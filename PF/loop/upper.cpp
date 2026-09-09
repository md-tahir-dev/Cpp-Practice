#include<iostream>
using namespace std;
int main()
{
    int uppernum, num=1, sumodd = 0,sumeven=0;
    cout<<"Enter a number: ";
    cin>>uppernum;
    if(uppernum>0)
        {   do
            {
                if(uppernum%2!=0)
                {
                sumodd+=uppernum;
                cout << uppernum << " \n";
                
                } 
                else{
                sumeven += uppernum;
                cout << uppernum << " (Even)\n";
                    }
            uppernum--;
        }
        while (uppernum>=num);
        cout << "\nSum of odd numbers = " << sumodd << endl;
        cout << "Sum of even numbers = " << sumeven << endl;
        }
    return 0;
}
/* Calculate the sum of odd integers for a given upper limit. Also draw flow chart of the program*/