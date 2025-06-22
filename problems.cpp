#include<iostream>
#include<vector>
using namespace std;

vector<string> findMatchingFruits(){
    vector<string> fruits = {"apple","banana","avacado","alphonso mango","watermelon"};
    string fruit; 
    vector<string> matchedFruits;
    cout << "Enter a fruit: ";
    cin >> fruit;

    for(const string& val : fruits){
        if(!fruit.empty() && !val.empty() && val.at(0) == fruit.at(0)){
            cout << val << endl;
            matchedFruits.push_back(val);
        }
    }
    return matchedFruits;
}

int singleNumber(vector<int>& arr){
    int ans =0;
    for(int val : arr ){
        ans ^= val;
        cout<< ans;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,5,5};
    //vector<string> result = findMatchingFruits();
    cout << singleNumber(nums);
}