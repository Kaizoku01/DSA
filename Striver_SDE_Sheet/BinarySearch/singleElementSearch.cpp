#include <bits/stdc++.h>
using namespace std;

//! Xor approach
//! TC = O(N)   SC = O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int elem = 0;
    for(int i=0;i<n;i++){
        elem = elem ^ nums[i];
    }
    return elem;
}

//! Using Binary Search
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 2;
    while (low<=high){
        int mid = (low + high) / 2;
        if(mid % 2 ==0){
            if(nums[mid] != nums[mid+1]){     //? checking for right half
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(nums[mid] == nums[mid + 1]){   //? checking for right half
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    return nums[low];
}

//! using binary search but concise code using xor 

    int singleNonDuplicate(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n - 2;
    while (low<=high){
        int mid = (low + high) >> 1 ;    //? if its odd then xoring it makes it even and vice versa
        if(nums[mid == nums[mid^1]]){  //? checking for left half
            low = mid + 1;
        }else{
            high = mid + 1;
        }
    }
    return nums[low];
}




int main(){
    return 0;
}