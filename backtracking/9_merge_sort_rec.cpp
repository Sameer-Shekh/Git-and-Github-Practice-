#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int start,int mid,int end) {
    vector<int> temp;
    int i = start,j = mid+1;

    // MERGING TWO SORTED ARRAYS WHILE COMPARING
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
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

}

void mergeSort(vector<int> &arr,int start,int end) {
    if(start < end) {
        int mid = start + (end - start)/2;
        // MERGE SORT LEFT HALF
        mergeSort(arr,start,mid);
        // MERGE SORT RIGHT HALF
        mergeSort(arr,mid+1,end);
        // MERGE BOTH HALVES
        merge(arr,start,mid,end);
    }
}

int main () {

    vector<int> arr = {12,32,55,1,66,21};
    int n = arr.size()-1;
    mergeSort(arr,0,n);
    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}