#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec; // 0
    vector<int> vec1 = {1, 2, 3};
    cout << vec1[0] << endl;
    cout << vec1[1] << endl;
    cout << vec1[2] << endl;

    vector<int> vec2(5, 1);
    for (int val : vec2)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> arr;
    cout<<"VECTORS ARE DYNAMIC IN NATURE WHEN WE PUSH BACK AT RUNTIME IT DOUBLES ITS SIZE THEREFORE THE SIZE AND CAPACITY COULD BE DIFFERENT"<<endl;
    cout << "SIZE OF ARR VECTOR: " << arr.size() << endl;
    arr.push_back(10);
    cout << "SIZE OF ARR VECTOR: " << arr.size() << endl;
    arr.push_back(20);
    arr.push_back(30);
    cout<<"SIZE OF ARR VECTOR: "<<arr.size()<<endl;
    cout<<"CAPACITY OF ARR VECTOR: "<<arr.capacity()<<endl;
    cout<<"BEFORE POP BACK"<<endl;
    for (int val : arr)
    {
        cout << val << " ";
    }
    arr.pop_back();
    cout<<"\nAFTER POP BACK"<<endl;
    for (int val : arr)
    {
        cout << val << " ";
    }

    cout<<"\nFRONT ELEMENT: "<<arr.front()<<endl;
    cout<<"BACK ELEMENT: "<<arr.back()<<endl;
    return 0;
}