#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // vector <int> vec={1,2,3};
    // vector <int> vec(5,1);
    // vector <char> vec = {'a', 'b', 'c', 'd', 'e', 'f'};
    // vector <int> vec = {97, 98, 99, 100, 101, 102};
    // vector <int> vec;
    // cout<< "size = "<<vec.size()<<endl;
    // vec.push_back(25);
    // vec.push_back(35);
    // vec.push_back(45);
    // cout<< "after push back size is = "<<vec.size()<<endl;
    // vec.pop_back();
    // cout<< "after pop back size is = "<<vec.size()<<endl;
    // cout<<vec.front()<<endl;
    // cout<<vec.back()<<endl;
    // cout<<vec.at(0)<<endl;

    // // cout<<vec[0]<<endl;
    // // cout<<vec[0]<<endl;
    // // cout<<vec[1]<<endl;
    // // cout<<vec[2]<<endl;
    // // cout<<vec[3]<<endl;
    // // cout<<vec[4]<<endl;
    // // for each loop
    // // for( int val: vec)
    // // {
    // //     cout<<val<<endl;
    // // }
    vector <int> vect;
    vect.push_back(0);
    vect.push_back(1);
    vect.push_back(2);
    for( int i: vect)
    {
        cout<<i<<endl;
    }
    cout<<"size is "<<vect.size()<<endl;
    cout<<"capacity is "<<vect.capacity()<<endl;
    vect.push_back(3);
    vect.push_back(4);
    cout<<"size is "<<vect.size()<<endl;
    cout<<"capacity is "<<vect.capacity()<<endl;


    return 0;
}