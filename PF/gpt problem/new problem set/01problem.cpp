// Array Analysis
// Number of positive elements
// Number of negative elements
// Number of zeros

// #include <iostream>
// #include <climits>
// using namespace std;
// void no_of_elements(int arr[],int size)
// {
//     int pos_element=0,neg_element=0,zero_element=0,sum_pos=0,neg_sum=0;
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i]>0)
//         {
//             pos_element++;
//             sum_pos+=arr[i];
//         }
//         else if(arr[i]<0)
//         {
//             neg_element++;
//             neg_sum+=arr[i];
//         }
//         else
//         {
//             zero_element++;
//         }
//     }

//     cout<<"Sum of positive element is "<<sum_pos<<endl;
//     cout<<"Total positive element is "<<pos_element<<endl;
//     cout<<"Total negetive element is "<<neg_element<<endl;
//     cout<<"Sum of Negitive element is "<<neg_sum<<endl;
//     cout<<"Total zero's is "<<zero_element<<endl;
    
// }
// void secondSmallest(int arr[], int size)
// {
//     int first = INT_MAX, second = INT_MAX;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] < first) {
//             second = first;
//             first = arr[i];
//         }
//         else if (arr[i] < second && arr[i] != first) {
//             second = arr[i];
//         }
//     }
//     cout << "Second Smallest Element is "<< second << endl;
// }
// void Largest_Number(int arr[], int size)
// {
//     int largest=arr[0];
//     int total_large=0;
//     for (size_t i = 1; i < size; i++)
//     {
//         if(arr[i]>largest)
//         {
//             largest=arr[i];
//         }
//     }
//     cout<<"Largest number is "<<largest<<endl;
//     for (int i = 0; i < size; i++)
//     {
//         if(largest==arr[i])
//         {
//             total_large++;
//         }
//     }
//     cout<<"Total occur of largest element  "<<total_large<<endl;
    
// }
// void Smallest_Number(int arr[], int size)
// {
//     int smallest=arr[0];
//     for (size_t i = 1; i < size; i++)
//     {
//         if(arr[i]<smallest)
//         {
//             smallest=arr[i];
//         }
//     }
//     cout<<"Smallest number is "<<smallest<<endl;
// }
// void even_sum(int arr[],int size)
// {
//     int sum=0,even=0,odd=0;
//     for (size_t i = 0; i < size; i++)
//     {
//         sum+=arr[i];
//         if(arr[i]%2==0)
//         {
//             even++;
//         }
//         else
//         {
//             odd++;
//         }
//     }
//     cout<<"Sum is "<<sum<<endl;
//     cout<<"Total even number is "<<even<<endl;
//     cout<<"Total odd number is "<<odd<<endl;
// }
// void secondLargest(int arr[],int size)
// {
//      int first = INT_MIN, second = INT_MIN;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] > first) {
//             second = first;
//             first = arr[i];
//         }
//         else if (arr[i] > second && arr[i] < first) {
//             second = arr[i];
//         }
//     }
//     cout << "Second Largest Element is "<< second << endl;
// }
// int main()
// {
//     int arr[] = {4, -2, 7, 4, 9, -2, 9, 1, 7, 9};
//     // int arr[] = {7, 2, 9, 4, 2, 7, 5, 9, 1};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     no_of_elements(arr,size);
//     Largest_Number(arr,size);
//     Smallest_Number(arr,size);
//     secondSmallest(arr,size);
//     even_sum(arr,size);
//     secondLargest(arr,size);
//     return 0;
// }

// one in function
#include <iostream>
#include <climits>
using namespace std;

void analyzeArray(int arr[], int size)
{
    int largest = INT_MIN, smallest = INT_MAX;
    int posCount = 0, negCount = 0, zeroCount = 0;
    int sumPos = 0, sumNeg = 0;
    int largestCount = 0, smallestCount = 0;

    for (int i = 0; i < size; i++)
    {
        int val = arr[i];

        // Track largest
        if (val > largest)
        {
            largest = val;
            largestCount = 1; // reset count
        }
        else if (val == largest)
        {
            largestCount++;
        }

        // Track smallest
        if (val < smallest)
        {
            smallest = val;
            smallestCount = 1; // reset count
        }
        else if (val == smallest)
        {
            smallestCount++;
        }

        // Positive / Negative / Zero counts and sums
        if (val > 0)
        {
            posCount++;
            sumPos += val;
        }
        else if (val < 0)
        {
            negCount++;
            sumNeg += val;
        }
        else
        {
            zeroCount++;
        }
    }

    cout << "Largest element: " << largest << endl;
    cout << "Count of largest: " << largestCount << endl;
    cout << "Smallest element: " << smallest << endl;
    cout << "Count of smallest: " << smallestCount << endl;
    cout << "Number of positives: " << posCount << endl;
    cout << "Sum of positives: " << sumPos << endl;
    cout << "Number of negatives: " << negCount << endl;
    cout << "Sum of negatives: " << sumNeg << endl;
    cout << "Number of zeros: " << zeroCount << endl;
}

int main()
{
    int arr[] = {5, -3, 8, 0, 5, -7, 8, 2, 0, -3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    analyzeArray(arr, size);
    return 0;
}
