#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string line;
    cout<<"Enter values: ";
    getline(cin, line);
    
    vector<double> meanVALUES;
    double count, sum=0;
    double mean;
    double currentNum = 0;
    bool isNegative = false;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            currentNum = currentNum * 10 + (line[i] - '0');
        }
        else if (line[i] == '-')
        {
            isNegative = true;
        }
        else
        {
            if (isNegative)
            {
                currentNum = -currentNum;
            }
            meanVALUES.push_back(currentNum);
            currentNum = 0;
            isNegative = false;
        }
    }
    if (isNegative)
    {
        currentNum = -currentNum;
    }
    meanVALUES.push_back(currentNum);

    for (int i = 0; i < meanVALUES.size(); i++)
    {
        cout << meanVALUES[i] << " ";
    }
    cout<<endl;
    for(int i=0;i<meanVALUES.size();i++)
    {
        sum += meanVALUES[i];
    }
        count = meanVALUES.size();

    cout<<"Total Sum is: "<<sum<<endl;
    cout<<"Total values are: "<<count<<endl;
    mean=sum/count;
    cout<<"Mean is: "<<mean;
}