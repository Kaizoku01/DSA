#include "bits/stdc++.h"
using namespace std;

int target,target_2;


void nextPermutation(vector<int> &nums){

    for (target = nums.size()-2; target >= 0; target--)
    {
        if(nums[target]<nums[target+1]){
            break;
        }
    }
    if (target<0){
        reverse(nums.begin(),nums.end());
    }
    else{
        for (target_2 = nums.size()-1; target_2 > target; target_2--){
            if (nums[target_2]>nums[target]){
                break;
            }
        }
        swap(nums[target],nums[target_2]);
        reverse(nums.begin()+(target+1),nums.end());       
    }

}
    

int main(){
    vector<int> num={3,2,1};

    nextPermutation(num);  
}   
