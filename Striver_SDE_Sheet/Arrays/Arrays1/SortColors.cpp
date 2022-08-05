// color represent 0,1,2  (red/white/blue)

#include "bits/stdc++.h"
using namespace std;

//! Frequency of elements approach
// O(n)+O(n) == O(n)

// void sortColors(vector<int>& nums){

//     int red=0,white=0,blue=0;
    
//     for (int i = 0; i < nums.size(); i++){
//         if(nums[i]>2 || nums[i]<0) return;

//         if(nums[i]==0) red++;
//         if(nums[i]==1) white++;
//         if(nums[i]==2) blue++;
//     }
//     nums.clear();
//     for (int i = 0; i < red; i++) nums.push_back(0);
//     for (int i = 0; i < white; i++) nums.push_back(1);
//     for (int i = 0; i < blue; i++) nums.push_back(2);   
// }

//! Dutch National Flag Algo Approach
//O(n)

void sortColors(vector<int>& nums){

    int low,mid,high;
    low = mid = 0;
    high = nums.size()-1;

    while (mid<=high)
    {
        switch(nums[mid]){
            case 0:
                swap(nums[low++],nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid],nums[high--]);
                break;

        }
    }
     
}


int main(){

    vector<int> nums = {0,1,1,2,1,0,0,1};

    cout<<"OG ARRAY"<<endl;
    for(auto& it:nums){
        cout<<it<<" ";
    }
    
    cout<<"Sorted Array"<<endl;
    sortColors(nums);
    for(auto& it:nums){
        cout<<it<<" ";
    }


}