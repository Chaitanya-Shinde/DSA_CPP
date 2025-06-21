#include<iostream>
using namespace std;

void smallAndlarge(int arr[], int size){
  int smallest = INT_MAX;
  for(int i = 0; i < size; i++){
    if(arr[i] < smallest){
      smallest = arr[i];
    }
  }
  cout<< smallest <<endl;

  int largest = INT_MIN;
  for(int i = 0; i < size ; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  cout << largest<< endl;
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

int main(){
  int arr[] = {1,2,3,4,5,5,6};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  //smallAndlarge(arr, size);
  //cout << linearSearch(arr, size, 8) << endl;
  //reverseArray(arr, size);
  //sumOfNumsInArray(arr,size);
  //productOfNumsInArray(arr, size);
  return 0;
}
