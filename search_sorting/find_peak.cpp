#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void findPeak(int arr[], int low, int high, int n) 
{
    int mid = low + (high - low)/2 ;/* (low + high)/2 */
  
    if((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == n-1 || arr[mid+1] <= arr[mid])) 
            {
                cout<<"returned "<<arr[mid]<<endl;
        cout<< arr[mid]<<endl;
            }
  
    // If middle element is not peak and its left neighbour is greater  
    // than it, then left half must have a peak element 
    if (mid > 0 && arr[mid-1] > arr[mid]) 
    {
        cout<<"Processing done for left side i.e "<< arr[mid]<< " is less than "<<arr[mid-1]<<endl;
         findPeak(arr, low, (mid -1), n);
    }
  
    // If middle element is not peak and its right neighbour is greater 
    // than it, then right half must have a peak element 
    if (mid < n-1 && arr[mid+1] > arr[mid]) 
    {
        cout<<"else looop"<<endl;
         findPeak(arr, (mid + 1), high, n);
    }
} 
int main()
{
    int arr[] = {10, 20, 15, 2, 90, 86, 67};
    findPeak(arr,0,6,7);
    return 0;
}