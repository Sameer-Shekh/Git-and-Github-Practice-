#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// BRUTE FORCE APPROACH JUST SORT IT USING ALGORITHM OR USE IN BUILD FUNCTION SORT(ARR.BEGINS(),ARR.END()) == O(NLOG(N))
void sortBruteForce(vector<int> &arr) {
    sort(arr.begin(),arr.end());
}

// OPTIMIZED APPROACH WITH DOUBLE PASS
void sortUsingCount(vector<int> &arr) {
    int countZeros = 0;
    int countOnes = 0;
    int countTwo = 0;

    // CALCULATE THE FREQUENCY OF 0S 1S 2S 
    for(int i =0; i<arr.size();i++) {
        if(arr[i] == 0) countZeros++;
        if(arr[i] == 1) countOnes++;
        if(arr[i] == 2) countTwo++;
    }

    int idx=0;
    // FOR ZERO
    for(int i = 0 ; i < countZeros ; i++) {
        arr[idx++] = 0;
    }
    // FOR ONES
    for(int i = 0 ; i < countZeros ; i++) {
        arr[idx++] = 1;
    }
    // FOR TWO'S
    for(int i = 0 ; i < countZeros ; i++) {
        arr[idx++] = 2;
    }
}

// SORT USING DNF(DUTCH NATIONAL FLAG ALGO)
void sortDNF(vector<int> &arr) {
    int mid = 0;
    int high = arr.size() - 1;
    int low = 0;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        if(arr[mid] == 1) {
            mid++;
        }
        if(arr[mid] == 2) {
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

// PRINT ARRAY
void printArray(vector<int> &arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main() { 

    vector<int> vec = {1,1,0,0,2,2,2,1,0};

    cout<< "SORT USING O(NLOG(N)) WITH INBUILT FUNCTION OR ANY ALGORITHM"<<endl;
    sortBruteForce(vec);
    printArray(vec);

    cout<< "\nSORT USING O(N) WITH 2 PASS"<<endl;
    sortUsingCount(vec);
    printArray(vec);

    cout<< "\nSORT USING O(N) WITH 1 PASS USING DNF ALGORITHM"<<endl;
    sortDNF(vec);
    printArray(vec);

    return 0;
}