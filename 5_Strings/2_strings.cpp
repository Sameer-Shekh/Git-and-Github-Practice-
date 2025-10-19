#include<iostream>
#include<string>

using namespace std;

int main() {
    // STRING IS A C++ CLASS ,WE MAKE OBJECTS FROM IT. IT IS RESIZABLE IN NATURE == > dynamic = runtime resize
    string str = "apna collage";
    cout << str << endl;

    str = "hello";
    cout << str << endl;


    string str1 = "hello";
    string str2 = "khello";
    string str3 = str1 + " " + str2; // concatenation
    cout << str3 << endl;

    // compare two strings
    if (str1 == str2) {
        cout << "strings are equal" << endl;
    } else {
        cout << "strings are not equal" << endl;
    }

    if(str1 < str2) {
        cout << "str1 is less than str2" << endl;
    } else {
        cout << "str1 is not less than str2" << endl;
    }

    // STRING LENGTH
    cout << "length of str1: " << str1.length() << endl;
    cout << "length of str2: " << str2.size() << endl;

    // INPUT STRING
    // string inputStr;
    // cout << "Enter a string: ";
    // cin>> inputStr;
    // cout << "You entered: " << inputStr << endl;
    
    // INPUT STRING WITH SPACE
    string inputstr1;
    cout << "Enter a string: ";
    getline(cin,inputstr1);
    cout << "You entered: " << inputstr1 << endl;

    // TRAVERSING WITH FOR
    cout<<"*********************USING FOR LOOP***********************"<<endl;
    for(int i = 0; i<inputstr1.length();i++) {
        cout<<inputstr1[i] <<" ";
    }
    cout<<endl;

    return 0;
}