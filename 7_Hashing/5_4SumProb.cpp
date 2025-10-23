#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> result;

    for (int i = 0; i < n - 3; i++) {
        // Skip duplicate i
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicate j
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            long long newTarget = (long long)target - arr[i] - arr[j];
            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = arr[left] + arr[right];
                if (sum == newTarget) {
                    result.push_back({arr[i], arr[j], arr[left], arr[right]});

                    // Skip duplicates for left and right
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < newTarget) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    auto res = fourSum(arr, target);
    for (auto &quad : res) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
}
