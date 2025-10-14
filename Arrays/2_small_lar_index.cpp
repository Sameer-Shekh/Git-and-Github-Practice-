// Find the index of the smallest and largest elements in an array
#include <iostream>
using namespace std;

void findSmallestAndLargest(int arr[], int n) {
    if (n <= 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int smallest = INT8_MAX;
    int largest = INT8_MIN;
    int smallestIndex = -1;
    int largestIndex = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallestIndex = i;
        }
        if (arr[i] > largest) {
            largest = arr[i];
            largestIndex = i;
        }
    }

    cout << "Smallest element: " << smallest << " at index " << smallestIndex << endl;
    cout << "Largest element: " << largest << " at index " << largestIndex << endl;
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSmallestAndLargest(arr, n);

    return 0;
}