// REMOVE ALL OCCURANCES OF A CHARACTER FROM STRING
#include<iostream>
#include<string>
using namespace std;

void removeAllOccurrences(string &str, string part) {
    while(str.length() > 0  && str.find(part) < str.length()) {
        str.erase(str.find(part), part.length());
    }
    if(str.length() == 0) {
        str = "EMPTY STRING";
    }
}

int main() {
    // string str = "hello world lll";
    string str = "abbabbababbabbbaaaabb";
    string part = "abb";

    removeAllOccurrences(str, part);
    cout << "STRING AFTER REMOVING ALL OCCURENCES OF PART STRING: " << str << endl;

    return 0;
}