#include<iostream>
#include<vector>
using namespace std;


// BRUTE FORCE WOULD BE LINEAR SEACH O(N)

// OPTIMAL USIGN BINARY SEARCH O(LOG(N))
int searchUsingBinarySearch(vector<int>& arr,int target,int n){
    int start = 0,end = n-1;


    while(start <= end) {
        int mid = start + (end-start) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[start] <= arr[mid]) { // LEFT SORTED
            if(arr[start] <= target && target <= arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid+ 1;
            }
        }
        else { // RIGHT SORTED
            if(arr[mid] <= target && target <= arr[end]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 2;
    int n = arr.size();

    int idx = searchUsingBinarySearch(arr, target, n);

    cout << "YOUR TARGET ELEMENT IS PRESENT AT INDEX = "<< idx <<endl;

    return 0;
}