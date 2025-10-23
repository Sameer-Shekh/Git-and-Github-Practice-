#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findMissingAndRepeatingValues(vector<vector<int>> &grid) {
    int a,b;
    int n = grid.size();
    unordered_set<int> s;
    vector<int> ans;

    int expSum=0,actualSum=0;

    // FOR FINDING REPEATED VALUES
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){

            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            else {
                s.insert(grid[i][j]);
            }
        }
    }

    // FOR FINDING MISSING VALUES
    // MISSING VALUE(B) = EXPSUM + A - ACTUALSUM

    expSum = (n*n) * (n*n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main() {

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,5}};
    vector<int> ans = findMissingAndRepeatingValues(grid);

    cout<<"REPEATED VALUE IS "<<ans[0]<<endl;
    cout<<"MISSING VALUE IS "<<ans[1]<<endl;

    return 0;
}