#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// OPTIMAL APPROACH TO FIND NEXT PERMUTATION OF AN ARRAY
void nextPermutationOptimal(vector<int>& arr) {
    int pivot = -1;
    int n = arr.size();
    // 1. Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }
    // 2. If pivot is -1, reverse the array
    if(pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    // 3. Find the successor
    for(int i = n - 1; i > pivot; i--) {
        if(arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    // 4. Reverse the suffix
    // reverse(arr.begin() + pivot + 1, arr.end());
    int left = pivot + 1;
    int right = n - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// BRUTE FORCE APPROACH TO FIND NEXT PERMUTATION OF AN ARRAY
vector<vector<int>> allPermutations;

void generatePermutations(vector<int>& arr, int idx) {
    if (idx == arr.size()) {
        allPermutations.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        generatePermutations(arr, idx + 1);
        swap(arr[idx], arr[i]); // backtrack
    }
}

void nextPermutationBruteForce(vector<int>& arr) {
    // 1. Generate all permutations
    generatePermutations(arr, 0);

    // 2. Sort lexicographically
    sort(allPermutations.begin(), allPermutations.end());

    // 3. Find current permutation and its successor
    for (int i = 0; i < allPermutations.size(); i++) {
        if (allPermutations[i] == arr) {
            int nextIdx = (i + 1) % allPermutations.size();
            arr = allPermutations[nextIdx]; // store next permutation in place
            return;
        }
    }
}

int main() {
    vector<int> arr = {1, 3, 2};

    nextPermutationBruteForce(arr);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    
    nextPermutationOptimal(arr); 
    for (int x : arr)
        cout << x << " ";
}
