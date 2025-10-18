#include <iostream>
#include <vector>
using namespace std;

// PAIR SUM BRUTE FORCE TC : O(N^2)
vector<int> pairSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        }
    }
    return ans;
}

// OPTIMIZED APPROACH TC : O(N)
vector<int> pairSumUsingTwoPointers(vector<int> &nums, int target)
{
    vector<int> ans;
    int i = 0;
    int j = nums.size();
    while(i < j) {
        int pairSum = nums[i] + nums[j];
        if(pairSum > target) {
            j--;
        }
        else if(pairSum < target) {
            i++;
        }
        else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = pairSum(vec, target);
    cout << "THE PAIR EXISTS IN ARRAY WHOSE SUM IS EQUAL TO TARGET (9) = " << ans[0] << "," << ans[1] << endl;

    vector<int> ans1 = pairSumUsingTwoPointers(vec,target);
    cout << "THE PAIR EXISTS IN ARRAY WHOSE SUM IS EQUAL TO TARGET (9) USING TWO POINTERS = " << ans1[0] << "," << ans1[1] << endl;

    return 0;
}