#include<iostream>
#include<vector>
using namespace std;


// BASIC BRUTE FORCE APPROACH - O(N^2) TIME COMPLEXITY WITH DIVISION
void findProductExceptSelfUsingDivision(const vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    int totalProduct = 1;
    int zeroCount = 0;

    for (int num : nums) {
        if (num != 0) {
            totalProduct *= num;
        } else {
            zeroCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (zeroCount > 1) {
            result[i] = 0;
        } else if (zeroCount == 1) {
            result[i] = (nums[i] == 0) ? totalProduct : 0;
        } else {
            result[i] = totalProduct / nums[i];
        }
    }

    cout << "Product of Array Except Self (Using Division): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

// SOLVE WITH BRUTE FORCE WITHOUT DIVISION - O(N^2) TIME COMPLEXITY
void findProductExceptSelfWithoutDivisionBruteForce(const vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                result[i] *= nums[j];
            }
        }
    }

    cout << "Product of Array Except Self (Brute Force Without Division): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}


// OPTIMIZED APPROACH WITHOUT DIVISION - O(N) TIME COMPLEXITY
void findProductExceptSelfOptimized(const vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Calculate left products
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }

    // Calculate right products and final result
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    cout << "Product of Array Except Self (Optimized Without Division): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    
    vector<int> nums = {1,2,3,4};
    
    findProductExceptSelfUsingDivision(nums);
    findProductExceptSelfWithoutDivisionBruteForce(nums);
    findProductExceptSelfOptimized(nums);

    return 0;
}