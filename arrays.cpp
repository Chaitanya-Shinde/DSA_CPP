#include<iostream>
#include <climits>
#include <vector>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int findSmallestElement(int arr[], int size){
  int smallest = INT_MAX;
  for(int i = 0; i < size; i++){
    if(arr[i] < smallest){
      smallest = arr[i];
    }
  }
  cout<< smallest <<endl;
  return smallest;
}

int findLargestElement(int arr[], int size){
  int largest = INT_MIN;
  for(int i = 0; i < size ; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  cout << largest<< endl;
  return largest;
}

int linearSearch(int arr[], int size, int element){
  int pos; 
  for(int i = 0; i < size; i++){
    if(arr[i] == element){
      cout<< "Element found at index: " << i << endl;
      pos = i;
      return pos;
    }
  }
  pos = -1;
  return pos;
}

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void reverseArray(int arr[], int size){
  int start = 0;
  int end = size - 1;

  while(start < end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
  for(int i = 0; i<size; i++){
    cout<< arr[i];
  }
}

void reverseElementsOfArray(vector<int>& arr, int start, int end){
  while(start<=end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void sumOfNumsInArray(int arr[], int size){
  int sum = 0;
  for(int i = 0; i < size; i++){
    sum = sum + arr[i];
  }
  cout << sum;
}

void productOfNumsInArray(int arr[], int size){
  int sum = 1;
  for(int i = 0; i < size; i++){
    sum = sum * arr[i];
  }
  cout << sum;
}

void swapMinMax(int arr[], int size){
  int smallest = findSmallestElement(arr, size);
  int largest = findLargestElement(arr,size);
  int temp = smallest;
  smallest = largest;
  largest = temp;
  cout << "Swapped!" << endl;
  cout << smallest << endl;
  cout << largest << endl;
  

}

void findUniqueElements(int arr[], int size){
  for(int i = 0; i < size; i++){
    bool isUnique = true;
    for(int j = 0; j < size; j++){
      if(i != j && arr[i] == arr[j]){
        isUnique = false;
        break;
      }
    }
    if(isUnique){
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

int findLargestElementOptimal(int arr[], int size){
  int largest = arr[0];
  for(int i=1; i<size; i++){
    if(arr[i] > arr[0]){
      largest = arr[i];
    }
  }
  cout << "Largest num is: " << largest << endl;
  return largest;
}

int secondLargest(vector<int> nums, int size){
  int largest = nums[0];
  int sLargest = INT_MIN;

  for(int i = 1; i<size; i++){
    if(nums[i] > largest){
      sLargest = largest;
      largest = nums[i];
    }
    else if(nums[i] < largest && nums[i] > sLargest){
      sLargest = nums[i];
    }
  }
  cout << "second largest num is: " << sLargest << endl;
  return sLargest;
}

int secondSmallest(vector<int> nums, int size){
  int smallest = nums[0];
  int sSmallest = INT_MAX;

  for(int i=1; i<size; i++){
    if(nums[i] < smallest){
      sSmallest = smallest;
      smallest = nums[i];
    }
    else if(nums[i] != smallest && nums[i] < sSmallest){
      sSmallest = nums[i];
    }
  }
  cout<< "second smallest num is: " << sSmallest << endl;
  return sSmallest;
}

vector<int> getSecondOrderElements(vector<int> nums, int size){
  int sLargest = secondLargest(nums,size);
  int sSmallest = secondSmallest(nums,size);

  return {sSmallest, sLargest};
}

bool checkArrSortedAndRotated(vector<int> nums, int nums_size){
  int count=0;
  for(int i=0;i<nums_size;i++){
    if(nums[(i+1)%nums_size] < nums[i]){
      count++;
    }
    if(count>1){
      return false;
    }
  }
  return true;
}

int removeDuplicatedFromSortedArr(int arr[], int size){
  int n = size;
  int i=0;
  for(int j=1; j<n;j++){
    if(arr[i] != arr[j]){
      arr[i+1] = arr[j];
      i++;
    }
  }
  cout << "Number of unique elements: " << i+1<<endl;
  return i+1;
}

vector<int> leftRotateByOne(vector<int> nums){
  int temp = nums[0];

  for(int i=1; i<nums.size(); i++){
    nums[i-1] = nums[i];
  }
  nums[nums.size()-1] = temp;
  return nums;
}

vector<int> leftRotateArrByKElements_BF(vector<int> nums, int k){
  int n = static_cast<int>(nums.size());
  if(n == 0){
    return nums;
  }
  k = k % n;
  if(k < 0){
    k += n;
  }

  vector<int> tempArr;
  for(int i = 0; i<k; i++){
    tempArr.push_back(nums[i]); //O(k)
  }

  for(int i=k; i<n; i++){
    nums[i-k] = nums[i]; //O(n-k)
  }

  for(int i=n-k; i<n; i++){
    nums[i] = tempArr[i-(n-k)]; //O(k)
  }
  //TC = O(n+k)
  //SC = O(k)
  return nums;
}

vector<int> leftRotateArrByKElements_OP(vector<int> nums, int k){
  int n = nums.size();
  if(n == 0){
    return nums;
  }
  k= k%n;
  if(k < 0){
    k += n;
  }

  reverseElementsOfArray(nums, 0, k-1);
  reverseElementsOfArray(nums, k,n-1);
  reverseElementsOfArray(nums, 0, n-1);


  return nums;
}

vector<int> rightRotateArrByKElements_OP(vector<int> nums, int k){
  int n = nums.size();
  if(n==0){
    return nums;
  }

  k = k%n;

  reverseElementsOfArray(nums, 0, (n-k)-1);
  reverseElementsOfArray(nums, n-k, n-1);
  reverseElementsOfArray(nums, 0 , n-1);

  return nums;
}



int main(){
  int arr[] = {1,2,3,4,5,6,6,7,8,8};
  int size = sizeof(arr) / sizeof(arr[0]);
  vector<int> nums = {3,4,9,1,3,9,5};
  vector<int> nums2 = {1,2,3,4,5,6,7,8};
  //vector<int> nums = {3,4,5,1,2};
  int nums_size = nums.size();
  
  //smallAndlarge(arr, size);
  //cout << linearSearch(arr, size, 8) << endl;
  //reverseArray(arr, size);
  //sumOfNumsInArray(arr,size);
  //productOfNumsInArray(arr, size);
  //swapMinMax(arr, size);
  //findUniqueElements(arr, size);
  
  //findLargestElementOptimal(arr,size);
  //getSecondOrderElements(nums, nums_size);
  
  //bool isSortedAndRotated = checkArrSortedAndRotated(nums, nums_size);
  //cout << (isSortedAndRotated ? "true" : "false") << endl;

  //removeDuplicatedFromSortedArr(arr,size);

  // vector<int> leftRotatedArr = leftRotateByOne(nums);
  // for(int num: leftRotatedArr){
  //   cout<<num << ",";
  // }
  // cout <<endl;

  //vector<int> leftRotatedArrByK = leftRotateArrByKElements_BF(nums,3);
  //vector<int> leftRotatedArrByK = leftRotateArrByKElements_OP(nums,3);
  vector<int> rightRotatedArrByK = rightRotateArrByKElements_OP(nums2,3);
  for(int num: rightRotatedArrByK){
    cout<<num << ",";
  }
  cout <<endl;
  return 0;
}
