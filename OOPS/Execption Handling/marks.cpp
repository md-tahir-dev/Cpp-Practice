#include <iostream>

using namespace std;

int main()
{
    int marks;
    cout << "Enter your mamrks: ";
    cin >> marks;
    cout << endl;

    try
    {
        if (marks < 0||marks>100)
        {
            throw "Invaild Marks.";
        }
        cout << "Vaild Marks";
    }
    catch (const char* statment)
    {
        cout << statment << '\n';
    }
    return 0;
}