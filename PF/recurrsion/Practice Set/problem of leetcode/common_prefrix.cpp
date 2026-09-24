#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string>words={"flower","flow","flight"};
    int n=words.size();
    string common_prefix=words[0];
    for (size_t i = 1; i < n; i++)
    {
        while (words[i].find(common_prefix)!=0)
        {
            common_prefix = common_prefix.substr(0, common_prefix.length() - 1);
        }
        if(common_prefix.empty())
        {
            break;
        }
    }
    cout << common_prefix << endl; 

    return 0;
}
// Output={"fl"}