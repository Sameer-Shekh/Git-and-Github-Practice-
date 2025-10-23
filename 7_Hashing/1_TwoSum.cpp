#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

void twoSumBruteForce(vector<int> &arr,int target) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] + arr[j] == target) {
                cout << "THE PAIR EXIST IN ARRAY WITH INDEX: " <<i<<","<<j<<endl;
                return;
            }
        }
    }
}

void twoSumBetter(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "THE PAIR EXIST IN ARRAY WITH INDEX USING TWO POINTERS: " <<left<<","<<right<<endl;
            return;
        } 
        else if (sum > target) {
            right--;
        } 
        else {
            left++;
        }
    }
    cout << "No pair found." << endl;
}

void twoSumOptimized(vector<int> &arr, int target) {
    unordered_map<int, int> mp; // stores value -> index

    for (int i = 0; i < arr.size(); i++) {
        int required = target - arr[i];

        // check if the complement exists
        if (mp.find(required) != mp.end()) {
            cout << "PAIR FOUND: " << arr[i] << " + " << required 
                 << " = " << target << endl;
            cout << "INDICES: " << mp[required] << ", " << i << endl;
            return; // or continue if you want multiple pairs
        }

        // store current element with its index
        mp[arr[i]] = i;
    }

    cout << "No pair found." << endl;
}

int main() {

    vector<int> arr = {1,5,2,4,9,8,11,12,10};
    int target = 11;

    twoSumBruteForce(arr,target);
    twoSumBetter(arr,target);
    twoSumOptimized(arr,target);

    return 0;
}