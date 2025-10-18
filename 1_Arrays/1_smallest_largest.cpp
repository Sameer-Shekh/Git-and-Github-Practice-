#include <iostream>
using namespace std;

void findSmallestAndLargest(int arr[],int n) {
    if (n <= 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int smallest = INT8_MAX;
    int largest = INT8_MIN;

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;
}

int main() {

    int arr[] = {3, 5, 7, 2, 8, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSmallestAndLargest(arr, n);

    return 0;
}