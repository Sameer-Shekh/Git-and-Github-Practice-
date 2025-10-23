#include <iostream>
#include <vector>
#include <set>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSumBrute(vector<int>& arr, int target) {
    int n = arr.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}


vector<vector<int>> threeSumBetter(vector<int>& arr, int target) {
    int n = arr.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++) {
            int third = target - (arr[i] + arr[j]);
            if (seen.count(third)) {
                vector<int> triplet = {arr[i], arr[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            seen.insert(arr[j]);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

vector<vector<int>> threeSumOptimized(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> result;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});

                // skip duplicates
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    auto result = threeSumBrute(arr, target);
    for (auto triplet : result) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }

    auto res = threeSumBetter(arr, target);
    for (auto triplet : res) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }

    auto ans = threeSumOptimized(arr, target);
    for (auto triplet : ans) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }

}
