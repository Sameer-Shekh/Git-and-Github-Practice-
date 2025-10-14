#include<iostream>
using namespace std;

void linearSearch(int arr[], int n, int target, bool &found) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element " << target << " found at index " << i << endl;
            found = true;
            return;
        }
    }
    if (!found) {
        cout << "Element " << target << " not found in the array." << endl;
    }
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    bool found = false;

    linearSearch(arr, n, target, found);
    
    return 0;
}