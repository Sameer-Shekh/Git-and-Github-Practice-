#include <bits/stdc++.h>
using namespace std;

// 1️⃣ BRUTE FORCE — O(n^2)
pair<int, int> subarraySumBrute(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == target) {
                count++;
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return {count, maxLen};
}

// 2️⃣ BETTER APPROACH — O(n log n) using Prefix Sum + Hash Map
pair<int, int> subarraySumBetter(vector<int>& arr, int target) {
    unordered_map<int, int> prefixIndex; // first occurrence index
    unordered_map<int, int> prefixCount; // count of each prefix sum

    int prefixSum = 0;
    int maxLen = 0;
    int count = 0;

    prefixCount[0] = 1; // base case for prefixSum == target

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Count logic
        int remove = prefixSum - target;
        if (prefixCount.find(remove) != prefixCount.end())
            count += prefixCount[remove];

        // Longest length logic
        if (prefixSum == target)
            maxLen = max(maxLen, i + 1);

        if (prefixIndex.find(prefixSum - target) != prefixIndex.end()) {
            int len = i - prefixIndex[prefixSum - target];
            maxLen = max(maxLen, len);
        }

        if (prefixIndex.find(prefixSum) == prefixIndex.end())
            prefixIndex[prefixSum] = i;

        prefixCount[prefixSum]++;
    }

    return {count, maxLen};
}

// 3️⃣ OPTIMIZED — O(n) using Sliding Window (works only for non-negative arrays)
int subarraySumOptimized(vector<int>& arr, int target) {
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;
    int n = arr.size();

    while (right < n) {
        sum += arr[right];

        while (sum > target && left <= right)
            sum -= arr[left++];

        if (sum == target)
            maxLen = max(maxLen, right - left + 1);

        right++;
    }

    return maxLen;
}

// 4️⃣ PURE COUNT VERSION — O(n) using Prefix Sum + Hash Map
int countSubarraysWithSumK(vector<int>& arr, int target) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int num : arr) {
        prefixSum += num;
        int remove = prefixSum - target;

        if (prefixCount.find(remove) != prefixCount.end())
            count += prefixCount[remove];

        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int target = 6;

    // Brute Force
    auto brute = subarraySumBrute(arr, target);
    cout << "Brute Force -> Count: " << brute.first
         << ", Longest Length: " << brute.second << endl;

    // Better (Prefix + Map)
    auto better = subarraySumBetter(arr, target);
    cout << "Better (Prefix + Map) -> Count: " << better.first
         << ", Longest Length: " << better.second << endl;

    // Optimized Sliding Window
    cout << "Optimized (Sliding Window) -> Longest Length: "
         << subarraySumOptimized(arr, target) << endl;

    // Pure Count Only (Clean O(n))
    cout << "Count using Prefix-Sum (Optimized Count): "
         << countSubarraysWithSumK(arr, target) << endl;

    return 0;
}
