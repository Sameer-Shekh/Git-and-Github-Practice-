#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int> arr, int target, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] <= target)
        {
            return binSearch(arr, target, mid + 1, end);
        }
        else
        {
            return binSearch(arr, target, start, mid - 1);
        }
    }

    return -1;
}

int search(vector<int> arr, int target)
{
    if (binSearch(arr, target, 0, arr.size()) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << search(arr, 100);
    return 0;
}