#include <iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result = {};
  for(int i = 0; i < nums.size(); i++){
    for(int j = 0; j < nums.size(); j++){
      if(i != j && (nums[i] + nums[j]) == target){
        result.push_back(i);
      }
    }
  }
  return result;
}

int main(){
  
  // vector<int> twoSumArr = {2,7,11,15};
  // int twoSumTarget = 9;
  // vector<int> twoSumResult = twoSum(twoSumArr, twoSumTarget);
  // cout << "Two sum result: ";
  // for(int i: twoSumResult){
  //   cout << i;
  // }

  

}