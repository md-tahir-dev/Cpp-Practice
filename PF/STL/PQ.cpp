#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    priority_queue <int,vector<int>,greater<int>> q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(7);
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    
    return 0;
}