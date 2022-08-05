#include "bits/stdc++.h"
using namespace std;

//! Brute
// int longestConsecutiveSequence(vector<int> nums){
//     if(nums.empty()) return 0;

//     sort(nums.begin(),nums.end());
//     int ans = 1;
//     int prev = nums[0];
//     int curr = 1;

//     for (int i = 0; i < nums.size(); i++){
//         if(nums[i]==prev+1) curr++;
//         else if(nums[i] != prev) curr = 1;
//         prev = nums[i];
//         ans = max(ans,curr);

//     }
//     return ans;
// }

//! Optimized and amazing

int longestConsecutiveSequence(vector<int> nums){
    set<int> tempSet;
    for(int num:nums) tempSet.insert(num);

    int ans = 0;

    for(int i: nums){
        if(!tempSet.count(i - 1)){
            int currnum = i;
            int streak = 1;

            while(tempSet.count(currnum + 1)){
                currnum++;
                streak++;
            }
            ans = max(ans, streak); 
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {100, 200, 1, 3, 2, 4};
    cout<<longestConsecutiveSequence(nums);
}