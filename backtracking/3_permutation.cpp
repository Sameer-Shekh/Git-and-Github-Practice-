#include<iostream>
#include<vector>
using namespace std;

void getPermutation(vector<int> &arr, int i, vector<vector<int>> &ans){
    // BASE CASE
    if(i == arr.size()){
        ans.push_back(arr);
        return;
    }
    // RECURSIVE CASE
    for(int j = i; j < arr.size(); j++){
        swap(arr[i], arr[j]);
        getPermutation(arr, i + 1, ans);
        // BACKTRACK STEP
        swap(arr[i], arr[j]);
    }
}

vector<vector<int>> permute(vector<int> &arr, int i){
    vector<vector<int>> ans;
    getPermutation(arr, i, ans);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permute(arr, 0);
    for(const auto &v : ans){
        for(int val : v){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}


// IF WE ARE GONNA USE EXTRA SPACE TO STORE THE ELEMENTS *************************************************

// void getPermutation(vector<int> &arr, vector<int> &temp, vector<bool> &used, vector<vector<int>> &ans) {
//     // BASE CASE
//     if (temp.size() == arr.size()) {
//         ans.push_back(temp);
//         return;
//     }

//     // RECURSIVE CASE
//     for (int i = 0; i < arr.size(); ++i) {
//         if (!used[i]) {
//             used[i] = true;
//             temp.push_back(arr[i]);
//             getPermutation(arr, temp, used, ans);

//             // BACKTRACK STEP
//             temp.pop_back();
//             used[i] = false;
//         }
//     }
// }

// vector<vector<int>> permute(vector<int> &arr) {
//     vector<vector<int>> ans;
//     vector<int> temp;
//     vector<bool> used(arr.size(), false);
//     getPermutation(arr, temp, used, ans);
//     return ans;
// }

// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<vector<int>> ans = permute(arr);
//     for (const auto &v : ans) {
//         for (int val : v) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }