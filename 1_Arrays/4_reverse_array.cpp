#include <iostream>

using namespace std;

// USING TWO-POINTER APPROACH
void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {3, 5, 7, 2, 8, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// HOW ITS HANDLE THE ODD AND EVEN LENGTH OF ARRAY
// For even length array, the two pointers will meet in the middle and swap all elements.
// For odd length array, the middle element will remain in its position as the two pointers will cross each other after swapping all other elements.
// In both cases, the entire array is reversed correctly.

// TIME COMPLEXITY: O(n) where n is the number of elements in the array.
// SPACE COMPLEXITY: O(1) as we are using only a constant amount of extra space.