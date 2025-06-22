#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<char> vec = {'a','b','c','d','e'};
    cout << vec.size()<< endl;
    for ( char val : vec){
        cout << val;
    }

    vec.push_back('f');
    cout << endl<<  vec.size()<< endl;
    for ( char val : vec){
        cout << val;
    }

    vec.pop_back();
    cout << endl<<  vec.size()<< endl;
    for ( char val : vec){
        cout << val;
    }

    cout << endl<< vec.front() <<endl;
    cout << vec.back() <<endl;
    cout << vec.at(3);
    return 0;
}