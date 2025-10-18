// WRITE A FUNCTION TO FIND ALL THE UNIQUE ELEMENTS IN AN ARRAY
#include<iostream>
#include<vector>
using namespace std;

void findUniqueElements(vector<int> &nums) {
    bool isUnique = false;

    for(int i = 0; i < nums.size(); i++) {
        isUnique = true;
        for(int j = 0; j < nums.size(); j++) {
            if(i != j && nums[i] == nums[j]) {
                isUnique = false;
                break;
            }
        }
        if(isUnique) {
            cout << nums[i] << " ";
        }
    }
    cout << endl;
}

int main() {

    vector<int> nums = {1,2,2,3,4,4,5,6,7,7};

    findUniqueElements(nums);

    return 0;
}

// ANOTHER APPROACH IS TO USE HASHMAP OR SET TO STORE THE FREQUENCY OF ELEMENTS AND THEN PRINT THE ELEMENTS WHOSE FREQUENCY IS 1
// TIME COMPLEXITY: O(N^2)
// SPACE COMPLEXITY: O(1)
// OPTIMIZED APPROACH
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)

// #include<unordered_map>
// void findUniqueElements(vector<int> &nums) {
//     unordered_map<int, int> freq;
//     for(int i = 0; i < nums.size(); i++) {
//         freq[nums[i]]++;
//     }
//     for(auto it : freq) {
//         if(it.second == 1) {
//             cout << it.first << " ";
//         }
//     }
//     cout << endl;
// }
// #include<unordered_set>
// void findUniqueElements(vector<int> &nums) {
//     unordered_set<int> s;
//     for(int i = 0; i < nums.size(); i++) {
//         if(s.find(nums[i]) == s.end()) {
//             s.insert(nums[i]);
//         } else {
//             s.erase(nums[i]);
//         }
//     }
//     for(auto it : s) {
//         cout << it << " ";
//     }
//     cout << endl;
// }
// ANOTHER APPROACH IS TO SORT THE ARRAY AND THEN PRINT THE ELEMENTS WHOSE NEIGHBOURS ARE NOT SAME
// TIME COMPLEXITY: O(NlogN)
// SPACE COMPLEXITY: O(1)
// #include<algorithm>
// void findUniqueElements(vector<int> &nums) {
//     sort(nums.begin(), nums.end());
//     for(int i = 0; i < nums.size(); i++) {
//         if((i == 0 || nums[i] != nums[i-1]) &&
//            (i == nums.size()-1 || nums[i] != nums[i+1])) {
//             cout << nums[i] << " ";
//         }
//     }
//     cout << endl;
// }
// ANOTHER APPROACH IS TO USE XOR OPERATION TO FIND THE UNIQUE ELEMENTS
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
// THIS APPROACH WORKS ONLY WHEN THERE ARE EXACTLY TWO UNIQUE ELEMENTS IN THE ARRAY
// #include<algorithm>
// void findUniqueElements(vector<int> &nums) {
//     int xorSum = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         xorSum ^= nums[i];
//     }
//     int setBit = xorSum & ~(xorSum - 1);
//     int num1 = 0, num2 = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         if(nums[i] & setBit) {
//             num1 ^= nums[i];
//         } else {
//             num2 ^= nums[i];
//         }
//     }
//     cout << num1 << " " << num2 << endl;
// }
// THIS APPROACH WORKS ONLY WHEN THERE IS EXACTLY ONE UNIQUE ELEMENT IN THE ARRAY
// #include<algorithm>
// void findUniqueElements(vector<int> &nums) {
//     int xorSum = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         xorSum ^= nums[i];
//     }
//     cout << xorSum << endl;
// }