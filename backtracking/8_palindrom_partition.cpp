#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(const string &s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllPartitions(string s, vector<string> &partitions, vector<vector<string>> &ans) {
    // base case
    if (s.empty()) {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i + 1); // prefix

        if (isPalindrome(part)) {
            partitions.push_back(part);

            // work on the remainder of the string
            string remaining = s.substr(i + 1);
            getAllPartitions(remaining, partitions, ans);

            partitions.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;
    getAllPartitions(s, partitions, ans);
    return ans;
}

int main() {
    string s = "aabaa";
    vector<vector<string>> result = partition(s);

    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << "[" << str << "] ";
        }
        cout << endl;
    }

    return 0;
}
