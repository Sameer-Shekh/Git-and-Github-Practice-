// WRITE A FUNCTION TO FIND THE INTERSECTION OF TWO ARRAYS
// SIMPLEST APPROACH IS TO USE TWO LOOPS AND CHECK FOR EVERY ELEMENT OF FIRST ARRAY
// IF IT IS PRESENT IN THE SECOND ARRAY OR NOT
// BUT THIS APPROACH WILL TAKE O(N*M) TIME COMPLEXITY

#include<iostream>
#include<vector>

using namespace std;

void findIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &intersection) {
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;

    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            i++;
        } else if(arr1[i] > arr2[j]) {
            j++;
        } else {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for(int k = 0; k < intersection.size(); k++) {
        cout << intersection[k] << " ";
    }
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> intersection;

    findIntersection(arr1, arr2, intersection);

    return 0;
}