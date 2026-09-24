#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int n = 5;
    int sumMAX = INT_MIN;
    for (int  start = 0; start < n ; start++)
    {   int currSUM = 0;
        for (int  end = start; end < n; end++)
        {
            currSUM += arr[end];
            sumMAX = max(currSUM, sumMAX);
            
        }
        // cout<<currSUM<<endl;
    }
    cout<<"Sum is: "<<sumMAX;
    
    return 0;
}
/*
                          ┌───────────────┐
                          │     Start     │
                          └───────┬───────┘
                                  │
                                  ▼
                    ┌────────────────────────┐
                    │ Initialize:            │
                    │ arr={1,2,3,4,5}        │
                    │ n=5                    │
                    │ sumMAX = INT_MIN       │
                    └──────────┬─────────────┘
                               │
                               ▼
                  ┌─────────────────────────┐
                  │ start = 0               │
                  └──────────┬──────────────┘
                             │
                             ▼
                     ┌─────────────────┐
                     │ start < n ?     │
                     └──────┬──────────┘
                      Yes   │   No
                            │
                            ▼
                  ┌────────────────────┐
                  │ currSUM = 0        │
                  │ end = start        │
                  └─────────┬──────────┘
                            │
                            ▼
                    ┌─────────────────┐
                    │ end < n ?       │
                    └──────┬──────────┘
                     Yes   │   No
                           │
                           ▼
            ┌─────────────────────────────┐
            │ currSUM = currSUM + arr[end]│
            └──────────────┬──────────────┘
                           │
                           ▼
            ┌─────────────────────────────┐
            │ sumMAX = max(currSUM,sumMAX)│
            └──────────────┬──────────────┘
                           │
                           ▼
                  ┌────────────────┐
                  │ end = end + 1  │
                  └───────┬────────┘
                          │
                          └───────────────┐
                                          │
                                          ▼
                                (Back to end < n?)

                     No
                      │
                      ▼
             ┌─────────────────┐
             │ start = start+1 │
             └───────┬─────────┘
                     │
                     └───────────────┐
                                     │
                                     ▼
                           (Back to start < n?)

                  No
                   │
                   ▼
          ┌──────────────────────┐
          │ Print "Sum is:"      │
          │ sumMAX               │
          └──────────┬───────────┘
                     │
                     ▼
              ┌───────────────┐
              │      End      │
              └───────────────┘

*/              