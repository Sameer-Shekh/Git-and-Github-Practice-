#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubset)
{
    if (i == arr.size()) {
        allSubset.push_back(ans);
        return;
    }

    // INCLUDE
    ans.push_back(arr[i]);
    printSubset(arr, ans, i + 1, allSubset);

    // BACKTRACK STEP
    ans.pop_back();

    // SKIPPING THE DUPLICATE ELEMENT
    int idx = i + 1;
    while (idx < arr.size() && arr[idx] == arr[i])
        idx++;

    // EXCLUDE
    printSubset(arr, ans, idx, allSubset);
}

int main()
{
    vector<vector<int>> allSubset;
    vector<int> arr = {1,2,2};
    vector<int> ans; // to store result

    printSubset(arr, ans, 0, allSubset);

    // PRINT ALL UNIQUE SUBSETS
    for (const auto &subset : allSubset)
    {
        for (int val : subset)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}