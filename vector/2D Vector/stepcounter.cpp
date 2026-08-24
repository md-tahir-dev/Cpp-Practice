#include <iostream>                                                                                       //[0][0]to last element of array
#include<vector>                                                                                                //count minimin steps in which i can go
using namespace std;                                                                                            //i go only on 1
int n;                                                                                                            //where 0 i can't g0
vector<vector <int>> gird;
vector<vector <int>> visited;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

                                                                                                                
void input(vector<vector<int>>&arr,int n)                                                                     
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter for "<<i+1<<" row"<<endl;
        for (int j = 0; j < n; j++)
        {
            cout<<"Enter elements for "<<j+1<<" element : ";
            cin>>arr[i][j];
            cout<<endl;
        }
        
    } 
}
bool isvaild(int x, int y, int n)
{
    if(x<0 || x >= n || y<0 || y>=n)
    {
        return false;
    }
    if (gird[x][y]==0)
    {   
        return false;
    }
    if(visited[x][y]==1)
    {
        return false;
    }
    return true;
    
}
void printARR(vector<vector<int>>&arr,int n)
{
    cout<<"Here is Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void countsteps(vector<vector<int>>&arr,int n,int notgo, int go)
{
    gird = arr;
    visited.assign(n,vector<int> (n,0));

    if(gird[0][0]==notgo)
    {
        cout<<"Not possible.";
        return;
    }

    vector<int>qx;
    vector<int>qy;
    vector<int>qlist;
    vector<int>parent;

    qx.push_back(0);
    qy.push_back(0);
    qlist.push_back(1);
    parent.push_back(-1);
    visited[0][0]=1;

    int i = 0;
    while(i < (int)qx.size())
    {
        int x = qx[i];
        int y = qy[i];
        int dlist = qlist[i];
        
        if(x == n-1 && y == n-1)
        {
            cout<<"Min steps: "<<dlist-1<<endl;
            vector<pair<int,int>>path;
            int curr = i;
            while (curr != -1)
            {
                path.push_back({qx[curr],qy[curr]});
                curr = parent[curr];
            }
            cout<<"Path: ";
            for(int k =path.size()-1;k>=0; k--)
            {
                cout<<path[k].first<<" , "<<path[k].second;
                if(k!=0)
                {
                    cout<<" ";
                }
                cout<<endl;
            }
            
            return;
        }
        int d = 0; 
        while(d < 4)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(isvaild(nx,ny, n))
            {
                visited[nx][ny] = 1; 
                qx.push_back(nx);
                qy.push_back(ny);
                qlist.push_back(dlist+1);
                parent.push_back(i);
            }
            d++;
        }
        i++;
    }
    
    cout<<"Not possible.";
    
     
}
    
    
int main()
{
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    int notgo = 0;
    int go = 1;
    vector<vector<int>>arr(n,vector<int>(n,0));
    input(arr,n);
    printARR(arr,n);
    cout<<endl;
    countsteps(arr,n,notgo, go);
    return 0;
}