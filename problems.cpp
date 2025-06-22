#include<iostream>
#include<vector>
#include<string>
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

int reverseNumber(){
    int num;
    cout << "enter a positive number to reverse: ";
    cin >> num;
    int reversedNum=0;
    while( num > 0){
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;

    }
    cout << endl<< reversedNum;
    return 0;
}

string reverseString(){
    string str;
    cout << "Enter a string to reverse: " << endl;
    cin >> str;
    string reversedStr;
    for(int i = str.length(); i >= 0; i--){
        reversedStr = reversedStr + str[i];
    }
    cout<< reversedStr;
    return reversedStr;
}

bool checkPalindromeNumber(int num){
    // int num = 0;
    // cout << "Enter a number: "<< endl;
    // cin >> num;
    int originalNum = num;
    int reversedNum = 0;
    while(num > 0){
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    if(reversedNum == originalNum){
        return true;
    }else{
        return false;
    }
    
    return false;
}

bool checkPalindromeStr(string str){
    string originalStr = str;
    string reversedStr = "";
    for(int i = str.length() - 1; i >= 0; i--){
        reversedStr = reversedStr + str[i];
    }
    if(reversedStr == originalStr){
        return true;
    }else{
        return false;
    }
    return false;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,5,5};
    //vector<string> result = findMatchingFruits();
    //cout << singleNumber(nums);
    //reverseNumber();
    //reverseString();
    //cout << checkPalindromeNumber(121);
    //cout << checkPalindromeStr("aabbaa");
    

}