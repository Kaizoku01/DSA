//? Day 5

#include <bits/stdc++.h>
using namespace std;

//! Using recursion
// int combinationSum4(vector<int>& nums, int target) {
//     int count = 0;
//     if(target==0) return 1;

//     for (int i = 0; i < nums.size(); i++){
//         if(nums[i] <= target) count += combinationSum4(nums, target - nums[i]);
//     }
//     return count;
// }

//! Using memoization
int combinationSum4(vector<int>& nums, int target, vector<int>& dp) {
    int count = 0;
    if(target==0) return 1;

    if(dp[target] != -1) return dp[target];

    for (int i = 0; i < nums.size(); i++){
        if(nums[i] <= target) count += combinationSum4(nums, target - nums[i], dp);
    }
    return dp[target] = count;
}

int main(){
    int target = 4;
    vector<int> nums = {1,2,3};
    vector<int> dp(target + 1, -1);
    cout<<combinationSum4(nums, target, dp);
}