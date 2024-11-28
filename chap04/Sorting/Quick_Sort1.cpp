// https://www.geeksforgeeks.org/quick-sort-algorithm/

#include <bits/stdc++.h>

using namespace std;

int partition(int arr[],int low,int high) {
  //choose the pivot
  int pivot=arr[high];
  
  //the right position of pivot found so far
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++) {
    if(arr[j]<pivot) {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

void quickSort(int arr[],int low,int high) {
  if(low<high) {
    // pi is the partition return index of pivot
    int pi=partition(arr,low,high);
    
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
 
int main() {
  int arr[]={10,7,8,9,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  
   quickSort(arr,0,n-1);

  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++) {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}

// run result 
// Sorted Array
// 1 5 7 8 9 10
