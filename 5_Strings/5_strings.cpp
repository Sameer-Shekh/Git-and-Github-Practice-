// PERMUTATIONS OF A STRING
#include<iostream>
#include<string>
using namespace std;

bool isFreqSame(int freq1[26],int freq2[26]){
    for(int i = 0; i<26 ;i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool isPermutationExist(string str1, string str2) {
    // STEP 1: CALCULATE FREQUENCY OF CHARACTERS IN FIRST STRING
    int frequency[26] = {0};
    for(char ch : str1) {
        frequency[ch - 'a']++;
    }

    // STEP 2: TRAVERSE SECOND STRING IN WINDOWS OF SIZE EQUAL TO FIRST STRING
    int windowSize = str1.length();
    for(int i = 0; i <= str2.length() - windowSize; i++) {
        int windowIdx = 0,idx=i;
        int windFreq[26] = {0};

        while(windowIdx < windowSize && idx <str2.length()) {
            windFreq[str2[idx] - 'a']++;
            windowIdx++;
            idx++;
        }

        if(isFreqSame(frequency,windFreq)) {
            return true;
        }
    }
    return false;
}


int main() {
    string s1 = "mf";
    string s2 = "abccbabba";
    cout << isPermutationExist(s1, s2);
}