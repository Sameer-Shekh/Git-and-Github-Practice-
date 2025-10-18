// SINGLE ELEMENT IN A SORTED ARRAY
#include <iostream>
using namespace std;

// USING LINEAR SEARCH
void singleElementLinearSearch(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
        {
            cout << "SINGLE ELEMENT IS: " << arr[i] << endl;
        }
    }
}

// USING BINARY SEARCH
int singleElementBinarySearch(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid == 0 && arr[0] != arr[1])
        {
            return arr[0];
        }

        if (mid == n - 1 && arr[n - 1] != arr[n - 2])
        {
            return arr[n - 1];
        }

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 != 0 && arr[mid] == arr[mid - 1]))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {1, 1, 2, 2 , 6, 3, 3, 4, 4, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    singleElementLinearSearch(arr, n);
    int val = singleElementBinarySearch(arr, n);
    if (val != -1)
    {
        cout << "SINGLE ELEMENT USING BINARY SEARCH IS: " << val << endl;
    }
    return 0;
}