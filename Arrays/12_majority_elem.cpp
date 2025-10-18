#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// BRUTE FORCE APPROACH TC : O(N^2) SC : O(1)
void findMajorityElement(vector<int> &nums, int n) {
    for(int val: nums) {
        int freq = 0;
        for(int el: nums) {
            if(el == val) {
                freq++;
            }
        }
        if(freq > n/2) {
            cout << "Majority Element: " << val << endl;
            return;
        }
    }
    cout << "No Majority Element" << endl;
}

// BETTER APPROACH USING SORTING TC : O(NlogN) SC : O(1)
void findMajorityElementSorting(vector<int> &nums, int n) {
    // SORT ARRAY
    sort(nums.begin(), nums.end());

    // FREQ COUNT
    int freq = 1, ans = nums[0];
    for(int i=1; i<n; i++) {
        if(nums[i] == nums[i-1]) {
            freq++;
        } else {
            freq = 1;
        }
        if(freq > n/2) {
            cout << "Majority Element: " << nums[i] << endl;
            return;
        }
    }
    
}

// OPTIMAL APPROACH USING MOORE'S VOTING ALGORITHM TC : O(N) SC : O(1)
void findMajorityElementMoore(vector<int> &nums, int n) {
    int freq = 0;
    int ans = 0;

    for(int i=0;i<n;i++) {
        if(freq == 0) {
            ans = nums[i];
        }
        if(nums[i] == ans) {
            freq++;
        } else {
            freq--;
        }   
    }

    cout<< "Potential Majority Element UsING Moore's Voting Algorithm: " << ans << endl;

    // VERIFYING THE MAJORITY ELEMENT LIKE IF ANS DOESNOT EXIST AS MAJORITY ELEMENT
    int count = 0;
    for(int i=0;i<n;i++) {
        if(nums[i] == ans) {
            count++;
        }
    }
    if(count > n/2) {
        cout << "Majority Element Confirmed: " << ans << endl;
    } else {
        cout << "No Majority Element" << endl;
    }
}
int main() {

    vector<int> vec = {2,2,2,1};
    int n = vec.size();

    findMajorityElement(vec, n);
    findMajorityElementSorting(vec, n);
    findMajorityElementMoore(vec, n);
    return 0;
}