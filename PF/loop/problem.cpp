#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    int evenCount = 0, oddCount = 0;
    int largest, smallest;

    for (int i = 1; i <= 10; i++)
    {
        cout << "Enter number " << i << ": ";
        cin >> num;
        sum += num;
        if(num%2==0)
            evenCount++;
        else
            oddCount++;
    
              if (i == 1)
        {
            largest = num;
            smallest = num;
        }
        else
        {
            if (num > largest)
                largest = num;
            if (num < smallest)
                smallest = num;

        
    }
}

    cout << "\nSum: " << sum << endl;
    cout << "\nEven: " << evenCount << endl;
    cout << "\nOdd: " << oddCount << endl;
    cout << "\nLargest: " << largest << endl;
    cout << "\nSmallest: " << smallest << endl;
    

    return 0;
    
}





































// Problem: Number Analyzer
// Write a C++ program that asks the user to enter 10 integers, one at a time. As you read each number, 
// keep track of:

// The sum of all numbers
// The count of even numbers entered
// The count of odd numbers entered
// The largest number entered
// The smallest number entered

// At the end, print all five results.
// Requirements:

// Use a for loop to read the 10 numbers.
// Use if/else to check even/odd (hint: use % 2).
// Use if comparisons to update the largest/smallest as you go (don't use any built-in max/min functions
//  — figure out the logic yourself).
// Only use variables, loops, and conditionals — no arrays or functions needed.

// Example run:
// Enter number 1: 5
// Enter number 2: 12
// Enter number 3: -3
// Enter number 4: 8
// Enter number 5: 0
// Enter number 6: 7
// Enter number 7: 15
// Enter number 8: -20
// Enter number 9: 9
// Enter number 10: 4

// Sum: 37
// Even count: 5
// Odd count: 5
// Largest: 15
// Smallest: -20

