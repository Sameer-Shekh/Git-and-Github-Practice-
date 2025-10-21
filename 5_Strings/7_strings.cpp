// STRING COMPRESSION
#include<iostream>
#include<vector>
using namespace std;

void compressArray(vector<char> &chars) {
    int n = chars.size();
    int idx = 0;

    for(int i = 0; i<n;i++) {
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch) {
            count++;
            i++;
        }

        if(count == 1) {
            chars[idx] = ch;
            idx++;
        }
        else {
            chars[idx] = ch;
            idx++;
            string str = to_string(count);
            for(char dig : str) {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);

    for(char c : chars) {
        cout << c << " ";
    }
}

int main() {

    vector<char> ch = {'a','a','b','b','c','c','c'};

    compressArray(ch);

    return 0;
}