#include<iostream>
using namespace std;

const int MAX = 5;

class array
{
private:
    int arr[MAX] = {0};

public:
    void insert(int pos, int num);
    void del(int pos);
    void reverse();
    void display();
    void search(int num);
};

void array::insert(int pos, int num)
{
    // Convert position to index
    pos--;

    for (int i = MAX - 1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;
}

void array::del(int pos)
{
    // Convert position to index
    pos--;

    for (int i = pos; i < MAX - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[MAX - 1] = 0;
}

void array::reverse()
{
    for (int i = 0; i < MAX / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[MAX - 1 - i];
        arr[MAX - 1 - i] = temp;
    }
}

void array::search(int num)
{
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] == num)
        {
            cout << "\n\nThe Element " << num
                 << " is present at position " << i + 1 << "\n";
            return;
        }
    }

    cout << "\n\nThe element " << num
         << " is not present in the array.";
}

void array::display()
{
    cout << endl;

    for (int i = 0; i < MAX; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    array a;

    a.insert(1, 11);
    a.insert(2, 12);
    a.insert(3, 13);
    a.insert(4, 14);
    a.insert(5, 15);

    cout << "\nElements of Array: ";
    a.display();

    a.del(5);
    a.del(2);

    cout << "\n\nAfter Deletion: ";
    a.display();

    a.insert(2, 222);
    a.insert(5, 555);

    cout << "\n\nAfter Insertion: ";
    a.display();

    a.reverse();

    cout << "\n\nAfter Reversing: ";
    a.display();

    a.search(222);
    a.search(666);
}