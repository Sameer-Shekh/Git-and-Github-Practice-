#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;
void getAllCombination(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &combine, int idx) {
    // base cases
    if (target == 0) {
        if(s.find(combine) == s.end()) {
            ans.push_back(combine);
            s.insert(combine);
        }
        return;
    }
    if (idx == arr.size() || target < 0) {
        return;
    }

    // 1. include current element once
    combine.push_back(arr[idx]);
    getAllCombination(arr, target - arr[idx], ans, combine, idx + 1);
    combine.pop_back();

    // 2. include current element multiple times
    combine.push_back(arr[idx]);
    getAllCombination(arr, target - arr[idx], ans, combine, idx); // stay at same idx
    combine.pop_back();

    // 3. exclude current element
    getAllCombination(arr, target, ans, combine, idx + 1);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> ans;
    vector<int> combine;
    getAllCombination(arr, target, ans, combine, 0);
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 5};
    vector<vector<int>> ans = combinationSum(arr, 8);

    for (const auto& row : ans) {
        for (int c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}
