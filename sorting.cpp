#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void selection_sort( int arr[], int n){
    for(int i=0; i<n-1; i++){

        int min = i;

        for( int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        //swapping
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
    cout << "After selection sort: " << "\n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void bubble_sort_bf(vector<int>& arr){
    int n = arr.size();

    for(int i = n-1; i >=0; i--){
        //cout << i <<endl;
        for(int j=0; j<= i-1; j++){
            //cout << arr[j] << " and " << arr[j+1] << endl;
            if(arr[j] > arr[j+1]){
                //swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }

    cout << "After using bubble sort: \n";
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;
}

void bubble_sort_o(vector<int>& arr){
    int n = arr.size();
    for(int i = n-1; i >=0; i--){
        int didSwap = 0;
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                //swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }

        if(didSwap == 0){
            break;
        }
    }
    cout << "After using bubble sort: \n";
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;

}

vector<int> insertion_sort(vector<int>& arr){
    int n = arr.size();

    for(int i=1; i <n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

    }

    cout << "after insertion sort: " << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return arr;
}

void merge(vector<int>& arr, int start, int mid, int end){
    vector<int> temp;
    int left = start, right = mid +1;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }

    while(left <= mid)
        temp.push_back(arr[left++]);

    while(right <= end)
        temp.push_back(arr[right++]);

    for(int i = start; i <=end; i++)
        arr[i] = temp[i-start];
}

void merge_sort(vector<int>& arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end)/2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);

}

void bubble_sort_recursive(int arr[], int n){
    

    if(n==1){
        return;
    }

    for(int i=0; i <= n-2; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }

    bubble_sort_recursive(arr, n-1);

}

void bubble_sort_recursive_o(int arr[], int n){
    if(n==1){
        return;
    }

    int didSwap=0;

    for(int i=0; i <= n-2; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
            didSwap = 1;
        }
    }

    if(didSwap ==0){
        return;
    }

    bubble_sort_recursive_o(arr,n-1);
}

void insertion_sort_recursive(int arr[], int idx, int n){
    if(idx == n){
        return;
    }

    int j = idx;
    while(j>0 && arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }


    insertion_sort_recursive(arr, idx+1, n);
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];

    int i = low -1;

    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quick_sort(vector<int>& arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr,low,high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}




int main(){
    int arr[] = {1,3,6,2,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> arr1 = {13,46,24,52,20,9};

    cout << "before sort: " << "\n";
    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }

    cout << "\n";

    //selection_sort(arr,n);
    //bubble_sort_bf(arr1);
    //bubble_sort_o(arr1);
    //insertion_sort(arr1);
    //merge_sort(arr1,0, arr1.size()-1);
    //bubble_sort_recursive(arr, n);
    //bubble_sort_recursive_o(arr, n);
    //insertion_sort_recursive(arr,0,n);
    quick_sort(arr1, 0 , arr1.size()-1);

    cout << "after sort: " << "\n";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    return 0;
}