// WRITE A FUNCTION TO SWAP THE MIN AND MAX ELEMENTS IN AN ARRAY
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapMaxMin(vector<int> &nums) {
    int n = nums.size();
    int maxIndex = 0;
    int minIndex = 0;
    for(int i = 1;i<n;i++) {
        if(nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
        if(nums[i] < nums[minIndex]) {
            minIndex = i;
        }
    }
    swap(nums[maxIndex], nums[minIndex]);
    cout<<"ARRAY AFTER SWAPPING MAX AND MIN ELEMENTS: ";
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
}

int main() {
    vector<int> vec = {1,2,3,4,5,6};
    swapMaxMin(vec);
    return 0;
}