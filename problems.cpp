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

void shiftZeroToEnd(vector<int>& arr){
    int n = arr.size();
    int index = 0;  // Position to place the next non-zero element

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with 0
    while (index < n) {
        arr[index++] = 0;
    }
    
    

}

vector<int> findDistantKIndices(vector<int>& nums, int key, int k){
    vector<int> result = {};
    for( int i = 0; i < nums.size(); i++){
        for( int j = 0; j < nums.size(); j++){
            if(nums[j] == key && abs(i-j) <= k){
                cout << i;
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};
    for(int i = 0; i < nums.size() ; i++ ){
        for(int j = 0; j < nums.size(); j++){
            if(i != j && (nums[i] + nums[j]) == target){
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}

bool isPalindrome(int x) {
    
    int originalNum = x;
    int reversedNum = 0;
    while(x > 0){
        int digit = x % 10;
        reversedNum = reversedNum * 10 + digit;
        x /= 10;
    }
    if(reversedNum == originalNum){
        cout << "true";
        return true;
    }else{
        cout << "false";
        return false;
    }
    cout<< "false";
    return false;
}

int main(){
    //vector<int> nums = {3,4,9,1,3,9,5};
    //vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {3,2,4};
    
    //vector<string> result = findMatchingFruits();
    
    //cout << singleNumber(nums);
    
    //reverseNumber();
    
    //reverseString();
    
    //cout << checkPalindromeNumber(121);
    
    //cout << checkPalindromeStr("aabbaa");
    
    //shiftZeroToEnd(nums);
    // for(int i: nums){
    //     cout<< i;
    // }

    //vector<int> indices = findDistantKIndices(nums, 2, 2);
    
    // vector<int> sums = twoSum(nums, 6);
    // for(int i: sums){
    //     cout<< i << " ";
    // }
    
    //bool checkPalindrome = isPalindrome(10);

}