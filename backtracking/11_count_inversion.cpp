#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr,int start,int mid,int end) {
    vector<int> temp;
    int i = start,j = mid+1;
    int invCount = 0;

    // MERGING TWO SORTED ARRAYS WHILE COMPARING
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            // arr[i] > arr[j] means all elements from i to mid will be greater than arr[j]
            invCount += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    // IF ANY ELEMENTS LEFT IN LEFT ARRAY
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    // IF ANY ELEMENTS LEFT IN RIGHT ARRAY
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // CHANGE TEMP TO ORIGINAL ARRAY
    for(int idx = 0;idx<temp.size();idx++) {
        arr[idx+start] = temp[idx];
    }
    return invCount;
}

int mergeSort(vector<int> &arr,int start,int end) {
    if(start < end) {
        int mid = start + (end - start)/2;
        // MERGE SORT LEFT HALF
        int leftInvCount = mergeSort(arr,start,mid);
        // MERGE SORT RIGHT HALF
        int rightInvCount = mergeSort(arr,mid+1,end);
        // MERGE BOTH HALVES
        int mergeCount = merge(arr,start,mid,end);
        return leftInvCount + rightInvCount + mergeCount;
    }
    return 0;
}
int main() {
    // vector<int> arr = {6,3,5,2,7};
    vector<int> arr = {1,3,5,10,2,6,8,9};
    int invCount = mergeSort(arr,0,arr.size()-1);
    cout<<"Inversion Count: "<<invCount<<endl;
    return 0;
}