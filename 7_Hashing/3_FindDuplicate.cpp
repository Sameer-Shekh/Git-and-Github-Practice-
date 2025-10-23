#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDuplicate(vector<int> &nums) { // TC O(N)  SC o(N)
    unordered_set<int> s;
    for(int val:nums) {
        if(s.find(val) != s.end()) {
            return val;
        }
        s.insert(val);
    }

    return -1;
}
int findDuplicateUsingSlowFastPointer(vector<int> &nums) {// TC O(N) SC O(1)
    int slow = nums[0],fast=nums[0];
    do{
        slow = nums[slow]; // +1
        fast = nums[nums[fast]]; // +2
    }
    while(slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow]; // +1
        fast = nums[fast]; // +2
    }
    return slow;
}
int main() {

    vector<int> nums = {3,1,3,4,2};
    cout << findDuplicate(nums)<<endl;
    cout << findDuplicateUsingSlowFastPointer(nums)<<endl;

    return 0;
}