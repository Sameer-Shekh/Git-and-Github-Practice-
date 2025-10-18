// WRITE A FUNCTION TO FIND THE PRODUCT AND SUM OF NUMBERS IN AN ARRAY
#include<iostream>
#include<vector>
using namespace std;

int findSumAndProduct(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    int product = 1;
    for(int i = 0;i<n;i++) {
        sum = sum + nums[i];
        product = product * nums[i];
    }

    cout<<"PRODUCT OF GIVEN ARRAY IS: "<<product<<endl;
    cout<<"SUM OF GIVEN ARRAY IS: "<<sum<<endl;
    return 0;
}

int main() {
    vector<int> vec = {1,2,3,4,5,6};
    findSumAndProduct(vec);
    return 0;
}