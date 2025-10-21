// REVERSE WORDS IN STRING
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reverseWordsInString(string s) {
    int n = s.length() - 1;
    string ans = "";

    reverse(s.begin(),s.end());

    for(int i=0 ; i<n ; i++) {
        string word = "";
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(),word.end());
        if(word.length() > 0) {
            ans += " " + word;
        }
    }

    return ans.substr(1);
}

int main() {

    string str = "    this     is my pen      ";
    string ans = reverseWordsInString(str);
    cout<< ans;
    return 0;
}