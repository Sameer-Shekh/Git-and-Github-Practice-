#include<iostream>
#include<vector>
using namespace std;

// RECURSIVE APPROACH
void binarySearchRecursive(const vector<int>& arr, int target, int left, int right)
{
    if (left > right) {
        cout << "Element not found in the array." << endl;
        return;
    }

    int mid = left + (right - left) / 2; // OPTIMIZED MID CALCULATION WE USE left + (right - left) / 2 TO AVOID POTENTIAL OVERFLOW

    if (arr[mid] == target) {
        cout << "Element found at index: " << mid << endl;
        return;
    }
    else if (arr[mid] < target) {
        binarySearchRecursive(arr, target, mid + 1, right);
    }
    else {
        binarySearchRecursive(arr, target, left, mid - 1);
    }
}

// ITERATIVE APPROACH WITHOUT OPTIMIZATION
void binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // HERE
        int mid = (left + right ) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Element not found in the array." << endl;
}

int main() {

    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    binarySearchIterative(arr,target);
    binarySearchRecursive(arr,target,0,arr.size()-1);
    return 0;
}