#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size();

    while (low <= high){
        int mid = (low+high) >> 1;

        if(arr[mid] == target){
            return mid;
        }
        if(arr[low] <= arr[mid]){   //checking is left part sorted
            if(arr[mid] >= target && arr[low] <= target){
                high = mid - 1;
            }else{
                low = mid  + 1;
            }
        }
        else{   // checking if right part sorted
            if(arr[mid] <= target && arr[high] >= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
    
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<search(arr,3);
}