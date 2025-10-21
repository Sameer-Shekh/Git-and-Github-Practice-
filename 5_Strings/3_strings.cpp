#include<iostream>
#include<string>
using namespace std;

bool isAlphanumeric(char ch) {
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string str) {
    int start = 0 ,end = str.length() - 1;
    while(start < end) {
        if(!isAlphanumeric(str[start])) {
            start++;
            continue;
        }
        if(!isAlphanumeric(str[end])) {
            end--;
            continue;   
        }
        if(tolower(str[start]) != tolower(str[end])) {
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main() {

    string str = "MADam, in Eden, I'm Adam"; // IGNORE SPACES AND CASE SENSITIVITY AND COMAS
    bool res =  isPalindrome(str);
    cout << "GIVEN STRING IS VALID PALINDROM OR NOT: " << res << endl;
    return 0;
}