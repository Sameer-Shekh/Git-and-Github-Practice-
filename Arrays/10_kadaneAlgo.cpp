#include <iostream>
using namespace std;

// ALL POSSIBLE SUBARRAYS FORMED FROM THE GIVEN ARRAY TC : O(N^3)
void findAllPossibleSubArrays(int arr[], int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

// FIND MAXSUM BETWEEN SUBARRAYS BRUTEFORCE TC : O(N^2)
void findMaxSumOfSubArray(int arr[], int n)
{
    int maxSum = INT8_MIN;
    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    cout << "MAX SUBARRAY SUM = " << maxSum << endl;
}

// MOST OPTIMIZED APPROACH USING KADANE'S ALGORITHM TC : (O(N))
void findUsingKadaneAlgo(int arr[], int n)
{
    int currSum = 0, maxSum = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    cout << "MAX SUBARRAY SUM USING KADANE'S ALGORITHM = " << maxSum << endl;
}

int main()
{
    int n = 5;
    // int arr[5] = {1, 2, 3, 4, 5};
    int arr[5] = {1, 2, -3, 4, 5};
    findAllPossibleSubArrays(arr, n);
    findMaxSumOfSubArray(arr, n);
    findUsingKadaneAlgo(arr, n);
    return 0;
}